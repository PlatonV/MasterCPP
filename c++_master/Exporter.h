#pragma once

#include "master.h"

class Exporter
{
public:
	virtual void Export(string filename, vector<Tutorial*> v) = 0;
};

class CSVExporter : public Exporter
{
private:
	string TutorialToCSV(Tutorial *t)
	{
		string result;

		result.append(t->GetTitle());
		result.append(",");
		result.append(t->GetPresenter());
		result.append(",");
		result.append(to_string(t->GetDuration()->GetMinutes()) + ":" + to_string(t->GetDuration()->GetSeconds()));
		result.append(",");
		result.append(to_string(t->GetLikes()));
		result.append(",");
		result.append(t->GetLink());
		return result;
	}

public:
	virtual void Export(string filename, vector<Tutorial*> v)
	{
		ofstream f;
		filename.append(".csv");
		f.open(filename);
		for (Tutorial *t : v)
		{
			f << TutorialToCSV(t) << endl;
		}
	}
};

class HTMLExporter : public Exporter
{
private:
	string TutorialToHTML(Tutorial *t)
	{
		string result;

		result.append("\
				<tr>\
					<td>"+ t->GetTitle()+"</td>\
					<td>"+ t->GetPresenter()+"</td>\
					<td>"+ to_string(t->GetDuration()->GetMinutes()) + ":" + to_string(t->GetDuration()->GetSeconds())+"</td>\
					<td>"+ to_string(t->GetLikes())+"</td>\
					<td><a href=\""+ t->GetLink()+"\">"+t->GetTitle()+"</a></td>\
				<tr>");
		return result;
	}
public:
	virtual void Export(string filename, vector<Tutorial*> v)
	{
		ofstream f;
		filename.append(".html");
		f.open(filename);
		f <<
			"<!DOCTYPE html>\
			<html>\
			<head>\
				<title>Playlist</title>\
			</head>\
			<body>\
				<table border=\"1\">\
				<tr>\
					<td>Title</td>\
					<td>Presenter</td>\
					<td>Duration</td>\
					<td>Likes</td>\
					<td>Link</td>\
				<tr>";
		for (Tutorial *t : v)
		{
			f << TutorialToHTML(t) << endl;
		}
		f << "</table\
			</body>\
			</html>" << endl;
	}
};