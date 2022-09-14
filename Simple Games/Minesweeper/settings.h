#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
    public:
        int xSize;
        int ySize;
        int blockSize;
    
    public:
        Settings(int x, int y, int bSize);
        ~Settings();
};

#endif