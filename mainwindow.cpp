#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RadarChart.h"
#include "QHBoxLayout"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RadarChart *chart = new RadarChart();
    QVector<QString> title;
    title.append(QStringLiteral("能力xx1"));
    title.append(QStringLiteral("能力xx2"));
    title.append(QStringLiteral("能力xx3"));
    title.append(QStringLiteral("能力xx4"));
    title.append(QStringLiteral("能力xx5"));
    title.append(QStringLiteral("能力xx6"));
    chart->setTitle(title);
    QList<RadarData> datas;
    QVector<qreal> data;
    data.append(20);
    data.append(20);
    data.append(20);
    data.append(20);
    data.append(20);
    data.append(20);
    QVector<qreal> data1;
    data1.append(40);
    data1.append(40);
    data1.append(40);
    data1.append(40);
    data1.append(40);
    data1.append(40);
        datas << RadarData( data,QColor(0,255,0,120)) <<
                RadarData( data1,QColor(255,0,0,120));


        chart->setDatas(datas);		//	添加数据，并计算多边形个数
        chart->setTickCount(4);		//	设置层级数
        chart->setAxisRange(0, 100);	//	设置刻度范围
        chart->setSeriesColor(QColor(45, 42, 221, 20));	//	设置区域块颜色
    QHBoxLayout* l =new QHBoxLayout;
    l->addWidget(chart);
    ui->centralWidget->setLayout(l);
}

MainWindow::~MainWindow()
{
    delete ui;
}
