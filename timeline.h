#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QGraphicsView>
#include <QJsonObject>
#include <QJsonArray>

class Timeline : public QWidget
{
    Q_OBJECT
public:
    explicit Timeline(QJsonArray data, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QJsonArray repoData;
};

#endif // TIMELINE_H
