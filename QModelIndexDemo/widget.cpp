#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , model{new QFileSystemModel(this)}
    , parentIndex{model->setRootPath("./")}
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const auto rowCount = model->rowCount(parentIndex);
    qDebug() << "Row count: " << rowCount;

    for (int i=0; i<rowCount; ++i)
    {
        QModelIndex index = model->index(i, 0, parentIndex);
        const auto data = model->data(index, Qt::DisplayRole).toString();
        qDebug() << "Data item [" << i << "] " << data;
    }
}

