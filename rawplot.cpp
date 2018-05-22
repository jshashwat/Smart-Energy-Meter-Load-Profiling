#include "rawplot.h"
#include "mainwindow.h"
#include<iostream>
using namespace std;
rawplot::rawplot()
{
    QString line;
    int rowCount=0;
    cout<<"fesfs\n";
    QStringList qList;
    QFile File("/home/zero/data_1.csv");
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
    ui->txtXYRadius->appendPlainText(QString::number(len));

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
