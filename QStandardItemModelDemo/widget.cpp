#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Tree Model
    treeModel = new QStandardItemModel(this);
    QModelIndex parentIndex = QModelIndex();

    for (int i=0; i<5; ++i)
    {
        qDebug() << "Current iteration: " << i;
        treeModel->insertRow(0, parentIndex);
        treeModel->insertColumn(0, parentIndex);

        parentIndex = treeModel->index(0, 0, parentIndex);
        const auto value = QString("item %0").arg(i);
        treeModel->setData(parentIndex, value);
    }

    ui->treeView->setModel(treeModel);

    // Table Model
    tableModel = new QStandardItemModel(this);
    tableModel->setRowCount(3);
    tableModel->setColumnCount(5);

    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<5; ++j)
        {
            auto data = QString("row %0, column %1").arg(i).arg(j);
            auto index = tableModel->index(i, j, QModelIndex());
            tableModel->setData(index, data);
        }
    }
    ui->tableView->setModel(tableModel);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_tableView_clicked(const QModelIndex &index)
{
    const auto data = tableModel->data(index).toString();
    qDebug() << "The data at index " << index << " is " << data;
}

