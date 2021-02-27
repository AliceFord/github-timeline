#include "namepopup.h"
#include "mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

NamePopup::NamePopup(QWidget *parent) : QDialog(parent)
{
    nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Name");

    QPushButton *submitPutton = new QPushButton("Submit");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(nameInput);
    layout->addWidget(submitPutton);
    setLayout(layout);
    setGeometry(600, 600, 100, 100);
    connect(submitPutton, &QPushButton::clicked, this, &NamePopup::returnValue);
}

void NamePopup::returnValue() {
    emit returnTwo(nameInput->text());
    accept();
}
