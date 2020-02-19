#include "handinginput.h"
#include "ui_mainwindow.h"

HandingInput::HandingInput(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    editor = new Editor(this,ui->graphicsView);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    player = new CommandPlayer(timer);

}

HandingInput::~HandingInput()
{
    delete ui;
}

void HandingInput::Update()
{
    if(player->PlayCommandList())
    {
        ui->progressBar_Recoding_Progress->setValue(player->GetCurrentCommandIndex());
    }
    else
    {
        editor->ChangeStateCanDraw(true);
        ui->progressBar_Recoding_Progress->setValue(false);
    }

}


void HandingInput::on_pushButton_Play_Recoding_clicked()
{
    editor->ClearScene();
    editor->ChangeStateCanDraw(false);

    player->SetCommandList(editor->GetCommandsDrawList());
    ui->progressBar_Recoding_Progress->setRange(0,player->GetSizeCommandLIst()-1);
    player->Play();

}

void HandingInput::on_pushButton_Pause_Recoding_clicked()
{
    player->PauseOnOf();
}

void HandingInput::on_pushButton_Stop_Recoding_clicked()
{
    player->Stop();
}

void HandingInput::on_horizontalSlider_Speed_Recoding_valueChanged(int value)
{
    player->SetSpeed(30 - value);
}

void HandingInput::on_pushButton_Clear_clicked()
{
    editor->ClearScene();
    editor->ClearCommandList();
    player->ClearCommandList();
}

void HandingInput::on_spinBox_valueChanged(int arg1)
{
    editor->SetPointRadius(arg1);
}

void HandingInput::on_pushButton_SetColor_clicked()
{
    editor->SetColor(QColorDialog::getColor(Qt::black));
}
