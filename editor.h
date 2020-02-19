#ifndef EDITOR_H
#define EDITOR_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "commanddrawpoint.h"
#include "command.h"
#include <QDebug>

class Editor : public QGraphicsScene
{
public:
    Editor(QObject *parent,QGraphicsView *graphicsView);
    QVector<Command*> GetCommandsDrawList();
    void SetPointRadius(int radius);
    void SetColor(QColor color);
    void ChangeStateCanDraw(bool state);
    void ClearScene();
    void ClearCommandList();
private:
    int pointRadius = 10;
    QColor color = Qt::black;
    bool stateCanDraw = true;
    QGraphicsView *graphicsView;
    QVector<Command*> commandsDrawList;

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void DrawPoint(QPoint coord);

};

#endif // EDITOR_H
