#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets/QMainWindow>   // 主窗口类
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>  // 场景类
#include <QtWidgets/QGraphicsView>  // 视图类
#include <QtGUI/QPixmap>  // 图片类
#include <QtWidgets/QGraphicsPixmapItem>  // 图片项类
#include <QtGUI/QKeyEvent>  // 键盘事件类
#include <QtWidgets/QPushButton>  // 按钮类
#include <QtWidgets/QLabel>  // 标签类
#include <QtWidgets/QMessageBox>  // 消息框类
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGUI/QPainter>
#include <QtCore/QString>

#include <string>
#include <map>
#include <set>

const int mapSize = 20;  // 地图大小



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* event);

    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(scene, this);

    void onNextBtnClicked();
    void onRestartBtnClicked();
    void onPreBtnClicked();

private:
    void InitGame();
    bool isSuccessful();
    void checkGame();
    int round;
    int step;
    const QString title = "推箱子游戏";

    int map[mapSize][mapSize];
    QGraphicsPixmapItem* mapItem[20][20];
    QGraphicsPixmapItem* wallItem[20][20];
    QGraphicsPixmapItem* playerItem;
    QGraphicsPixmapItem* boxItem[10];
    QGraphicsPixmapItem* finalItem[10];

    QPixmap wallPixmap;
    QPixmap aimPixmap;
    QPixmap blockPixmap;
    QPixmap boxPixmap;
    QPixmap upPixmap;
    QPixmap downPixmap;
    QPixmap rightPixmap;
    QPixmap leftPixmap;

    QLabel* roundLabel;
    QLabel* stepLabel;

    QPushButton* nextBtn;
    QPushButton* restartBtn;
    QPushButton* preBtn;
};


#endif