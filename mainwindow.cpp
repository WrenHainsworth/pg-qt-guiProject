#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("playground");
    db.setUserName("postgres");
    db.setPassword("");
    if (db.open()){
        qDebug() << "Connected";
    } else{
        qDebug() << "Failed";
    }

    QBarSet *set0 = new QBarSet("User1");
    QBarSet *set1 = new QBarSet("User2");
    QBarSet *set2 = new QBarSet("User3");
    QBarSet *set3 = new QBarSet("User4");
    QBarSet *set4 = new QBarSet("User5");

    *set0 << 10 << 20 << 30 << 40 << 50 << 60;
    *set1 << 50 << 70 << 40 << 45 << 80 << 70;
    *set2 << 30 << 50 << 80 << 13 << 80 << 50;
    *set3 << 50 << 60 << 70 << 30 << 40 << 25;
    *set4 << 90 << 70 << 50 << 30 << 16 << 42;

    QBarSeries *seriesBar = new QBarSeries();
    seriesBar->append(set0);
    seriesBar->append(set1);
    seriesBar->append(set2);
    seriesBar->append(set3);
    seriesBar->append(set4);

    QChart *chartBar = new QChart();
    chartBar->addSeries(seriesBar);
    chartBar->setTitle("Chart Title");
    chartBar->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "June";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chartBar->createDefaultAxes();
    chartBar->setAxisX(axis,seriesBar);

    chartViewBar = new QChartView(chartBar);
    chartViewBar->setRenderHint(QPainter::Antialiasing);
    chartViewBar->setParent(ui->chart1);

    QPieSeries *seriesPie = new QPieSeries();
    seriesPie->append("User1", 10);
    seriesPie->append("User2", 20);
    seriesPie->append("User3", 30);
    seriesPie->append("User4", 40);
    seriesPie->append("User5", 50);

    QPieSlice *slice = seriesPie->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chartPie = new QChart();
    chartPie->addSeries(seriesPie);
    chartPie->setTitle("Pie Chart Title");

    chartViewPie = new QChartView(chartPie);
    chartViewPie->setRenderHint(QPainter::Antialiasing);
    chartViewPie->setParent(ui->chart2);


   QLineSeries *seriesLine = new QLineSeries();
   seriesLine->append(0,6);
   seriesLine->append(2,4);
   seriesLine->append(3,8);
   seriesLine->append(7,4);
   seriesLine->append(10,5);
   seriesLine->append(11,10);
   seriesLine->append(13,3);
   seriesLine->append(17,6);
   seriesLine->append(18,3);
   seriesLine->append(20,2);

   QChart *chartLine = new QChart();
   chartLine->addSeries(seriesLine);
   chartLine->createDefaultAxes();
   chartLine->setTitle("Line chart title");

   chartViewLine = new QChartView(chartLine);
   chartViewLine->setRenderHint(QPainter::Antialiasing);
   chartViewLine->setParent(ui->chart3);


}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    chartViewBar->resize(chartViewBar->parentWidget()->size());
    chartViewPie->resize(chartViewPie->parentWidget()->size());
    chartViewLine->resize(chartViewLine->parentWidget()->size());
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();
    QString password = ui->passwordInput->text();
    qDebug() << username << password;

    QString command = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "' AND status = 1";
    qDebug() << command;
    QSqlQuery query(db);
    if (query.exec(command)){
        if (query.size() > 0){
            QMessageBox::information(this, "Login success.", "You have successfully logged in");
        }else{
            QMessageBox::information(this, "Login failed.", "Login failed. Please try again");
        }
    }


}



void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1==1){

    }
}

