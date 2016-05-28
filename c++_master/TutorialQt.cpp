#include "master.h"
#include "TutorialQt.h"
#include <vector>
#include "master_cpp.h"
#include <qurl.h>
#include <qdesktopservices.h>
#include <QMessageBox>

TutorialQt::TutorialQt(TutorialController& c, QWidget *parent) : ctrl{ c }, QWidget{ parent }
{
	this->initGUI();
	this->currentTutorialsInRepoList = this->ctrl.GetAll();
	this->populateRepoList();
}

TutorialQt::~TutorialQt()
{
	
}

void	TutorialQt::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* TutorialDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ TutorialDataWidget };
	this->titleEdit = new QLineEdit{};
	this->presenterEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	formLayout->addRow("&Title:", titleEdit);
	formLayout->addRow("&Presenter:", presenterEdit);
	formLayout->addRow("&Duration:", durationEdit);
	formLayout->addRow("&Likes:", likesEdit);
	formLayout->addRow("&Link:", linkEdit);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->moveToWatchlistButton = new QPushButton("To watchlist");
	this->removeFromWatchlistButton = new QPushButton("Remove from watchlist");
	this->likeButton = new QPushButton("Like");
	this->watchButton = new QPushButton("Watch");
	this->exportCSVButton = new QPushButton("Export CSV");
	this->exportHTMLButton = new QPushButton("Export HTML");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 1, 0);
	gridLayout->addWidget(updateButton, 2, 0);
	gridLayout->addWidget(moveToWatchlistButton, 0, 3);
	gridLayout->addWidget(removeFromWatchlistButton, 1, 3);
	gridLayout->addWidget(likeButton, 0, 1);
	gridLayout->addWidget(watchButton, 1, 1);
	gridLayout->addWidget(exportCSVButton, 0, 2);
	gridLayout->addWidget(exportHTMLButton, 1, 2);

	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	this->watchlistList = new QListWidget{};
	this->watchlistList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* WatchlistDataWidget = new QWidget{};
	QFormLayout* watchlistFormLayout = new QFormLayout{ WatchlistDataWidget };

	// add everything to the left layout
	rightSide->addWidget(new QLabel{ "Watchlist:" });
	rightSide->addWidget(watchlistList);
	rightSide->addWidget(WatchlistDataWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(rightWidget);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All Tutorials:" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(TutorialDataWidget);
	leftSide->addWidget(buttonsWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(rightWidget);

	this->connectSignalsAndSlots();
}

void TutorialQt::connectSignalsAndSlots()
{
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->watchlistList, SIGNAL(itemSelectionChanged()), this, SLOT(watchlistItemChanged()));

	// add button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewTutorial()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTutorial()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateTutorial()));
	QObject::connect(this->moveToWatchlistButton, SIGNAL(clicked()), this, SLOT(moveTutorialToWatchlist()));
	QObject::connect(this->removeFromWatchlistButton, SIGNAL(clicked()), this, SLOT(removeTutorialFromWatchlist()));
	QObject::connect(this->likeButton, SIGNAL(clicked()), this, SLOT(like()));
	QObject::connect(this->watchButton, SIGNAL(clicked()), this, SLOT(watch()));
	QObject::connect(this->exportCSVButton, SIGNAL(clicked()), this, SLOT(exportCSV()));
	QObject::connect(this->exportHTMLButton, SIGNAL(clicked()), this, SLOT(exportHTML()));
}

void TutorialQt::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto s : this->currentTutorialsInRepoList)
	{
		QString itemInList = QString::fromStdString(s->GetPresenter() + " - " + s->GetTitle());
		this->repoList->addItem(itemInList);
	}

	// set the selection on the first item in the list
	if (this->currentTutorialsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void TutorialQt::populateWatchlistList()
{
	if (this->watchlistList->count() > 0)
		this->watchlistList->clear();

	for (auto s : this->currentTutorialsInWatchlistList)
	{
		QString itemInList = QString::fromStdString(s->GetPresenter() + " - " + s->GetTitle() + " " + to_string(s->GetLikes()));
		this->watchlistList->addItem(itemInList);
	}

	// set the selection on the first item in the list
	if (this->currentTutorialsInWatchlistList.size() > 0)
		this->watchlistList->setCurrentRow(0);
}


int TutorialQt::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->presenterEdit->clear();
		this->titleEdit->clear();
		this->durationEdit->clear();
		this->likesEdit->clear();
		this->linkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

int TutorialQt::getWatchlistListSelectedIndex()
{
	if (this->watchlistList->count() == 0)
		return -1;

	QModelIndexList index = this->watchlistList->selectionModel()->selectedIndexes();
	int idx;
	if (index.size() > 0)
		idx = index.at(0).row();
	else
		return -1;
	return idx;
}

void TutorialQt::watchlistItemChanged()
{
	int idx = this->getWatchlistListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial*> tutorials = this->currentTutorialsInWatchlistList;

	if (idx >= tutorials.size())
		return;
	selectedWatchlist = tutorials[idx];

	this->presenterEdit->setText(QString::fromStdString(selectedWatchlist->GetPresenter()));
	this->titleEdit->setText(QString::fromStdString(selectedWatchlist->GetTitle()));
	this->durationEdit->setText(QString::fromStdString(std::to_string(selectedWatchlist->GetDuration()->GetMinutes()) + ":" + std::to_string(selectedTutorial->GetDuration()->GetSeconds())));
	this->likesEdit->setText(QString::fromStdString(to_string(selectedWatchlist->GetLikes())));
	this->linkEdit->setText(QString::fromStdString(selectedWatchlist->GetLink()));
}


void TutorialQt::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial*> tutorials = this->currentTutorialsInRepoList;

	// get the song at the selected index
	if (idx >= tutorials.size())
		return;
	selectedTutorial = tutorials[idx];

	this->presenterEdit->setText(QString::fromStdString(selectedTutorial->GetPresenter()));
	this->titleEdit->setText(QString::fromStdString(selectedTutorial->GetTitle()));
	this->durationEdit->setText(QString::fromStdString(std::to_string(selectedTutorial->GetDuration()->GetMinutes()) + ":" + std::to_string(selectedTutorial->GetDuration()->GetSeconds())));
	this->likesEdit->setText(QString::fromStdString(to_string(selectedTutorial->GetLikes())));
	this->linkEdit->setText(QString::fromStdString(selectedTutorial->GetLink()));
}

void TutorialQt::addNewTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}
	long likes = this->likesEdit->text().toLong();
	std::string link = this->linkEdit->text().toStdString();
	Tutorial *tutorial = new Tutorial(title, presenter, atoi(durationTokens[1].c_str()), atoi(durationTokens[0].c_str()), likes, link);

	try
	{
		ctrl.AddTutorial(tutorial);
		this->currentTutorialsInRepoList = this->ctrl.GetAll();
		this->populateRepoList();
	}
	catch (exception e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot add tutorial");
	}
}

void TutorialQt::deleteTutorial()
{
	try
	{
		ctrl.RemoveTutorial(selectedTutorial->GetTitle(), selectedTutorial->GetPresenter());
		this->currentTutorialsInRepoList = this->ctrl.GetAll();
		this->populateRepoList();
		this->currentTutorialsInWatchlistList = this->ctrl.GetWatchlist();
		this->populateWatchlistList();
	}
	catch (exception e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TutorialQt::updateTutorial()
{
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string title = this->titleEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}
	long likes = this->likesEdit->text().toLong();
	std::string link = this->linkEdit->text().toStdString();
	Tutorial *tutorial = new Tutorial(title, presenter, 10, 12, likes, link);

	try 
	{
		ctrl.UpdateTutorial(selectedTutorial->GetTitle(), selectedTutorial->GetPresenter(), tutorial);
		this->currentTutorialsInRepoList = this->ctrl.GetAll();
		this->populateRepoList();
		this->currentTutorialsInWatchlistList = this->ctrl.GetWatchlist();
		this->populateWatchlistList();
	}
	catch (exception e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TutorialQt::moveTutorialToWatchlist()
{
	try 
	{
		this->ctrl.AddToWatchList(new Tutorial(
			selectedTutorial->GetTitle(),
			selectedTutorial->GetPresenter(),
			selectedTutorial->GetDuration()->GetMinutes(), selectedTutorial->GetDuration()->GetSeconds(),
			selectedTutorial->GetLikes(),
			selectedTutorial->GetLink()
			));
		this->currentTutorialsInWatchlistList.clear();
		this->currentTutorialsInWatchlistList = this->ctrl.GetWatchlist();
		this->populateWatchlistList();
	}
	catch (exception e)
	{ 
		// ignore
	}
}

void TutorialQt::removeTutorialFromWatchlist()
{
	try
	{
		this->ctrl.RemoveFromWatchlist(selectedWatchlist->GetTitle(), selectedWatchlist->GetPresenter());
		this->currentTutorialsInWatchlistList.clear();
		this->currentTutorialsInWatchlistList = this->ctrl.GetWatchlist();
		this->populateWatchlistList();
	}
	catch (exception e)
	{
		//ignore
	}
}

void TutorialQt::like()
{
	try
	{
		this->ctrl.IncreaseLikes(selectedWatchlist->GetTitle(), selectedWatchlist->GetPresenter());
		this->currentTutorialsInWatchlistList.clear();
		this->currentTutorialsInWatchlistList = this->ctrl.GetWatchlist();
		this->populateWatchlistList();
	}
	catch (exception e)
	{
		//ignore
	}
}

void TutorialQt::exportCSV()
{
	this->ctrl.ExportWatchlist(new CSVExporter());
}

void TutorialQt::exportHTML()
{
	this->ctrl.ExportWatchlist(new HTMLExporter());
}

void TutorialQt::watch()
{
	try
	{
		QDesktopServices::openUrl(QUrl(QString::fromStdString(selectedWatchlist->GetLink())));
	}
	catch (exception e)
	{
		//ignore
	}
}

