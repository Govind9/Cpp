#include <iostream>
#include"jawanda_sir.h"

using namespace std;

int main()
{int at;
char ch='y';
jawanda_sir j1;
do{

cout<<"Enter the Atomic Number of the Element\n";
cin>>at;
if(at>120)
    cout<<"Please enter a valid atomic number (less than or equal to 120)\n";
else

    j1.EC(at);

    if(at==0)
        break;
cout<<"enter Y/N\n";
cin>>ch;
}while(ch=='y'||ch=='Y');

    return 0;
}
