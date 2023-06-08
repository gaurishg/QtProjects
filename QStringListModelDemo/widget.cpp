#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

    QStringList list;
    list << "Cow" << "Rooster" << "Lion" << "Hyena" << "Buffalo";

    model->setStringList(list);
    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "The current data is " << model->stringList();
}

