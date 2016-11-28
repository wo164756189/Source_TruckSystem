#include "mainframe.h"
#include <QPainter>
#include <QDateTime>

MainFrame::MainFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
	QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
	ui.label_time->setText(str);//在标签上显示时间
}

MainFrame::~MainFrame()
{

}

void MainFrame::DrawCustomLine(QPainter& _painter, double _angle, double _len, const QColor& _color, QPoint& _origin)
{
	// 鍒濆鍖? 
	_painter.resetTransform(); // 閲嶈鐢荤瑪  
	_painter.translate(_origin);
	_painter.setPen(_color);
	//_painter.setPen(QPen(Qt::black, 2));

	// 缁樺埗绾挎  
	QLine _line(QPoint(0, 0), QPoint(_len, 0));
	_painter.rotate(_angle);
	_painter.drawLine(_line);

	// 缁樺埗绠ご  
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
	// 鍙嶉敮榻?
	painter.setPen(Qt::red);
	painter.setRenderHint(QPainter::Antialiasing);
	// 缁樺埗绾挎  	
    painter.drawLine(QPoint(1075, 900), QPoint(1075, 750));
    painter.drawLine(QPoint(1075, 750), QPoint(275, 750));
    QPoint trans=QPoint(275,750);
    DrawCustomLine(painter, 90, 150,  Qt::red, trans);


	QWidget::paintEvent(event);
}
