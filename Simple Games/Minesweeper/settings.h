#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
    public:
        int xSize;
        int ySize;
        int blockSize;
        int blockAmount;
    
    public:
        Settings(int x, int y);
        ~Settings();
};

inline Settings::Settings(int x, int y)
{
    xSize = x;
    ySize = y;
    blockSize = 10;
    blockAmount = 50;
}

inline Settings::~Settings()
{

}

#endif