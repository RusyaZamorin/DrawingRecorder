#include "editor.h"


Editor::Editor(QObject *parent, QGraphicsView *graphicsView): QGraphicsScene(parent)
{
    this->graphicsView = graphicsView;
    graphicsView->setScene(this);
    setSceneRect(graphicsView->rect());

}



QVector<Command *> Editor::GetCommandsDrawList()
{
    return commandsDrawList;
}

void Editor::SetPointRadius(int radius)
{
    pointRadius = radius;
}

void Editor::SetColor(QColor color)
{
    this->color = color;
}

void Editor::ChangeStateCanDraw(bool state)
{
    stateCanDraw = state;
}

void Editor::ClearScene()
{
    clear();
}

void Editor::ClearCommandList()
{
    commandsDrawList.clear();
}

void Editor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    DrawPoint(event->scenePos().toPoint()+ QPoint(-3,-3));

}

void Editor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    DrawPoint(event->scenePos().toPoint()+ QPoint(-3,-3));
}



void Editor::DrawPoint(QPoint coord)
{
    if(!stateCanDraw)
        return;
    commandsDrawList.push_back(new CommandDrawPoint(this, coord, pointRadius, color));
    commandsDrawList.last()->execute();
}



