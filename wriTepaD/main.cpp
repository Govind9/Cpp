#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
string text,check;
char name[100];

cout<<"Enter the name of the File\n";
cin.getline(name,99);




ofstream f(name);
cout<<"Enter the Text (Enter twice to stop)\n";

while(true)
{
getline(cin,text);
check=text;
f<<text<<endl;
if(text+check==check)
break;
}
f.close();
    return 0;
}
