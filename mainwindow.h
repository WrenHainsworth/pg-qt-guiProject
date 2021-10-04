#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

#include <QtCharts>
#include <QChartView>

#include <QBarSet>
#include <QBarSeries>

#include <QPieSeries>
#include <QPieSlice>

#include <QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QChartView *chartViewBar;
    QChartView *chartViewPie;
    QChartView *chartViewLine;

protected:
    void resizeEvent(QResizeEvent* event);

};




#endif // MAINWINDOW_H
