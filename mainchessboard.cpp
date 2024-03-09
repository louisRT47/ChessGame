#include "mainchessboard.h"
#include "ui_mainchessboard.h"

MainChessBoard::MainChessBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainChessBoard)
{
    ui->setupUi(this);
}

MainChessBoard::~MainChessBoard()
{
    delete ui;
}
