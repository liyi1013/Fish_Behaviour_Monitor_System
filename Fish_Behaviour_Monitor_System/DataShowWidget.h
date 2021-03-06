#pragma execution_character_set("utf-8")
#pragma once

#include<fstream>

#include <qstring.h>
#include <QtCore\qdebug.h>
#include <QtCore\qvector.h>
#include <QtWidgets\QWidget>
#include <QtWidgets\qpushbutton.h>
#include "qcustomplot.h"

// 这个类放在mainwindow中，用于视频帧对应的数据的显示
class DataShowWidget : public QWidget
{
public:
	DataShowWidget(QWidget *parent = 0);
	~DataShowWidget();

public:

	void add_Graphs(int num_graphs);//添加num_graphs条曲线
	void set_title(QString t);
	void set_unit(QString u);
	void updata_data(double data);
	void updata_data(std::vector<double> data);

	void setRange(int x1, int x2){ ui_qcustomplot->yAxis->setRange(x1,x2); };
private:
	void setupUi();

private:
	QCustomPlot* ui_qcustomplot;
	QString title;
	float current_data;

	QLabel ui_show_title;
	
	QLabel ui_show_unit;
public:
	QLabel ui_show_data;
};

