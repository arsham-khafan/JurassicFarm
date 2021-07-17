#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QProgressBar>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  public slots:
    void opdatee();
private:
    QTimer*tm;
    QProgressBar*pb;
    QLabel* ql;
    QLabel* talk;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
