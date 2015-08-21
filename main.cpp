#include "mainwindow.h"
#include <QApplication>
#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    createGrid(grid, ROWS, COLS);
    return a.exec();
}
