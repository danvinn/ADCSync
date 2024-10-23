#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QMainWindow>
#include <QTimer>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class landingPage;
}
QT_END_NAMESPACE

class landingPage : public QMainWindow
{
    Q_OBJECT

public:
    landingPage(QWidget *parent = nullptr);
    ~landingPage();

private slots:

    void on_runSensorDiagnostic_clicked();

    void on_startSystem_clicked();

    void on_stopSystem_clicked();

    void on_downloadData_clicked();

    void updateDiagram();

    void clearDiagram();


private:
    Ui::landingPage *ui;
    double time;
    QTimer* myTimer;

};
#endif // LANDINGPAGE_H
