#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
string keywords[]={"main","auto","const","double","float","int","short","struct","unsigned","break","continue","else","for","long","signed","switch","void","case","default","enum","goto","register","sizeof","typedef","volatile","char","do","extern","if","return","static","union","while","asm","dynamic_cast","namespace","reinterpret_cast","try","bool","explicit","new","false","operator","template","typename","class","friend","private","this,using","const_cast","inline","public","throw","virtual","delete","mutable","protected","true"};
string operators[]={"+","-","*","/","%","--","++","&&","||","!","<",">","<=",">=","==","!=",">>","<<",",","=","?",":","->","."};
int main()
{
    string word;
    char ch;
    ifstream f;
    f.open("abc.txt");
    cout<<"KEYWORDS\n";
    while(!f.eof())
    {
        f>>word;
        for(int i=0;i-58;i++)
        {
            if(word==keywords[i])
            {
                cout<<word<<endl;
                break;
            }
        }
    }
    f.close();
    cout<<endl;
    f.open("abc.txt");
    cout<<"HEADER FILES \n";
    while(f.get(ch))
    {
        if(ch=='#')
        {
            while(ch!='<')
            {
                f.get(ch);
            }
            f.get(ch);
            while(ch!='>')
            {
                cout<<ch;
                f.get(ch);
            }
            cout<<endl;
        }

     }
    f.close();
    cout<<"\nIDENTIFIERS\n";
    f.open("abc.txt");
    int x=2;
    while(x)
    {
        f>>word;
        if(word=="int"||word=="double"||word=="float"||word=="struct"||word=="class"||word=="char"||word=="string")
        {
            f.get(ch);
            while(f.get(ch))
            {
                if(ch==';'||ch == '('){
                        f.get(ch);
                 ll:   break;
                }
                if(ch==' ')
                {
                    while(ch!=',')
                    {
                     f.get(ch);
                     if(ch==';')
                     {
                      goto ll;
                     }
                    }

                }
                if(ch==',')
                {
                    f.get(ch);
                    while(ch==' ')
                        f.get(ch);
                    cout<<endl;
                }
                if(ch=='=')
                {
                    while(ch!=',')
                        f.get(ch);
                    f.get(ch);
                }
                cout<<ch;
            }
            cout<<endl;
            if(f.eof())
                x=0;
        }
        if(f.eof())
            x=0;
    }
    f.close();
    cout<<"\nOPERATORS\n";
    f.open("abc.txt");
    while(!f.eof())
    {
        f>>word;
        for(int i=0;i-24;i++)
        {
            if(word == operators[i])
            {
                cout<<word<<endl;
                break;
            }
        }
    }
    f.close();

    return 0;
}
