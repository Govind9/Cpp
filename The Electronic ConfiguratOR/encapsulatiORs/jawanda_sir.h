#include<iostream>

using namespace std;
class jawanda_sir{
public:
    char a[21]={'s','s','p','s','p','s','d','p','s','d','p','s','f','d','p','s','f','d','p','s','3'};
    int b[21]={1,2,2,3,3,4,3,4,5,4,5,6,4,5,6,7,5,6,7,8,3};
int c[21]={2,4,10,12,18,20,30,36,38,48,54,56,70,80,88,102,112,118,120,3};
int y,z;
void EC(int x){

for(int i=0;i<20&&c[i]<=x;i++){
    y=i; z= x - c[i];
};
 cout<<"The Electronic COnfiguration of the Element with Atomic Number "<<x<<" is \n";
for(int j=0;j<=y;j++){

    cout<<b[j]<<a[j];
    switch (a[j]){
    case 's' :cout<<"2 ";
    break;
    case 'p' :cout<<"6 ";
    break;
    case 'd' :cout<<"10 ";
    break;
    case 'f' :cout<<"14 ";
    break;
    }
};
if(z!=0)
    cout<<b[y+1]<<a[y+1]<<z<<endl<<"\n\n";
  else
        cout<<" "<<endl<<"\n\n";


}
};
