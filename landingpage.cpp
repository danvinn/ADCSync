#include "landingpage.h"
#include "ui_landingpage.h"
#include <random>
#include <QmessageBox>

landingPage::landingPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::landingPage)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();

    ui->plot->graph(0)->setPen(QPen(Qt::red));
    ui->plot->graph(1)->setPen(QPen(Qt::blue));
    ui->plot->graph(2)->setPen(QPen(Qt::green));

    ui->plot->xAxis->setLabel("Time (t)");
    ui->plot->xAxis->setRange(0,70);
    ui->plot->yAxis->setLabel("Angular Momentum (ω)");
    ui->plot->yAxis->setRange(-1,2);

}

landingPage::~landingPage()
{
    delete ui;
}


void landingPage::on_runSensorDiagnostic_clicked()
{
    QMessageBox::information(this,"Sensor Diagnostics","Verifying checksum..");
}


void landingPage::on_startSystem_clicked()
{

    time = 0.0;

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout,this, &landingPage::updateDiagram);
    myTimer->start(250);

}

void landingPage::on_stopSystem_clicked()
{
    clearDiagram();
    if(myTimer){
        myTimer->stop();
        delete myTimer;
        myTimer = nullptr;
    }
}


void landingPage::on_downloadData_clicked()
{
    QMessageBox::information(this,"Data Download","Dowloading 'CCT.csv'...");
}

void landingPage::updateDiagram()
{
    time += 5;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double>dist6(0,1);

    ui->plot->graph(0)->addData(time,dist6(rng));
    ui->plot->graph(1)->addData(time,dist6(rng));
    ui->plot->graph(2)->addData(time,dist6(rng));

    if(time > 60)
        ui->plot->xAxis->setRange(time - 60, time + 10);
    ui->plot->replot();
}

void landingPage::clearDiagram()
{
    ui->plot->graph(0)->setData(QVector<double>(), QVector<double>());

    ui->plot->xAxis->setRange(0, 500);
    ui->plot->yAxis->setRange(-1, 2);

    ui->plot->replot();

}



