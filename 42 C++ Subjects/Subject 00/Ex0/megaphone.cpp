#include <iostream>
int main(int argc, char *argv[])
{
    if (argc <= 1 || argv == nullptr)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] >= 97 && argv[i][j] <= 122)
                std::cout << (char)(argv[i][j] - 32);
            else
                std::cout << argv[i][j];
            j++;
        }
    }
    return 0;
}