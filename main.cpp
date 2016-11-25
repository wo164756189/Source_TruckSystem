#include "mainframe.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainFrame w;
	//w.move(-500, -500);
	w.show();
	return a.exec();
}
