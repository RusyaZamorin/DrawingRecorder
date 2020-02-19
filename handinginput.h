#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editor.h"
#include <QTimer>
#include "commandplayer.h"
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class HandingInput : public QMainWindow
{
    Q_OBJECT

public:
    HandingInput(QWidget *parent = nullptr);
    ~HandingInput();

private slots:


    void Update();
    void on_pushButton_Play_Recoding_clicked();

    void on_pushButton_Pause_Recoding_clicked();

    void on_pushButton_Stop_Recoding_clicked();

    void on_horizontalSlider_Speed_Recoding_valueChanged(int value);

    void on_pushButton_Clear_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_SetColor_clicked();

private:
    Ui::MainWindow *ui;
    Editor *editor;
    CommandPlayer *player;
    QTimer *timer;
};
#endif // MAINWINDOW_H
