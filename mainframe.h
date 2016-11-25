#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QtWidgets/QWidget>
#include "ui_mainframe.h"

class MainFrame : public QWidget
{
	Q_OBJECT

public:
	MainFrame(QWidget *parent = 0);
	~MainFrame();

private:
	Ui::MainFrameClass ui;

	void DrawCustomLine(QPainter& _painter, double _angle, double _len, const QColor& _color, QPoint& _origin);
	void paintEvent(QPaintEvent *event);
};

#endif // MAINFRAME_H
