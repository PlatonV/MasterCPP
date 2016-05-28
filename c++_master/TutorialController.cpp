#include "master.h"

TutorialController::TutorialController(Repository *_repo)
{
	m_repo = _repo;
	m_watchlist = new Repository();
}

vector<Tutorial*> TutorialController::GetAll()
{
	return m_repo->GetData();
}

vector<Tutorial*> TutorialController::GetWatchlist()
{
	return m_watchlist->GetData();
}

/*
Adds tutorial t to watchlist.
*/
void TutorialController::AddToWatchList(Tutorial *t)
{
	m_watchlist->AddTutorial(t);
}

/*
Removes tutorial from watchlist by title and presenter.
*/
void TutorialController::RemoveFromWatchlist(std::string title, std::string presenter)
{
	m_watchlist->RemoveTutorial(title, presenter);
}

/*
Returns string representation of watchlist.
*/
std::string TutorialController::GetWatchlistString()
{
	return VectorToString(m_watchlist->GetData());
}

/*
Adds tutorial to database.
*/
void TutorialController::AddTutorial(Tutorial *tutorial)
{
	m_repo->AddTutorial(tutorial);
}

/*
Removes tutorial by title and presenter.
*/
void TutorialController::RemoveTutorial(std::string title, std::string presenter)
{
	m_repo->RemoveTutorial(title, presenter);
	try
	{
		m_watchlist->RemoveTutorial(title, presenter);
	}
	catch (exception e)
	{
		//ignore
	}
}

/*
Increases the likes on tutorial searched by ttiel and presenter.
*/
void TutorialController::IncreaseLikes(std::string title, std::string presenter)
{
	m_watchlist->IncreaseLikes(title, presenter);
	m_repo->IncreaseLikes(title, presenter);
}

/*
Updates the tutorial.
It searches by title and presenter and replaces it with tutorial.
*/
void TutorialController::UpdateTutorial(std::string title, std::string presenter, Tutorial *tutorial)
{
	m_repo->UpdateTutorial(title, presenter, tutorial);
	try
	{
		m_watchlist->UpdateTutorial(title, presenter, tutorial);
	}
	catch (exception e)
	{
		// ignore
	}
}

std::string TutorialController::TutorialsAsString()
{
	return VectorToString(m_repo->GetData());
}

/*
Returns string representation of all vectors.
*/
std::string TutorialController::VectorToString(vector<Tutorial*> v)
{
	std::string result;

	for (Tutorial *t: v)
	{
		result.append(Tutorial::ToString(t));
		result.append("\n");
	}
	return result;
}

/*
Returns a vector of tutorials with given presenter.
*/
vector<Tutorial*> *TutorialController::GetByPresenter(std::string presenter)
{
	vector<Tutorial*> *result = new vector<Tutorial*>();
	
	for (Tutorial *t : m_repo->GetData())
	{
		if (t->GetPresenter() == presenter)
		{
			result->push_back(t);
		}
	}
	return result;
}

/*
Exports watchlist with the provided exporter.
*/
void TutorialController::ExportWatchlist(Exporter *exporter)
{
	exporter->Export("watchlist", m_watchlist->GetData());
}

TutorialController::~TutorialController()
{
}

void TutorialController::Test()
{
	TutorialController *c = new TutorialController(new Repository());

	c->AddTutorial(new Tutorial("test", "test", 10, 10, 0, "www.google.com"));
	delete c;
}