#include "settings.h"

Settings::Settings(int x, int y, int bSize)
{
    xSize = x;
    ySize = y;
    blockSize = bSize;
    blockAmount = 50;
}

Settings::~Settings()
{

}