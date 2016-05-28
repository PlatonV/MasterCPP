#pragma once

#ifndef TUTORIALCONTROLLER_H
#define TUTORIALCONTROLLER_H

class TutorialController
{
	Repository *m_repo;
	Repository *m_watchlist;

public:
	TutorialController(Repository *);

	void AddTutorial(Tutorial*);
	void RemoveTutorial(std::string, std::string);
	void IncreaseLikes(std::string title, std::string presenter);
	void UpdateTutorial(std::string, std::string, Tutorial*);
	void AddToWatchList(Tutorial*);
	void RemoveFromWatchlist(std::string, std::string);
	std::string GetWatchlistString();
	void TutorialController::ExportWatchlist(Exporter*);
	vector<Tutorial*> *GetByPresenter(std::string);
	vector<Tutorial*> GetAll();
	vector<Tutorial*> GetWatchlist();
	std::string TutorialsAsString();
	std::string VectorToString(vector<Tutorial*>);

	~TutorialController();
	static void Test();
};

#endif