// Main File for project entry point
#include <QApplication>
#include "mainwindow.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Start";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
