#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QComboBox>
#include <QColor>
#include <QPixmap>

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
    QToolBar* toolBar;
    QComboBox* comboBox;
    QAction* colorAction;
    // end

    //properties
    QColor color;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void aboutTrigger();
};
#endif // MAINWINDOW_H
