#include <iostream>
#include <Windows.h>

// Gets the current color of the terminal and sets the value of ret to be that color in order to reset the color 
bool getCurrentColor(short &ret)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
        return false;
    ret = info.wAttributes;
    return true;
}

int main()
{
    short current;
    getCurrentColor(current);

    for(int i = 0; i < 256; ++i)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        std::cout << "text color in use = " << i << std::endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), current);
	
	std::cin.get();

    return 0;
}