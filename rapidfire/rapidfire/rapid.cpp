#include <iostream>
#include <Windows.h>
#include <time.h>
#include <random>

using namespace std;

int qweasd(int qazxsw, int lkjhgfdsa) {
    return rand() % (lkjhgfdsa - qazxsw + 1) + qazxsw;
}

void send_mouse_event(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo)
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = dx;
    input.mi.dy = dy;
    input.mi.mouseData = dwData;
    input.mi.dwFlags = dwFlags;
    input.mi.time = 0;
    input.mi.dwExtraInfo = dwExtraInfo;

    SendInput(1, &input, sizeof(INPUT));
}

int main()
{
    mt19937 generator(time(NULL));
    uniform_int_distribution<int> distribution(-50, 50);

    bool rF = false;
    int aFT = clock();
    int cT = 0;
    bool mD = false;
    int mDn = distribution(generator);
    int mXn = distribution(generator);
    int nMg = distribution(generator);
    int nDl = distribution(generator);

    while (true)
    {
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) rF = true;
        else rF = false;

        if (rF)
        {
            if (!mD)
            {
                mD = true;
                int nX = distribution(generator);
                int nY = distribution(generator);
                nDl = distribution(generator);
                send_mouse_event(MOUSEEVENTF_LEFTUP, nX, nY, 0, 0);
            }

            if (clock() - aFT > qweasd(mDn, mXn))
            {
                mD = false;
                int nX = distribution(generator);
                int nY = distribution(generator);
                send_mouse_event(MOUSEEVENTF_LEFTDOWN, nX, nY, 0, 0);
                aFT = clock() + nDl;
            }
        }
        Sleep(5);
    }

    return 0;
}