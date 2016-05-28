#ifndef MYCLASS_H
#define MYCLASS_H

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"

# include <cstdio>
# include <cstring>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <cstdlib>

using namespace	std;

#include "Utils.h"

class MyClass : public QMainWindow
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
};

#endif // MYCLASS_H
