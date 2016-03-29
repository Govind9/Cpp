#include<iostream>
#include<cstring>
#include<process.h>
#include<conio.h>
using namespace std;
int main(){
    string a[5][5]={"1","|","2","|","3","-","-","-","-","-","4","|","5","|","6","-","-","-","-","-","7","|","8","|","9"};
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    string st;
    char ch='y';
do
{
  cout<<"enter the position of element for (X)\n";
  getline(cin,st);
  //strcat(st," ");
  for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
          if(a[i][j]==st)
          {
              a[i][j]="X";
          }
      }
  }
  for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    if((a[0][0]==a[0][2] && a[0][0]==a[0][4])||(a[2][0]==a[2][2]&&a[2][0]==a[2][4])||(a[4][0]==a[4][2]&&a[4][0]==a[4][4])||
       (a[0][0]==a[2][2]&&a[0][0]==a[4][4])||(a[0][4]==a[2][2]&&a[0][4]==a[4][0])||(a[0][0]==a[2][0]&&a[0][0]==a[4][0])||
       (a[0][2]==a[2][2]&&a[0][2]==a[4][2])||(a[0][4]==a[2][4]&& a[0][4]==a[4][4])){
        cout<<"\n\nX WIN--- 0 DI PAD TI \n\n";

       }
  cout<<"enter the position of element for (O)\n";
  getline(cin,st);
 // strcat(st," ");
  for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
          if(a[i][j]==st)
          {
              a[i][j]="O";
          }
      }
  }
  for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    if((a[0][0]==a[0][2] && a[0][0]==a[0][4])||(a[2][0]==a[2][2]&&a[2][0]==a[2][4])||(a[4][0]==a[4][2]&&a[4][0]==a[4][4])||
       (a[0][0]==a[2][2]&&a[0][0]==a[4][4])||(a[0][4]==a[2][2]&&a[0][4]==a[4][0])||(a[0][0]==a[2][0]&&a[0][0]==a[4][0])||
       (a[0][2]==a[2][2]&&a[0][2]==a[4][2])||(a[0][4]==a[2][4]&& a[0][4]==a[4][4])){
        cout<<"\n\nO WIN---X DI PAD TI \n\n";

       }
}while(ch=='y');
}
