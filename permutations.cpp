#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string x;
    cout<<"Enter Your String\n";
    getline(cin,x);
    int l=x.length();
    int c[l];
    for(int i=0;i<l;i++)
        c[i]=1;
    for(int i=0;i<x.length();i++)
    {
        for(int j=0;j<x.length();j++)
        {
            if(i==j)
                continue;
            else
            {
                if(x[i]==x[j])
                    {
                        c[i]++;
                    }
            }
        }
    }
    for(int i=1;i<l;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(x[i]==x[j])
            {
                c[i]=1;
                break;
            }
        }
    }
    //for(int i=0;i<l;i++)
        //cout<<c[i]<<endl;
    int sum=1;
    for(int i=1;i<=l;i++)
    {
        sum=sum*i;
    }
    int divide=1;
    int dd=1;
    for(int i=0;i<l;i++)
    {
        for(int j=1;j<=c[i];j++)
        {
            divide=divide*j;
        }
        dd=dd*divide;
        divide=1;
    }

cout<<"the answer is\n"<<sum<<"/"<<dd;
    return 1;
}
