#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring>
using namespace std;

int main()
{
    string w = "";
    char ch;
    while(1)
    {
        system("CLS");
        cout<<w;
        ch = char(getch());
        if(int(ch) == 8)
        {
            string x = "";
            for(int i=1;i<w.length();i++)
            {
                x = x + w[i];
            }
            w = x;
        }
        else
            w = ch + w;
    }
    return 0;
}
