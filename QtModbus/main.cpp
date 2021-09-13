#include "qtmodbus.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtModbus w;
	w.show();
	return a.exec();
}
