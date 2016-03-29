#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string> splitC(string str, string del)
{
    char *x=const_cast<char *>(str.c_str());
    char *d=const_cast<char *>(del.c_str());
    char *s;
    vector<string> arr;
    s=strtok(x, d);
    while(s!=NULL)
    {
        arr.push_back(s);
        s=strtok(NULL, del.c_str());
    }
    return arr;
}

vector<string> splitS(string str, string del, int cut=0)
{
    vector<string> arr;
    while(str!=del && str!="")
    {
        if(cut>0)
        {
            if(arr.size()==cut)
            {
            	arr.push_back(str);
                return arr;
            }
        }
        if(str.find(del)>str.length())
        {
            arr.push_back(str);
            break;
        }
        if(str.substr(0, str.find(del)).length())
            arr.push_back(str.substr(0, str.find(del)));
        if((str.find(del)+del.length())<str.length())
            str=str.substr(str.find(del)+del.length());
        else
            str="";
    }
    return arr;
}

int main()
{
    vector<string> arr;
    string str="BCABCAABCAAABCAAAABCA";
    string del="BC";
    arr=splitS(str, del, -4);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    return arr.size();
}
