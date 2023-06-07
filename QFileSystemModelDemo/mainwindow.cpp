#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dirModel{new QFileSystemModel(this)}
    , filesModel{new QFileSystemModel(this)}
{
    ui->setupUi(this);

    QString path = "./";

    // Dir model
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    dirModel->setRootPath(path);
    ui->treeView->setModel(dirModel);

    // Files model
    filesModel->setFilter(QDir::Files);
    filesModel->setRootPath(path);
    ui->listView->setModel(filesModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    const auto path = dirModel->fileInfo(index).absoluteFilePath();
    qDebug() << "User clicked on " << path;
    ui->listView->setRootIndex(filesModel->setRootPath(path));
}

