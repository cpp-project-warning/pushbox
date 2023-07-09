#include "Mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , blockPixmap(":/img/block.png")
    , boxPixmap(":/img/box.png")
    , wallPixmap(":/img/wall.png")
    , aimPixmap(":/img/ball.png")
    , upPixmap(":/img/up.png")
    , downPixmap(":./img/down.png")
    , rightPixmap(":/img/right.png")
    , leftPixmap(":/img/left.png")
{

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 700, 700);
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFrameStyle(0);
    view->setSceneRect(0, 0, 700, 700);


    round = 1;
    step = 0;
    roundLabel = new QLabel(this);
    //roundLabel->setAlignment(Qt::AlignCenter);
    stepLabel = new QLabel(this);
    
    this->setWindowTitle(title);
    setDirection(Down);
    LoadGame();

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


void MainWindow::LoadGame() {
    setviewMap();
    int aimiter = 0; 
    int boxiter = 0;
    scene->clear();
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            mapItem[i][j] = new QGraphicsPixmapItem(blockPixmap);
            mapItem[i][j]->setZValue(0);
            mapItem[i][j]->setPos(j * 35, i * 35);
            scene->addItem(mapItem[i][j]);
            if (viewMap[i][j] & 1)  // 该位置有墙
            {
                wallItem[i][j] = new QGraphicsPixmapItem(wallPixmap);
                wallItem[i][j]->setZValue(1);
                wallItem[i][j]->setPos(j * 35, i * 35);
                scene->addItem(wallItem[i][j]);
            }
            if (viewMap[i][j] & 2) {  // 该位置有目标
                aimItem[aimiter] = new QGraphicsPixmapItem(aimPixmap);
                aimItem[aimiter]->setZValue(1);
				aimItem[aimiter]->setPos(j * 35, i * 35);
				scene->addItem(aimItem[aimiter]);
				aimiter++;
            }
            if (viewMap[i][j] & 4) {  // 该位置有box
                boxItem[boxiter] = new QGraphicsPixmapItem(boxPixmap);
                boxItem[boxiter]->setZValue(1);
                boxItem[boxiter]->setPos(j * 35, i * 35);
                scene->addItem(boxItem[boxiter]);
                aimiter++;
            }
            if(viewMap[i][j] & 8) {  // 该位置有人
				playerItem = new QGraphicsPixmapItem(playerPixmap);
				playerItem->setZValue(1);
				playerItem->setPos(j * 35, i * 35);
				scene->addItem(playerItem);
			}
        }
    }
    roundLabel->setText(QString("第" + QString::number(round) + "关"));
    stepLabel->setText(QString("移动次数："+step));
    repaint();
}

bool MainWindow::isSuccessful() {
    if (1) {
        return true;
    }
	else {
		return false;
	}
}

void MainWindow::checkGame() {
    if (isSuccessful()) {
        QMessageBox::information(this, tr("Congratulations"), tr("You have completed this level!"));
        if(round<roundNum)
            round++;
        else
            round = 1;
    }
    LoadGame();
}

void MainWindow::setviewMap() {
    int**wall = vm->get_wall();
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            viewMap[i][j] = wall[i][j];
        }
    }
    std::set<Box> box = vm->get_all_box();
    box_num = box.size();
    for (auto it = box.begin(); it != box.end(); it++) {
		viewMap[it->get_position().x][it->get_position().y] += 4;
	}
	std::set<position> aim = vm->get_destination();
    for (auto it = aim.begin(); it != aim.end(); it++) {
		viewMap[it->x][it->y] += 2;
	}
    Player player = vm->get_player();
	viewMap[player.get_position().x][player.get_position().y] += 8;
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
        if (vm->move_operation(Up))
            step++;
        setDirection(Up);
        break;
    case Qt::Key_A:
        if(vm->move_operation(Left))
			step++;
        setDirection(Left);
        break;
    case Qt::Key_S:
        if (vm->move_operation(Down))
            step++;
        setDirection(Down);
        break;
    case Qt::Key_D:
        if (vm->move_operation(Right))
            step++;
        setDirection(Right);
        break;
    case Qt::Key_Up:
        if (vm->move_operation(Up))
            step++;
        setDirection(Up);
        break;
    case Qt::Key_Left:
        if (vm->move_operation(Left))
            step++;
        setDirection(Left);
        break;
    case Qt::Key_Down:
        if (vm->move_operation(Down))
            step++;
        setDirection(Down);
        break;
    case Qt::Key_Right:
        if (vm->move_operation(Right))
            step++;
        setDirection(Right);
        break;
    default:
        break;
    }
    // 更新游戏界面
    checkGame();
}

void MainWindow::onNextBtnClicked(){
    if (round < roundNum)
        round++;
    else
        round = 1;
    setDirection();
	LoadGame();
}

void MainWindow::onRestartBtnClicked() {
    setDirection();
    LoadGame();
}


void MainWindow::onPreBtnClicked() {
    if (round > 1)
        round --;
    else
        round = roundNum;
    setDirection();
    LoadGame();
}

void MainWindow::setDirection(direction d = Down) {
    if(d == Up)
		playerPixmap = upPixmap;
	else if(d == Down)
		playerPixmap = downPixmap;
	else if(d == Left)
		playerPixmap = leftPixmap;
	else if(d == Right)
		playerPixmap = rightPixmap;
	else
		playerPixmap = downPixmap;
}