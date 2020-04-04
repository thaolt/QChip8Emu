#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLdROM_clicked()
{
    ui->display->pixelSet(10,3);
    ui->display->pixelSet(11,3);
    ui->display->pixelSet(12,4);
    ui->display->pixelSet(13,4);
    ui->display->pixelSet(20,10);
    ui->display->pixelSet(30,15);
    ui->display->pixelSet(40,30);
}

void MainWindow::on_btnReset_clicked()
{
    ui->display->screenClear();
}


void MainWindow::on_btnPause_clicked()
{
    ui->display->pixelClear(40,30);
}


void MainWindow::on_btnConfig_clicked()
{
    ui->display->pixelToggle(20,10);
}
