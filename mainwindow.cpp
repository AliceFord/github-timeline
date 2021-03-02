#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "namepopup.h"
#include "timeline.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QUrl>
#include <QtNetwork/qnetworkrequest.h>
#include <QJsonObject>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    enterNameButton = new QPushButton("Test");
    QWidget *mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();

    mainLayout->addWidget(enterNameButton);

    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
    setGeometry(100, 100, 500, 500);

    manager = new QNetworkAccessManager();

    connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    displayPopup(1);
                    return;
                }

                QString answer = reply->readAll();
                mainLayout->removeWidget(enterNameButton);
                delete enterNameButton;

                QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());

                Timeline *timeline = new Timeline(doc.array());
                mainLayout->addWidget(timeline);
        }
    );

    displayPopup(0);
}

MainWindow::~MainWindow()
{
}

void MainWindow::displayPopup(int source) {
    NamePopup *popup = new NamePopup(this);
    if (source == 0)
        connect(enterNameButton, SIGNAL(clicked()), popup, SLOT(exec()));
    else
        popup->show();
    connect(popup, &NamePopup::finished, this, &MainWindow::popupFinished);
    connect(popup, &NamePopup::returnTwo, this, &MainWindow::nameRecieved);
}

void MainWindow::popupFinished(int result) {
    if (result == 0)
            displayPopup(1);
}


void MainWindow::nameRecieved(QString name) {
    qDebug() << "Name recieved";
    request.setUrl(QUrl("https://api.github.com/users/" + name + "/repos"));
    manager->get(request);
}
