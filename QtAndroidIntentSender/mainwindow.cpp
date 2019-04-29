#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "intent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClose_clicked()
{
    qApp->exit();
}

void MainWindow::on_btnAndroid_clicked()
{
    Intent intent;
    intent.send("I Love Android!");
}

void MainWindow::on_btnQt_clicked()
{
    Intent intent;
    intent.send("I Love Qt!");
}
