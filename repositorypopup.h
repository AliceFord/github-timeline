#ifndef REPOSITORYPOPUP_H
#define REPOSITORYPOPUP_H

#include <QJsonArray>
#include <QDialog>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class RepositoryPopup : public QDialog
{
    Q_OBJECT
public:
    RepositoryPopup(QJsonArray repoData, int index);
private:
    void setupUi(QJsonArray commitData);
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QJsonObject data;
    int index;
};

#endif // REPOSITORYPOPUP_H
