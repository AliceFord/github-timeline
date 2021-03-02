#ifndef COMMITTIMELINE_H
#define COMMITTIMELINE_H

#include <QWidget>
#include <QJsonArray>

class CommitTimeline : public QWidget
{
    Q_OBJECT
public:
    explicit CommitTimeline(QJsonArray data, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
private:
    QJsonArray data;

};

#endif // COMMITTIMELINE_H
