#include "Mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , blockPixmap(":/image/block.png")
    , boxPixmap(":/image/box.png")
    , wallPixmap(":/image/wall.png")
    , aimPixmap(":/image/ball.png")
    , upPixmap(":/image/up.png")
    , downPixmap(":/image/down.png")
    , rightPixmap(":/image/right.png")
    , leftPixmap(":/image/left.png")
{
    round = 1;
    

    roundLabel = new QLabel(this);
    //roundLabel->setAlignment(Qt::AlignCenter);
    
    stepLabel = new QLabel(this);
    
    this->setWindowTitle(title);
    InitGame();

    nextBtn = new QPushButton(QString("下一关"), this);
    restartBtn = new QPushButton(QString("重新开始"), this);
    preBtn = new QPushButton(QString("上一关"), this);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(preBtn);
    buttonLayout->addWidget(restartBtn);
    buttonLayout->addWidget(nextBtn);

    QHBoxLayout* textLayout = new QHBoxLayout;
    textLayout->addWidget(roundLabel);
    textLayout->addWidget(stepLabel);

    // 创建垂直布局，将游戏界面和按钮放置在其中
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(buttonLayout);

    // 设置布局为MainWindow的中心部件
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);



    connect(nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));
    connect(restartBtn, SIGNAL(clicked()), this, SLOT(onRestartBtnClicked()));
    connect(preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));

}

void MainWindow::InitGame() {
    step = 0;
    playerItem = new QGraphicsPixmapItem(downPixmap);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            mapItem[i][j] = new QGraphicsPixmapItem(blockPixmap);
            mapItem[i][j]->setZValue(0);
            // 设置图片项的位置
            mapItem[i][j]->setPos(j * 35, i * 35);
            // 将图片项添加到场景中
            scene->addItem(mapItem[i][j]);
            if (map[i][j] == 1)  // 该位置有墙
            {
                wallItem[i][j] = new QGraphicsPixmapItem(wallPixmap);
                wallItem[i][j]->setZValue(1);
                wallItem[i][j]->setPos(j * 35, i * 35);
                scene->addItem(wallItem[i][j]);
            }

        }
    }
    // 设置人物的初始位置
    playerItem->setPos(40, 40);
    // 将人物添加到场景中
    roundLabel->setText(QString("第1关"));
    stepLabel->setText(QString("移动次数：0"));
    scene->addItem(playerItem);
    // 将视图设置为MainWindow的中心部件
    repaint();
}

bool MainWindow::isSuccessful() {
    
}

void MainWindow::checkGame() {
    repaint();
    stepLabel->setText(QString("移动次数："+step));
    if (isSuccessful()) {
        round++;
        InitGame();
    }
}

MainWindow::~MainWindow() {
    delete preBtn;
    delete restartBtn;
    delete nextBtn;
    delete roundLabel;
    delete stepLabel;
}

void MainWindow::paintEvent(QPaintEvent*) {

}

void MainWindow::mousePressEvent(QMouseEvent* event) {

}

void MainWindow::keyPressEvent(QKeyEvent* e) {
    switch (e->key()) 
    {
    case Qt::Key_W:
        game->moveUp();
        break;
    case Qt::Key_A:
        game->moveLeft();
        break;
    case Qt::Key_S:
        game->moveDown();
        break;
    case Qt::Key_D:
        game->moveRight();
        break;
    case Qt::Key_Up:
        game->moveUp();
        break;
    case Qt::Key_Left:
        game->moveLeft();
        break;
    case Qt::Key_Down:
        game->moveDown();
        break;
    case Qt::Key_Right:
        game->moveRight();
        break;
    default:
        break;
    }
    // 更新游戏界面
    checkGame();
}

void MainWindow::onNextBtnClicked(){
    round++;
	InitGame();
}

void MainWindow::onRestartBtnClicked() {
    InitGame();
}


void MainWindow::onPreBtnClicked() {
    round--;
    InitGame();
}

