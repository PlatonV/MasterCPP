#include "master.h"

/*
Returns true if t1 and t2 are logicaly equal.
*/
bool tutorial_equals(Tutorial t1, Tutorial t2)
{
	return t1.GetTitle() == t2.GetTitle() && t1.GetPresenter() == t2.GetPresenter();
}

/*
Constructor for Repository. Makes space for 50 elements in data.
*/
Repository::Repository()
{
}

/*
Loads tutorials from a file.
*/
void Repository::LoadFromFile(string filename)
{
	ifstream f;
	f.open(filename);

	while (!f.eof())
	{
		Tutorial * t = new Tutorial();
		f >> *t;
		m_data.push_back(t);
	}
}

/*
Adds tutorial to the repository.
*/
void Repository::AddTutorial(Tutorial *_t)
{
	if (!Validator::ValidateTutorial(*_t, m_data))
		throw TutorialAlreadyExistsException();
	m_data.push_back(_t);
}

/*
Removes a tutorial from the repository based on title and presenter.
*/
void Repository::RemoveTutorial(std::string title, std::string presenter)
{
	for (vector<Tutorial*>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		if ((*it._Ptr)->GetTitle() == title && ((*it._Ptr)->GetPresenter() == presenter))
		{
			m_data.erase(it);
			return;
		}
	throw TutorialNotFoundException();
}

/*
Increases likes for a tutorial.
*/
void Repository::IncreaseLikes(std::string title, std::string presenter)
{
	for (Tutorial *t : m_data)
	{
		if (t->GetTitle() == title && t->GetPresenter() == presenter)
		{
			t->Like();
			return;
		}
	}
	throw TutorialNotFoundException();
}

/*
Updates a tutorial by title and name, asks for the tutorial to replace with.
*/
void Repository::UpdateTutorial(std::string title, std::string presenter, Tutorial *tutorial)
{
	for (vector<Tutorial*>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		if ((*it._Ptr)->GetTitle() == title && ((*it._Ptr)->GetPresenter() == presenter))
		{
			m_data.erase(it);
			m_data.push_back(tutorial);
			return;
		}
	throw TutorialNotFoundException();
}

/*
Returns pointer to the data in the repository.
*/
vector<Tutorial*> Repository::GetData()
{
	return m_data;
}

Repository::~Repository()
{
}

void Repository::Test()
{
	Repository *repo = new Repository();

	repo->AddTutorial(new Tutorial("test", "test", 10, 10, 0, "google.com"));
	assert(repo->GetData()[0]->GetTitle() == "test");
	assert(repo->GetData()[0]->GetPresenter() == "test");
	assert(repo->GetData()[0]->GetDuration()->GetMinutes() == 10);
	repo->IncreaseLikes("test", "test");
	assert(repo->GetData()[0]->GetLikes() == 1);
	try
	{
		repo->AddTutorial(new Tutorial("test", "test", 10, 10, 0, "google.com"));
	}
	catch (exception& e)
	{ }
	delete repo;
}