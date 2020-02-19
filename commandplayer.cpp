#include "commandplayer.h"




CommandPlayer::CommandPlayer(QTimer *timer)
{
    this->timer = timer;
    timer->setInterval(speed);
    timer->start();
}

void CommandPlayer::SetCommandList(QVector<Command *> commandList)
{
    this->commandList = commandList;
}

void CommandPlayer::ClearCommandList()
{
    currentCommandIndex = 0;
    commandList.clear();
}

void CommandPlayer::ChangeSpeed(int change)
{
    speed+=change;
}

void CommandPlayer::SetSpeed(int speed)
{
    timer->stop();
    this->speed = speed;
    timer->setInterval(speed);
    timer->start();
}

void CommandPlayer::Play()
{
    if(commandList.isEmpty())
        return;
    currentCommandIndex =0;
    timer->start();
    ChangeStatePlay(true);

}

void CommandPlayer::Stop()
{
    ChangeStatePlay(false);
    for(int i = currentCommandIndex; i< commandList.size(); i++)
    {
        commandList[i]->execute();
    }
    currentCommandIndex =0;
}

void CommandPlayer::PauseOnOf()
{
    if(timer->isActive())
    {
        timer->stop();
    }
    else
    {
        timer->start();
    }


}

void CommandPlayer::ChangeStatePlay(bool state)
{
    statePlay = state;
}


int CommandPlayer::GetCurrentCommandIndex()
{
    return currentCommandIndex;
}

int CommandPlayer::GetSizeCommandLIst()
{
    return commandList.size();
}

bool CommandPlayer::PlayCommandList()
{
    if(statePlay)
    {
        if(!commandList.isEmpty())
        {
            commandList[currentCommandIndex]->execute();
            currentCommandIndex++;
            if(currentCommandIndex>=commandList.size())
            {
                currentCommandIndex=0;
                ChangeStatePlay(false);
            }
        }
        return true;
    }
    return false;
}

CommandPlayer::~CommandPlayer()
{
    commandList.clear();
    delete timer;
}
