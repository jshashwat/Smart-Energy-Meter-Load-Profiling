#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kmeans.h"
#include "point.h"
#include "cluster.h"
#include<qcustomplot.h>
#include<iostream>
#include <QStringList>
#include <QLineEdit>
#include <QCompleter>
#include <QString>
#include <QWidget>
#include <QProcess>
#include <QLabel>
#include <qfile.h>
#include <QTextStream>
#include <fstream>
using namespace std;
QString filename;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow :: call_kmeans()
{
    ifstream myRead;
        myRead.open("kmeans_data.txt");
        int total_points, total_values, K, max_iterations, has_name;

        myRead >> total_points >> total_values >> K >> max_iterations >> has_name;

        vector<point> points;
        string point_name;

        for(int i = 0; i < total_points; i++)
        {
            vector<double> values;

            for(int j = 0; j < total_values; j++)
            {
                double value;
                myRead >> value;
                values.push_back(value);
            }

            if(has_name)
            {
                myRead >> point_name;
                point p(i, values, point_name);
                points.push_back(p);
            }
            else
            {
                point p(i, values);
                points.push_back(p);
            }
        }
        myRead.close();
        kmeans km(K, total_points, total_values, max_iterations);
        km.run(points);
}


void MainWindow::plotraw()
{
    QString line;
    int rowCount=0;
    cout<<"fesfs\n";
    QStringList qList;
    QFile File(filename);
    QVector<float> z;
     QVector<double> x1, y1;
    if(File.open(QIODevice::ReadOnly))
    {
        cout<<"fesfs\n";
        //ui->txtXYRadius->appendPlainText(QString("X_Pos of Vehicle = "));
        QTextStream out(&File);
        while(!out.atEnd())
        {
            line=out.readLine();
            line=line.mid(0,line.length());
            qList=line.split(",");
            z.append(qList[0].toFloat());
            z.append(qList[1].toFloat());
            rowCount++;
        }
        File.close();
    }
    cout<<z[0]<<" "<<z[1]<<endl;
    int len=z.size();
    // ui->txtXYRadius->appendPlainText(QString::number(len));

    for (int i=0; i<len/2; ++i)
    {
        //ui->txtXYRadius->appendPlainText(QString("X_Pos of Vehicle = "));
        //cout<<z[i];
      x1.append(z[i*2]);
      y1.append(z[i*2+1]);
    }

    // create and configure plottables:
    QCPGraph *graph1 = ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 0.5), QBrush(Qt::black), 9));
    graph1->setPen(Qt::NoPen);

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));

    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    ui->customPlot->rescaleAxes(true);
}



void MainWindow::plotClusters()
{

    QString line;
    int rowCount=0;
    QStringList qList;
    QFile File(filename);
    QVector<float> z;
    QVector<double> x1, y1;
    QVector<double> x2, y2;
    QVector<double> x3, y3;
    QVector<double> x4, y4;
    if(File.open(QIODevice::ReadOnly))
    {
        cout<<"fesfs\n";
        //ui->txtXYRadius->appendPlainText(QString("X_Pos of Vehicle = "));
        QTextStream out(&File);
        while(!out.atEnd())
        {
            line=out.readLine();
            line=line.mid(0,line.length());
            qList=line.split(",");
            z.append(qList[0].toFloat());
            z.append(qList[1].toFloat());
            rowCount++;
        }
        File.close();
    }
    //cout<<z[0]<<" "<<z[1]<<endl;
    int len=z.size();
    //ui->txtXYRadius->appendPlainText(QString::number(len));

    for (int i=0; i<len/2; ++i)
    {
      float first=z[i*2],second=z[i*2+1];
      if(first<100 && second<=15)
      {
          x1.append(first);
          y1.append(second);
      }
      else if(first<100 && second>15)
      {
          x2.append(first);
          y2.append(second);
      }
      else if(first>100 && second<=25)
      {
          x3.append(first);
          y3.append(second);
      }
     else
      {
          x4.append(first);
          y4.append(second);
      }
    }

    ui->label->setText(QString("Cluster 1 \n 41.5019 5.39169 \nCluster 2 \n 57.8807 5.28552\nCluster 3 \n 180.096 18.3079 \nCluster 4 \n 50.6142 33.062 "));


    // create and configure plottables:
    QCPGraph *graph1 = ui->customPlot->addGraph();
     QCPGraph *graph2 = ui->customPlot->addGraph();
      QCPGraph *graph3 = ui->customPlot->addGraph();
       QCPGraph *graph4 = ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::yellow , 0.5), QBrush(Qt::yellow), 9));
    graph1->setPen(Qt::NoPen);

    graph2->setData(x2, y2);
    graph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::blue, 0.5), QBrush(Qt::blue), 9));
    graph2->setPen(Qt::NoPen);

    graph3->setData(x3, y3);
    graph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::green, 0.5), QBrush(Qt::green), 9));
    graph3->setPen(Qt::NoPen);

    graph4->setData(x4, y4);
    graph4->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::red, 0.5), QBrush(Qt::red), 9));
    graph4->setPen(Qt::NoPen);

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::black, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));

    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    ui->customPlot->rescaleAxes(true);
}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    plotraw();
    ui->customPlot->replot();
}

void MainWindow::on_pushButton_8_clicked()
{
   // call_kmeans();
    plotClusters();
    ui->customPlot->replot();
}

void MainWindow::on_pushButton_6_clicked()
{
    filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Open Dataset"),
                    "/home/",
                    tr("Csv file (*.csv)"));
}
