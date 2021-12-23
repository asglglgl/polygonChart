#pragma once

#include <QWidget>
#include "ui_RadarChart.h"

#include <QPainter>
#include <qmath.h>
#include <QColor>
enum RadarType{ Radar, Spider};
enum PointType{ ScatterPoints, LinePoints};

typedef struct RadarData
{
    RadarData( const QVector<qreal> &_value,const QColor& _color){ value = _value; color = _color;}
    QVector<qreal> value;
    QColor color;
};

#define PI 3.1415926

class RadarChart : public QWidget
{
	Q_OBJECT

public:
	RadarChart(QWidget *parent = Q_NULLPTR);
	~RadarChart();

	void setRadarType(RadarType radartype);
	void setPointType(PointType pointstype);
	void paintEvent(QPaintEvent * event);

    void setTitle(const QVector<QString>& titile);
    void setDatas(const QList<RadarData> &datas);

	//	设置数值范围
	void setAxisRange(qreal min, qreal max);

	//	设置多边形个数
	void setAngularCount(int nNum){ m_AngularCount = nNum; }	

	//	设置层级数
	void setTickCount(int tickCount){ m_tickCount = tickCount; this->update(); }

	void setTitleFont(const QFont &titleFont){ m_titleFont = titleFont; this->update(); }
	void setTitleColor(const QColor &titleColor){ m_titleColor = titleColor; this->update(); }
	void setSeriesColor(const QColor &color){ m_seriesColor = color; this->update(); }

private:
	void drawTitle(QPainter *painter);
	void drawRadarType(QPainter *painter);	//	绘制雷达类型
	void drawRadar(QPainter *painter);
	void drawSpider(QPainter *painter);

	void drawPolygon(QPainter *painter);
	void drawLine(QPainter *painter);
	void drawScaleNum(QPainter *painter);
	void drawLegends(QPainter *painter);

	void init();
	void drawRadialLabel(QPainter *painter);
	void drawAngularLabel(QPainter *painter);

	void drawAxisLabel(QPainter *painter);
	void drawLabel(QPainter *painter);
	void drawData(QPainter *painter);
	void drawScatterPoints(QPainter *painter);
	void drawLinePoints(QPainter *painter);

	void setRadialAxisLabelVisible(bool visible){ m_showRadialAxisLabel = visible; this->update(); }
	void setAngularAxisLabelVisible(bool visible){ m_showAngularAxisLabel = visible; this->update(); }
	void setTitle(const QString &title){ m_title = title; this->update(); }
	
	void setAngularLineColor(const QColor &color){ m_AngularLineColor = color; this->update(); }
	void setRadialLineColor(const QColor &color){ m_RadialLineColor = color; this->update(); }
	void setAngularLabelColor(const QColor &color){ m_AngularLabelColor = color; this->update(); }
	void setRadialLabelColor(const QColor &color){ m_RadialLabelColor = color; this->update(); }
	
	void setbackgroundColor(const QColor &color){ m_backgroundColor = color; this->update(); }
	void setmLabelFont(const QFont &labelFont){ m_labelFont = labelFont; this->update(); }

private:
	RadarType m_radartype;
	PointType m_pointstype;

	bool m_showRadialAxisLabel;
	bool m_showAngularAxisLabel;

	QString m_title;
	QFont m_titleFont;
	QColor m_titleColor;
    QList<RadarData> m_datas;

	int m_tickCount;		//	层级数
	int m_AngularCount;		//	多边形数

	qreal m_Axis_min;
	qreal m_Axis_max;

	QColor m_AngularLineColor;
	QColor m_RadialLineColor;
	QColor m_AngularLabelColor;
	QColor m_RadialLabelColor;
    QColor m_seriesColor;
	QColor m_backgroundColor;

	QFont m_labelFont;
	qreal m_titleHeight;
    QVector<QString> m_titile;

private:
	Ui::RadarChart ui;
};
