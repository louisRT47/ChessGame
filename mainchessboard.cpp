#include "mainchessboard.h"
#include "ui_mainchessboard.h"
#include <QMediaPlayer>
#include <QAudioOutput>


/*      First Constructor      */
MainChessBoard::MainChessBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainChessBoard)
{
    ui->setupUi(this);

    //Background color using-CSS Style
    //this->setStyleSheet("background-color: #FAFAFA; border: none; QMainWindow::title { background-color: #FF0000; }"); // Blue dim color

    QPixmap bkgnd("/home/luisr/Documents/Projects/ChessGame/backgroundImage-chess.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    // Change the color of the title bar (window frame) for Windows
    this->setStyleSheet("QMainWindow::title { background-color: #FF0000; }");

    // Set the fixed size for the window
    setFixedSize(1000, 550); // Set your desired width and height

    // Initialize the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    // Start the timer when the window opens
    connect(this, SIGNAL(windowShown()), this, SLOT(startTimer()));
    // Stop the timer when the window is closed
    connect(this, SIGNAL(windowClosed()), this, SLOT(stopTimer()));

    // Inital Buttons
    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playNewGame()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quitGame()));
    ui->playButton->setStyleSheet("border-radius: 3px; background-color: #D2CAB6;");
    ui->quitButton->setStyleSheet("border-radius: 3px; background-color: #D2CAB6;");

    // Background Music
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    //player->setSource(QUrl::fromLocalFile("/home/luisr/Documents/Projects/ChessGame/Pirates Of The Caribbean Theme Song.mp3"));
    player->setSource(QUrl::fromLocalFile("/home/luisr/Documents/Projects/ChessGame/theme music.mp3"));
    player->setLoops(-1);
    player->play();


}

void MainChessBoard::startTimer()
{
    // Start the timer to update the LCD every second
    timer->start(1000);
    ui->lcdNumber->setStyleSheet("background-color: #D2CAB6;");
}

void MainChessBoard::stopTimer()
{
    // Stop the timer when the window is closed
    timer->stop();
}

void MainChessBoard::updateTime()
{
    // Increment the seconds count
    seconds++;

    if (seconds > 59) {
        int minutes = seconds / 60;
        int remainingSeconds = seconds % 60;

        // Format display minutes:seconds
        ui->lcdNumber->display(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(remainingSeconds, 2, 10, QChar('0')));
    } else {
        // Update the LCD number to display seconds only
        ui->lcdNumber->display(seconds);
    }
}

void MainChessBoard::showEvent(QShowEvent *event)
{
    // Emit the signal to start the timer when the window is shown
    emit windowShown();
    QMainWindow::showEvent(event);
}

void MainChessBoard::closeEvent(QCloseEvent *event)
{
    // Emit the signal to stop the timer when the window is closed
    emit windowClosed();
    QMainWindow::closeEvent(event);
}

void MainChessBoard::playNewGame()
{
    // Implement functionality to start a new game
}

void MainChessBoard::cleanup()
{
    if (player) {
        player->stop();
        delete player;
        player = nullptr;
    }
}

void MainChessBoard::quitGame()
{
    stopTimer();
    cleanup();
    close();
}

/*      Destructor      */
MainChessBoard::~MainChessBoard()
{
    delete ui;
}
