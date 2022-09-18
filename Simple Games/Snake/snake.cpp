#include "snake.h"
#include <iostream>

void Snake::SetMoveDir(KeyboardKey key)
{
    switch (key)
    {
        case KEY_W:
            if (moveDir != DOWN)
                moveDir = UP;
            break;
        case KEY_S:
            if (moveDir != UP)
                moveDir = DOWN;
            break;
        case KEY_A:
            if (moveDir != RIGHT)
                moveDir = LEFT;
            break;
        case KEY_D:
            if (moveDir != LEFT)
                moveDir = RIGHT;
            break;
        default:
            break;
    }
}

void Snake::PaintSnake(Candy *candy)
{
    int horizontal = moveDir == LEFT ? -10 : moveDir == RIGHT ? 10 : 0;
    int vertical = moveDir == UP ? -10 : moveDir == DOWN ? 10 : 0;
    if (snake != nullptr)
    {
        // if (snake->CheckPos())
        // {
        //     snake->DrawStatic();
        //     return;
        // }
        bool isOverlapped = false;
        if (candy != nullptr)
            isOverlapped = OverlapCandy(candy);
        snake->DrawHead(horizontal, vertical, isOverlapped);
    }
}

bool Snake::OverlapCandy(Candy *candy)
{
    if (CheckCollisionRecs(snake->snakePart, candy->GetRect()))
    {
        delete(candy);
        candy = new Candy();
        return true;
    }
    return false;
}