#ifndef COMANDPLAYER_H
#define COMANDPLAYER_H

#include "command.h"
#include "QTimer"
#include <QVector>

class CommandPlayer: public QObject
{
private:
    int speed = 10;
    bool statePlay = false;
    int currentCommandIndex = 0;
    QTimer *timer;
    QVector<Command*> commandList;
    ~CommandPlayer();

public:
    CommandPlayer(QTimer *timer);
    void SetCommandList(QVector<Command*> commandList);
    void ClearCommandList();
    void ChangeSpeed(int change);
    void SetSpeed(int speed);

    void Play();
    void Stop();
    void PauseOnOf();

    void ChangeStatePlay(bool state);
    int GetCurrentCommandIndex();
    int GetSizeCommandLIst();
    bool PlayCommandList(); // return index next command for play

};

#endif // COMANDPLAYER_H
