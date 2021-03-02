#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QGraphicsView>
#include <QJsonObject>
#include <QJsonArray>
#include <QRect>

class Timeline : public QWidget
{
    Q_OBJECT
public:
    explicit Timeline(QJsonArray data, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
private:
    QJsonArray repoData;
    QVector<QRect *> circleBoundingBoxes;
    int offset = 0;
    static const int scrollOffset = 20;
};

#endif // TIMELINE_H
