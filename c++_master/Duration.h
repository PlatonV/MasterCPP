#pragma once

#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
	unsigned int m_minutes;
	unsigned int m_seconds;
public:

	Duration() {}
	Duration(int minutes, int seconds) { m_minutes = minutes; m_seconds = seconds; }
	unsigned int GetMinutes();
	unsigned int GetSeconds();
};

#endif