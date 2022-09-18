#ifndef SNAKE_H
#define SNAKE_H

#include "enums.h"
#include "raylib.h"
#include "candy.h"
#include <iostream>

struct SnakeBlock
{
    Rectangle snakePart;
    SnakeBlock *nextSnakeBlock = nullptr;

    SnakeBlock(int x, int y)
    {
        snakePart = CreateRect(x, y);
    }

    Rectangle CreateRect(int x, int y)
    {
        Rectangle rect = Rectangle();
        rect.x = x;
        rect.y = y;
        rect.width = 10;
        rect.height = 10;
        return rect;
    }

    void DrawHead(int hor, int vert, bool overlapped)
    {
        int currentX = snakePart.x;
        int currentY = snakePart.y;
        snakePart.x += hor;
        snakePart.y += vert;
        LoopPos();
        DrawRectangle(snakePart.x, snakePart.y, snakePart.width, snakePart.height, BLACK);
        if (nextSnakeBlock != nullptr)
            nextSnakeBlock->DrawPart(currentX, currentY, overlapped);
    }

    void DrawStatic()
    {
        DrawRectangle(snakePart.x, snakePart.y, snakePart.width, snakePart.height, BLACK);
        if (nextSnakeBlock != nullptr)
            nextSnakeBlock->DrawStatic();
    }

    void DrawPart(int hor, int vert, bool overlapped)
    {
        int currentX = snakePart.x;
        int currentY = snakePart.y;
        snakePart.x = hor;
        snakePart.y = vert;
        DrawRectangle(snakePart.x, snakePart.y, snakePart.width, snakePart.height, BLACK);
        if (nextSnakeBlock != nullptr)
            nextSnakeBlock->DrawPart(currentX, currentY, overlapped);
        if (nextSnakeBlock == nullptr && overlapped)
            nextSnakeBlock = new SnakeBlock(currentX, currentY);
    }

    bool CheckPos()
    {
        return (snakePart.x < 0 || snakePart.x >= 600 || snakePart.y < 0 || snakePart.y >= 300);
    }

    void LoopPos()
    {
        if (snakePart.x < 0)
            snakePart.x = 590;
        if (snakePart.x >= 600)
            snakePart.x =0;
        if (snakePart.y < 0)
            snakePart.y = 290;
        if (snakePart.y >= 300)
            snakePart.y = 0;
    }
};

class Snake
{
    public:
        Snake();
        ~Snake();
        void SetMoveDir(KeyboardKey key);
        void PaintSnake(Candy *candy);
        void SetSpeed(int toSet);
        int GetSpeed();

    private:
        SnakeBlock *snake = nullptr;
        Movement moveDir = RIGHT;
        int speed = 5;
        int currentSize = 5;
        bool OverlapCandy(Candy *candy);
};

inline void Snake::SetSpeed(int toSet)
{
    if (toSet >= 1)
        speed = toSet;
}

inline int Snake::GetSpeed()
{
    return speed;
}

inline Snake::Snake()
{
    snake = new SnakeBlock(150, 140);
    snake->nextSnakeBlock = new SnakeBlock(140, 140);
    snake->nextSnakeBlock->nextSnakeBlock = new SnakeBlock(130, 140);
    snake->nextSnakeBlock->nextSnakeBlock->nextSnakeBlock = new SnakeBlock(120, 140);
}

#endif