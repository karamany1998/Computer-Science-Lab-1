#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include "map.h"
#include "mapio.h"
#include "dialog.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "dialogstreet.h"


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
    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_2_clicked();

    //void on_TestDrawCity_clicked();

    //void on_pushButton_3_clicked();

    void on_mapDrawTest_clicked();

    void on_streetDrawTest_clicked();


    void on_checkBox_clicked();

    void on_pushButton_3_clicked();

    void on_fillMap_clicked();

    void on_pushButton_4_clicked();

    void on_testAbstractMap_clicked();

    void on_testDijkstra_clicked();

    void on_runDijkstra_clicked();

    void on_addStreet_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsRectItem rectangle;
    Map map;
    MapIo* mapIO;
};

#endif // MAINWINDOW_H
