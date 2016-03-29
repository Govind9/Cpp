#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class parchi
{
    fstream f;
string drive,folder,name,text,check,addr;
public:

void create()
{
cout<<"Enter the Drive the name\n";
getline(cin,drive);
cout<<"Enter the Folder name\n";
getline(cin,folder);
cout<<"Enter the name of the File\n";
getline(cin,name);
addr=drive+folder+ name;

}

void write()
{
cout<<"Enter the Text (Enter twice to stop)\n";
f.open(addr);
while(true)
{
getline(cin,text);
check=text;
f<<text<<endl;
if(text+check==check)
break;
}
}
};
