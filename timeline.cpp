#include "timeline.h"

#include <QDebug>
#include <QJsonObject>

Timeline::Timeline(QJsonArray data, QWidget *parent) : QWidget(parent)
{
    repoData = data;
    for (QJsonValueRef ref : data) {
        qDebug() << ref.toObject()["name"];
    }
}

void Timeline::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    int counter = 0;
    for (QJsonValueRef ref : repoData) {
        painter.setBrush(QBrush(QColor(255, 255, 255)));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(this->width()/2, counter, 30, 30);
        painter.setPen(Qt::SolidLine);
        painter.drawText(this->width()/2+35, counter+20, ref.toObject()["name"].toString());
        counter += 50;
    }
}
