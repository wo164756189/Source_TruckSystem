#include "mainframe.h"
#include <QPainter>

MainFrame::MainFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

MainFrame::~MainFrame()
{

}

void MainFrame::DrawCustomLine(QPainter& _painter, double _angle, double _len, const QColor& _color, QPoint& _origin)
{
	// 初始化  
	_painter.resetTransform(); // 重设画笔  
	_painter.translate(_origin);
	_painter.setPen(_color);
	//_painter.setPen(QPen(Qt::black, 2));

	// 绘制线段  
	QLine _line(QPoint(0, 0), QPoint(_len, 0));
	_painter.rotate(_angle);
	_painter.drawLine(_line);

	// 绘制箭头  
	int off_x = 10;
	QPainterPath _path;
	_path.moveTo(_len - off_x, -5);
	_path.lineTo(_len, 0);
	_path.lineTo(_len - off_x, 5);
	_painter.drawPath(_path);
}

void MainFrame::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	// 反锯齿
	painter.setPen(Qt::red);
	painter.setRenderHint(QPainter::Antialiasing);
	// 绘制线段  	
	painter.drawLine(QPoint(1075, 1000), QPoint(1075, 850));
	painter.drawLine(QPoint(1075, 850), QPoint(275, 850));
    DrawCustomLine(painter, 90, 150,  Qt::red, QPoint(275,850));


	QWidget::paintEvent(event);
}