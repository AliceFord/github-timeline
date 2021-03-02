#include "timeline.h"
#include "repositorypopup.h"
#include "global.h"

#include <QDebug>
#include <QJsonObject>
#include <bits/stdc++.h>
#include <QMouseEvent>

Timeline::Timeline(QJsonArray data, QWidget *parent) : QWidget(parent)
{
    repoData = data;

    std::sort(repoData.begin(), repoData.end(), [](const QJsonValue &v1, const QJsonValue &v2) {
        return v1.toObject()["id"].toInt() < v2.toObject()["id"].toInt();
    });
}

void Timeline::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    int counter = 0;
    circleBoundingBoxes.clear();
    for (QJsonValue ref : qAsConst(repoData)) {
        painter.setBrush(QBrush(QColor(255, 255, 255)));
        painter.setPen(Qt::NoPen);
        QRect *currentBox = new QRect(this->width()/2, counter+offset, 50, 50);
        painter.drawEllipse(*currentBox);
        circleBoundingBoxes.append(currentBox);
        painter.setPen(Qt::SolidLine);
        painter.drawText(this->width()/2+55, counter+offset+30, ref.toObject()["name"].toString());
        std::string dateStr = ref.toObject()["created_at"].toString().toStdString();
        int y,M,d,h,m,s;
        char formatted[256];
        sscanf(dateStr.c_str(), "%d-%d-%dT%d:%d:%dZ", &y, &M, &d, &h, &m, &s);
        sprintf(formatted, "%d/%d/%d", d, M, y);
        painter.drawText(this->width()/2, counter+offset+30, QString(formatted));
        counter += 75;
    }
}

void Timeline::mousePressEvent(QMouseEvent *event) {
    int counter=0;
    for (QRect *rect : qAsConst(circleBoundingBoxes)) {
        if (rect->contains(event->pos())) {
            RepositoryPopup *popup = new RepositoryPopup(repoData, counter);
            popup->show();
            break;
        }
        counter++;
    }
}

void Timeline::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0 && offset < 0) {
        offset += scrollOffset;
    } else if (event->angleDelta().y() < 0) {
        offset -= scrollOffset;
    }
    update();
}
