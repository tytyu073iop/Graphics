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
#include <QRadioButton>
#include <QButtonGroup>
#include <QActionGroup>
#include <QContextMenuEvent>
#include <QStatusBar>
#include <QLabel>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QFileDialog>
#include <QTextStream>
#include <sstream>
#include <string>

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
    QAction* colorAction;
    QMenu* sizeMenu;
    // QButtonGroup* bg;
    QActionGroup* ag;
    // end

    //properties
    QColor color;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void contextMenuEvent(QContextMenuEvent *event);

public slots:
    void aboutTrigger();
    void updateState();
    void saveTrigger();
    void loadTrigger();
};
#endif // MAINWINDOW_H
