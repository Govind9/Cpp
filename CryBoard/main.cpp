#define WINVER 0x0500
#include <windows.h>
#include <Winuser.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
void hide()
{
    HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
}
void presskey(int k)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = k;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}
int main()
{
    //hide();
    string x;
    x = "qwertyuioplkjhgfdsazxcvbnm1234567890";

    while(1)
    {
        for(int i=8;i<=190;i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
               // cout<<i;
                if(i!=8 && i!=13)
                {
                    presskey(8);
                    int h;
                    h = (rand()%95)+32;
                    cout<<h<<endl;
                    presskey(h);
                }
            }
        }
    }
    return 0;
}
