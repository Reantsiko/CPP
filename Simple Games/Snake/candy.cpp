#include "candy.h"
#include <iostream>
#include "math.h"

Candy::Candy()
{
    std::srand(time(0));
    rect = Rectangle();
    int x = rand() % 590;
    int y = rand() % 290;
    float remainderX = x % 10;
    float remainderY = y % 10;
    x += (10 - remainderX);
    y += (10 - remainderY);
    rect.x = x;
    rect.y = y;
    rect.width = 10;
    rect.height = 10;
}

void Candy::PaintCandy()
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, RED);
}

Rectangle Candy::GetRect()
{
    return rect;
}