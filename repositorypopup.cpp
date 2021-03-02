#include "repositorypopup.h"
#include "committimeline.h"
#include "global.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>

RepositoryPopup::RepositoryPopup(QJsonArray repoData, int index)
{
    data = qAsConst(repoData)[index].toObject();

    manager = new QNetworkAccessManager();

    connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }
                setupUi(QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).array());
        }
    );

    request.setUrl(QUrl("https://api.github.com/users/TechieHelper/repos"));
    manager->get(request);
}


void RepositoryPopup::setupUi(QJsonArray commitData) {
    QString html_url = data["html_url"].toString();
    QString full_name = data["full_name"].toString();

    QLabel *title = new QLabel(full_name);

    QLabel *link = new QLabel("<a class='github-button' href='" + html_url + "' data-icon='octicon-star' data-size='large' data-show-count='true' aria-label='Star " + full_name + " on GitHub'>Visit on github</a>");
    link->setOpenExternalLinks(true);

    QLabel *createdDate = new QLabel("Created: " + dateFormmater(data["created_at"].toString()));
    QLabel *updatedDate = new QLabel("Updated: " + dateFormmater(data["updated_at"].toString()));
    QLabel *pushedDate = new QLabel("Pushed: " + dateFormmater(data["pushed_at"].toString()));

    CommitTimeline *timeline = new CommitTimeline(commitData);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(title);
    layout->addWidget(link);
    layout->addWidget(createdDate);
    layout->addWidget(updatedDate);
    layout->addWidget(pushedDate);
    layout->addWidget(timeline);
    setLayout(layout);
}
