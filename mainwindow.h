#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    unsigned int totalFailures;
    unsigned int inc_num;
    unsigned int dec_num;
public slots:
    void changeFailureCount();
    void changeIncNum();
    void changeDecNum();
    void add();
    void sub();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
