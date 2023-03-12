#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <conio.h>
using namespace std;

class RapidFire
{
public:
    RapidFire();
    void StartRapidFire();
    void EndRapidFire();

private:
    void Obfuscate();
    void SendMouseInput();
};

RapidFire::RapidFire()
{
}

void RapidFire::StartRapidFire()
{

    while(true)
    {
        if (GetAsyncKeyState(VK_RBUTTON) != 0)
        {
            Obfuscate();
            SendMouseInput();
        }
    }
}

void RapidFire::EndRapidFire()
{
}

void RapidFire::Obfuscate()
{
    int v[256] = { 0 };
    std::string s = "SomeRandomString";

    for (int i = 0; i < s.length(); i++) {
        v[i] = (unsigned char)s[i];
    }

    auto seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(v), std::end(v), std::default_random_engine(seed));

    std::string t(v, v + s.length());

    std::cout << t << std::endl;
}


void RapidFire::SendMouseInput()
{
    INPUT Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &Input, sizeof(INPUT));

    ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
    RapidFire rf;

    rf.StartRapidFire();
    
    
    rf.EndRapidFire();

    std::cout << "Press any key to exit the program..." << std::endl;
    while (!_kbhit()) {
        Sleep(100);
    }

    return 0;
}