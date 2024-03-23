#ifndef MAINCHESSBOARD_H
#define MAINCHESSBOARD_H

#include <QMainWindow>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

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

signals:
    void timeout();
    void windowShown();
    void windowClosed();
    void clicked();

public slots:
    void startTimer();
    void stopTimer();
    void updateTime();
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void playNewGame();
    void quitGame();
    void cleanup();

private:
    Ui::MainChessBoard *ui;
    QTimer *timer; //declaration of timer as member variable
    int seconds = 0;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

};
#endif // MAINCHESSBOARD_H
