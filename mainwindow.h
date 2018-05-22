#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include<qcustomplot.h>
#include <QStringList>
#include <QLineEdit>
#include <QCompleter>
#include <QString>
#include <QWidget>
#include <QLabel>

#include <qfile.h>
#include <QTextStream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   //QCPGraph *graph1;
public slots:
    void plotraw();
    void call_kmeans();
    void plotClusters();
    void on_pushButton_7_clicked();

private slots:
    void on_pushButton_8_clicked();


    void on_pushButton_6_clicked();

private:

};

#endif // MAINWINDOW_H
