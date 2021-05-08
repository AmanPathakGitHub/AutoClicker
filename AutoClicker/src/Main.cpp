
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void LeftClick()
{
    INPUT    Input = { 0 };
    // left down 
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}


int main()
{
	std::cout << "Press Enter to start and press S to stop\n";

	std::cin.get();

	std::this_thread::sleep_for(5s);

	while (1)
	{
        LeftClick();
        

        std::this_thread::sleep_for(125000ns); //1/8th of a milisecond 

        if (GetKeyState('S') & 0x8000)
        {
            break;
        }

        
	}

    std::cout << "Ended\n";
    std::cin.get();
}