#include "mainwindow.h"

// inline QIcon

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
    AboutMenu->addAction(about);
    menuBar->addAction(about);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(loadAction);
}

MainWindow::~MainWindow() {}
