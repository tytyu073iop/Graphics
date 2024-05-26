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
    fileMenu->addAction(loadAction);

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
