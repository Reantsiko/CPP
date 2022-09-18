#ifndef CANDY_H
#define CANDY_H

#include "raylib.h"

class Candy
{
    public:
        Candy();
        // ~Candy();
        void PaintCandy();
        Rectangle GetRect();

    private:
        Rectangle rect;
};

#endif