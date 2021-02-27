#ifndef NAMEPOPUP_H
#define NAMEPOPUP_H

#include <QDialog>
#include <QObject>
#include <QLineEdit>

class NamePopup : public QDialog
{
    Q_OBJECT
public:
    NamePopup(QWidget *parent = nullptr);

private:
    QLineEdit *nameInput;

public slots:
    void returnValue();

signals:
    void returnTwo(QString val);
};

#endif // NAMEPOPUP_H
