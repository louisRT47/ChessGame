#ifndef MAINCHESSBOARD_H
#define MAINCHESSBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainChessBoard;
}
QT_END_NAMESPACE

class MainChessBoard : public QMainWindow
{
    Q_OBJECT

public:
    MainChessBoard(QWidget *parent = nullptr);
    ~MainChessBoard();

private:
    Ui::MainChessBoard *ui;
};
#endif // MAINCHESSBOARD_H
