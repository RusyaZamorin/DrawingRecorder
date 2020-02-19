#ifndef COMMANDDRAWPOINT_H
#define COMMANDDRAWPOINT_H

#include <QPoint>
#include <QColor>
#include <QGraphicsScene>
#include "command.h"

class CommandDrawPoint: public Command
{
public:
    CommandDrawPoint(QGraphicsScene * scene, QPoint coordinates, int radius, QColor color)
    {
        this->color = color;
        this->scene = scene;
        this->radius = radius;
        this->coordinates = coordinates;
    }

    void execute() override
    {
        scene->addEllipse(coordinates.x(),coordinates.y(),radius,radius,Qt::NoPen,QBrush(color));
    }
    void undo() override
    {

    }
private:
    QPoint coordinates;
    QColor color;
    int radius;
    QGraphicsScene *scene;

    ~CommandDrawPoint() override
    {
        delete scene;
    }
};

#endif // COMMANDDRAWPOINT_H
