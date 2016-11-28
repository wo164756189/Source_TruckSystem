#include "mainframe.h"
#include <QPainter>
#include <QDateTime>

MainFrame::MainFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QDateTime time = QDateTime::currentDateTime();//��ȡϵͳ���ڵ�ʱ��
	QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //������ʾ��ʽ
	ui.label_time->setText(str);//�ڱ�ǩ����ʾʱ��
}

MainFrame::~MainFrame()
{

}

void MainFrame::DrawCustomLine(QPainter& _painter, double _angle, double _len, const QColor& _color, QPoint& _origin)
{
	// 初始�? 
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
	// 反锯�?
	painter.setPen(Qt::red);
	painter.setRenderHint(QPainter::Antialiasing);
	// 绘制线段  	
    painter.drawLine(QPoint(1075, 900), QPoint(1075, 750));
    painter.drawLine(QPoint(1075, 750), QPoint(275, 750));
    QPoint trans=QPoint(275,750);
    DrawCustomLine(painter, 90, 150,  Qt::red, trans);


	QWidget::paintEvent(event);
}
