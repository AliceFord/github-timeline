#include "committimeline.h"

CommitTimeline::CommitTimeline(QJsonArray data, QWidget *parent) : QWidget(parent)
{
    this->data = data;
}

void CommitTimeline::paintEvent(QPaintEvent *event) {

}

void CommitTimeline::mousePressEvent(QMouseEvent *event) {

}

void CommitTimeline::wheelEvent(QWheelEvent* event) {

}
