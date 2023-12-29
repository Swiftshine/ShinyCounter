#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , totalFailures(0)
    , inc_num(0)
    , dec_num(0)
{
    ui->setupUi(this);

    ui->count_egg->setValue(0);
    ui->count_inc->setValue(0);
    ui->count_dec->setValue(0);

    QObject::connect(ui->button_add, &QPushButton::clicked, this, &MainWindow::add);
    QObject::connect(ui->button_sub, &QPushButton::clicked, this, &MainWindow::sub);
    QObject::connect(ui->count_egg, &QSpinBox::valueChanged, this, &MainWindow::changeFailureCount);
    QObject::connect(ui->count_inc, &QSpinBox::valueChanged, this, &MainWindow::changeIncNum);
    QObject::connect(ui->count_dec, &QSpinBox::valueChanged, this, &MainWindow::changeDecNum);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeFailureCount() {
    this->totalFailures = ui->count_egg->value();
}

void MainWindow::changeIncNum() {
    this->inc_num = ui->count_inc->value();

}

void MainWindow::changeDecNum() {
    this->dec_num = ui->count_dec->value();
}

void MainWindow::add() {
    if (inc_num < 99999 && totalFailures + inc_num < 99999 && totalFailures < 99999) { // just pick an arbitrary value
        totalFailures += inc_num;
        ui->count_egg->setValue(totalFailures);
    }
}

void MainWindow::sub() {
    if (dec_num < 99999 && totalFailures - dec_num > 0 && totalFailures > 0) {
        totalFailures -= dec_num;
        ui->count_egg->setValue(totalFailures);
    }
}
