#include "mainwindow.h"

inline QIcon getColorIcon(const QColor& color) {
    QPixmap pm(20, 20);
    pm.fill(color);
    QIcon icon(pm);
    return icon;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    menuBar = new QMenuBar();
    setMenuBar(menuBar);
    fileMenu = new QMenu("file");
    AboutMenu = new QMenu("about");
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(AboutMenu);
    saveAction = new QAction("save");
    loadAction = new QAction("load");
    about = new QAction("about");
    connect(about, SIGNAL(triggered(bool)), this, SLOT(aboutTrigger()));
    AboutMenu->addAction(about);
    menuBar->addAction(about);
    fileMenu->addAction(saveAction);
    connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(saveTrigger()));
    fileMenu->addAction(loadAction);
    connect(loadAction, SIGNAL(triggered(bool)), this, SLOT(loadTrigger()));

    // toolbar
    toolBar = new QToolBar("properties");
    addToolBar(toolBar);
    colorAction = new QAction(getColorIcon(Qt::black), "color");
    toolBar->addAction(colorAction);

    // sizeMenu
    sizeMenu = new QMenu("size");
    ag = new QActionGroup(this);
    for (int i = 1; i <= 10; ++i) {
        QAction* action = new QAction(QString::number(i));
        action->setCheckable(true);
        if (i == 1) { action->setChecked(true); }
        ag->addAction(action);
        sizeMenu->addAction(action);

    }
    updateState();
    connect(sizeMenu, SIGNAL(triggered(QAction*)), this, SLOT(updateState()));

    // view
    QChart* chart = new QChart();
    chart->setBackgroundPen(QPen(Qt::blue));
    chart->setBackgroundBrush(QBrush(Qt::yellow));
    chart->setPlotAreaBackgroundPen(QPen(Qt::black));
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    QBarSeries* bs = new QBarSeries;
    bs->setBarWidth(1/qreal(10));
    QBarSet* bSet = new QBarSet("schools");
    bSet->append(3);
    bSet->append(5);
    bs->append(bSet);
    QBarSet* bSet2 = new QBarSet("vans");
    bSet2->append(1);
    bSet2->append(2);
    bs->append(bSet2);
    chart->addSeries(bs);
    QBarCategoryAxis* bca = new QBarCategoryAxis;
    chart->addAxis(bca, Qt::AlignBottom);
    bs->attachAxis(bca);
    // bca->append("skibidi");
    // bca->append("rizz");
    // bca->append("6");
    QValueAxis* va = new QValueAxis;
    // va->setMax(10);
    // va->setMin(-10);
    // va->setTickCount(5);
    // va->setTickInterval(3);
    chart->addAxis(va, Qt::AlignLeft);
    bs->attachAxis(va);
    QChartView* cv = new QChartView(chart);
    setCentralWidget(cv);

}

MainWindow::~MainWindow() {}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    sizeMenu->exec(event->globalPos());
}

void MainWindow::aboutTrigger()
{
    QMessageBox msgBox;
    msgBox.setText("Бирюк Илья Александрович\n11 группа\n0 Вариант");
    msgBox.setWindowTitle("О программе");
    msgBox.exec();
}

void MainWindow::updateState()
{
    QStatusBar* sb = new QStatusBar;
    setStatusBar(sb);
    QString size = ag->checkedAction() == nullptr ? "error" : ag->checkedAction()->text();
    sb->addWidget(new QLabel("size: " + size));
}

void MainWindow::saveTrigger()
{
    QFileDialog fd;
    fd.setDefaultSuffix("png");
    fd.setAcceptMode(QFileDialog::AcceptSave);
    if (fd.exec()) {
        qDebug() << fd.selectedFiles();
        // QPixmap pm = QPixmap::grabWidget(this->centralWidget());
        // pm.save(fd.selectedFiles()[0]);
        this->centralWidget()->grab().save(fd.selectedFiles()[0]);
    }
}

void MainWindow::loadTrigger()
{
    QString path = QFileDialog::getOpenFileName(this, "", "", "*.txt");
    if (path.isEmpty()) { return; }
    QFile* file = new QFile(path);
    file->open(QIODeviceBase::ReadOnly);
    QTextStream ts(file);
    QString timeS = ts.readAll();
    std::string str = timeS.toStdString();
    std::stringstream ss(str);
    while (ss.peek() != EOF) {
        std::string one;
        std::getline(ss, one, ';');
        qDebug() << one;
        std::string two;
        std::getline(ss, two);
        qDebug() << two;
    }
}
