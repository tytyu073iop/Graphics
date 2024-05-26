#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // views
    QMenuBar* menuBar;
    QMenu* fileMenu;
    QAction* saveAction;
    QAction* loadAction;
    QMenu* AboutMenu;
    QAction* about;
    QAction* colorAction;
    QAction* sizeAction;
    // end

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void aboutTrigger();
};
#endif // MAINWINDOW_H
