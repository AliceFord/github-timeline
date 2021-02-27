#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void popupFinished(int result);
    void nameRecieved(QString name);
    void displayPopup(int source);

private:
    QString name;
    QPushButton* enterNameButton;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QHBoxLayout *mainLayout;
};
#endif // MAINWINDOW_H
