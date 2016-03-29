#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string symbol[100];
int address[100];
string value [70];

void display(int j)
{
    cout<<"Symbol:";
    cout.width(10);
    int z;
    cout<<"address";cout.width(10);cout<<"value"<<endl;
    for(int i = 0;i<=j;i++)
    {
        z=24-symbol[i].length();
        cout<<symbol[i];cout.width(z-10);cout<<address[i];cout.width(10);cout<<value[i]<<endl;
    }
}
int main()
{
    int j=0,addre = 1;
    string ch,word;
    fstream f("ABC.txt");

      while(!f.eof())
    {
        f>>ch;
        if(ch=="start")
        {
           f>>addre;
        }

        if(ch == "DS" || ch == "ds")
        {
             symbol[j]=word;

             f>>ch;
             value[j] = ch;
             j++;

        }
           if(ch == "DC" || ch == "dc")
        {
             symbol[j]=word;

             f>>ch;
             value[j] = ch;
             j++;
        }

        word = ch;
    }

    f.close();
    int q =--j;
    j=0;
    ifstream e("ABC.txt");
    char sy,s='D';
    while(e.get(sy))
    {
        if(sy == '\n')
        {
            addre++;
        }

        if((s=='D'&&sy=='S')||(s=='d'&&sy=='s'))
        {
            address[j]=addre;
            j++;
        }
           if((s=='D'&&sy=='C')||(s=='d'&&sy=='c'))
        {
            address[j]=addre;
            j++;
        }
        s=sy;
    }

    display(q);
    e.close();
}
