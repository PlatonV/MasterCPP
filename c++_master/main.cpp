#include "master.h"
#include "master_cpp.h"
#include "TutorialQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo = Repository();
	repo.AddTutorial(new Tutorial("Tutorial1", "Presenter1", 10, 10, 0, "www.google.com"));
	repo.AddTutorial(new Tutorial("Tutorial2", "Presenter1", 12, 13, 0, "www.google.com"));
	repo.AddTutorial(new Tutorial("Tutorial3", "Presenter1", 45, 25, 0, "www.google.com"));
	repo.AddTutorial(new Tutorial("Tutorial4", "Presenter2", 7, 21, 0, "www.google.com"));
	repo.AddTutorial(new Tutorial("Tutorial5", "Presenter2", 30, 59, 0, "www.google.com"));
	TutorialController controller = TutorialController(&repo);
	TutorialQt w{ controller };
	w.show();
	return a.exec();
}
