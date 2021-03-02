#ifndef GLOBAL_H
#define GLOBAL_H

#include <QJsonValue>
#include <QJsonValueRef>

inline void swap(QJsonValueRef v1, QJsonValueRef v2) {
    QJsonValue temp(v1);
    v1 = QJsonValue(v2);
    v2 = temp;
}

inline QString dateFormmater(QString zuluTime) {
    int y,M,d,h,m,s;
    char formatted[256];
    sscanf(zuluTime.toStdString().c_str(), "%d-%d-%dT%d:%d:%dZ", &y, &M, &d, &h, &m, &s);
    sprintf(formatted, "%d/%d/%d %d:%d:%d", d, M, y, h, m, s);
    return QString(formatted);
}


#endif // GLOBAL_H
