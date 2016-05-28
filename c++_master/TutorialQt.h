#ifndef UIQT_H
#define UIQT_H

#include <QtWidgets/QMainWindow>
#include "master.h"
#include "master_cpp.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class TutorialQt : public QWidget //public QMainWindow
{
	Q_OBJECT

public:
	TutorialQt(TutorialController& c, QWidget *parent = 0);
	~TutorialQt();

private:
	TutorialController& ctrl;
	std::vector<Tutorial*> currentTutorialsInRepoList;
	std::vector<Tutorial*> currentTutorialsInWatchlistList;
	Tutorial* selectedTutorial;
	Tutorial* selectedWatchlist;

	QListWidget* repoList;
	QLineEdit* titleEdit;
	QLineEdit* presenterEdit;
	QLineEdit* durationEdit;
	QLineEdit* likesEdit;
	QLineEdit* linkEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* moveToWatchlistButton;
	QPushButton* removeFromWatchlistButton;
	QPushButton* moveOneSongButton;
	QPushButton* moveAllSongsButton;
	QPushButton* likeButton;
	QPushButton* watchButton;
	QPushButton* exportCSVButton;
	QPushButton* exportHTMLButton;

	QListWidget* playList;
	QListWidget* watchlistList;

	void initGUI();
	void populateRepoList();
	void populateWatchlistList();
	int getRepoListSelectedIndex();
	int getWatchlistListSelectedIndex();

	void connectSignalsAndSlots();
	
	private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();
	void watchlistItemChanged();
	
	void addNewTutorial();
	void deleteTutorial();

	void like();
	void watch();
	void exportCSV();
	void exportHTML();
	
	// filters the elements in the list, by the artist written in the artist edit box
	void updateTutorial();
	void moveTutorialToWatchlist();
	void removeTutorialFromWatchlist();
};

#endif