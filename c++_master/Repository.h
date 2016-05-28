#pragma once

#ifndef REPOSITORY_H
#define REPOSITORY_H

template<class T>
class DynamicVector;

class Repository
{
private:
	vector<Tutorial*>	m_data;
public:
	Repository();
	void LoadFromFile(string filename);
	void AddTutorial(Tutorial*);
	void RemoveTutorial(std::string title, std::string presenter);
	void IncreaseLikes(std::string title, std::string presenter);
	void UpdateTutorial(std::string title, std::string presenter, Tutorial*);
	vector<Tutorial*> GetData();
	static void Test();
	~Repository();
};

#endif