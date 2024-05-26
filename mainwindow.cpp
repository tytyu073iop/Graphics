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
}

MainWindow::~MainWindow() {}

void MainWindow::aboutTrigger()
{
    QMessageBox msgBox;
    msgBox.setText("Бирюк Илья Александрович\n11 группа\n0 Вариант");
    msgBox.setWindowTitle("О программе");
    msgBox.exec();
}
