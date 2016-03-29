#include <iostream>
using namespace std;
#define MAX_SIZE 10
bool adjacent[MAX_SIZE][MAX_SIZE];
int status[MAX_SIZE]; //0 means untouched, 1 means in stack, 2 means done.
int n;
void dfs(int in)
{
    for(int i=0;i<n;i++)
    {
        if(adjacent[in][i] && status[i]==0)
        {
            status[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(adjacent[in][i] && status[i]==0)
        {
            dfs(i);
        }
    }
    status[in]=2;
    cout<<"\t"<<in;
}
int main()
{
    cout<<"AMANDEEP SINGH\t1311014\n\n";
    cout<<"Enter the number of vertices\n";
    cin>>n;
    if(n<=0)
        return 0;
    if(n>MAX_SIZE)
        n=MAX_SIZE;
    int ch;
    for(int i=0;i<n;i++)
    {
        status[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            cout<<"Is there a path from "<<i<<" to "<<j<<"?";
            cout<<"(Enter 1 for yes and 0 for no)\n";
            cin>>ch;
            if(ch==1)
                adjacent[i][j]=true;
            else
                adjacent[i][j]=false;
        }
    }
    int src;
    cout<<"Enter the index for the source vertex\n";
    cin>>src;
    if(src>n-1)
        src=n-1;
    if(src<0)
        src=0;
    status[src]=2;
    cout<<"Topologically sorted order(using DFS) is: ";
    cout<<"";
    cout<<src<<endl;
    for(int i=0;i<n;i++)
    {
        if(adjacent[src][i])
            status[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(adjacent[src][i])
            dfs(i);
    }
    return 0;
}
