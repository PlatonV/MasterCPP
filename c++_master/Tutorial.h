#pragma once

#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Duration.h"

class Tutorial
{
private:
	std::string		m_title;
	std::string		m_presenter;
	Duration		*m_duration;
	unsigned int	m_likes;
	std::string 	m_link;
public:
	Tutorial() {};
	Tutorial(std::string title,
		std::string presenter,
		int minutes,
		int seconds,
		unsigned int likes,
		std::string link)
	{
		m_title = title;
		m_presenter = presenter;
		m_duration = new Duration(minutes, seconds);
		m_likes = likes;
		m_link = link;
	}
	std::string GetTitle() const { return m_title; }
	std::string  GetPresenter() const { return m_presenter; }
	Duration *GetDuration() const { return m_duration; }
	unsigned int GetLikes() const { return m_likes; }
	std::string GetLink() const { return m_link; }
	void Like() { m_likes++; }

	bool operator==(const Tutorial& rhs) const
	{
		return this->GetTitle() == rhs.GetTitle() && this->GetPresenter() == rhs.GetPresenter();
	}

	friend ostream& operator<<(ostream& os, const Tutorial& t)
	{
		os << "Title: " << t.GetTitle() << endl <<
			"Presenter: " << t.GetPresenter() << endl <<
			"Duration: " << to_string(t.GetDuration()->GetMinutes()) + ":" + to_string(t.GetDuration()->GetSeconds()) << endl <<
			"Likes: " << to_string(t.GetLikes()) << endl <<
			"Link: " << t.GetLink() << endl;
		return os;
	}

	friend istream &operator>>(istream  &input, Tutorial &t)
	{
		int minutes, seconds;
		input >> t.m_title >> t.m_presenter >> minutes >> seconds >> t.m_likes >> t.m_link;
		t.m_duration = new Duration(minutes, seconds);
		return input;
	}

	static std::string ToString(Tutorial *t)
	{
		std::string result;
		result.append("Title: " + t->GetTitle());
		result.append("\n");
		result.append("Presenter: " + t->GetPresenter());
		result.append("\n");
		result.append("Duration: " + std::to_string(t->GetDuration()->GetMinutes()) + ":" + std::to_string(t->GetDuration()->GetSeconds()));
		result.append("\n");
		result.append("Likes: " + std::to_string(t->GetLikes()));
		result.append("\n");
		result.append("Link: " + t->GetLink());
		return result;
	}

	~Tutorial() 
	{
		delete m_duration;
	}
};

#endif