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
	// ��ʼ��  
	_painter.resetTransform(); // ���軭��  
	_painter.translate(_origin);
	_painter.setPen(_color);
	//_painter.setPen(QPen(Qt::black, 2));

	// �����߶�  
	QLine _line(QPoint(0, 0), QPoint(_len, 0));
	_painter.rotate(_angle);
	_painter.drawLine(_line);

	// ���Ƽ�ͷ  
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
	// �����
	painter.setPen(Qt::red);
	painter.setRenderHint(QPainter::Antialiasing);
	// �����߶�  	
	painter.drawLine(QPoint(1075, 1000), QPoint(1075, 850));
	painter.drawLine(QPoint(1075, 850), QPoint(275, 850));
    DrawCustomLine(painter, 90, 150,  Qt::red, QPoint(275,850));


	QWidget::paintEvent(event);
}