#include <iostream>
#include<algorithm>
using namespace std;
class digit_swap
{
    int *a,*wrk,*asc,*dsc,*mx,*mn,sze,flag,num;
    void innt(int s,int nm)
    {
        sze=s;
        num=nm;
        flag=0;
        a=new int[sze];
        wrk=new int[sze];
        asc=new int[sze];
        dsc=new int[sze];
        mx=new int[sze];
        mn=new int[sze];
        for(int i=0;i<sze;i++)
        {
            a[i]=nm%10;
            nm=nm/10;
        }
        reverse(a,a+sze);
        for(int i=0;i<sze;i++)
        {
            wrk[i]=a[i];
            mx[i]=a[i];
            mn[i]=a[i];
            asc[i]=a[i];
            dsc[i]=a[i];
        }
        sort(asc,asc+sze);
        sort(dsc,dsc+sze);
        reverse(dsc,dsc+sze);
    }
    void finish()
    {
        delete[] a;
        delete[] wrk;
        delete[] asc;
        delete[] dsc;
        delete[] mx;
        delete[] mn;
    }
    int already()
    {
        int i;
        if(flag==0)
        {
            for(i=0;i<sze;i++)
            {
                if(wrk[i] != dsc[i])
                    break;
            }
            return i;
        }
        else
        {
            for(i=0;i<sze;i++)
            {
                if(wrk[i] != asc[i])
                    break;
            }
            return i;
        }
    }
    void exchange(int i)
    {
        int j;
        if(flag==0)
        {
            for(j=0;j<sze;j++)
            {
                if(mx[j]==dsc[i])
                {
                    while(mx[j]==mx[j+1])
                    {
                        j++;
                    }
                    break;
                }
            }
            int temp;
            temp=mx[i];
            mx[i]=dsc[i];
            mx[j]=temp;
        }
        else
        {
            for(j=0;j<sze;j++)
            {
                if(mn[j]==asc[i])
                {
                    while(mn[j]==mn[j+1])
                    {
                        j++;
                    }
                    break;
                }
            }
            int temp;
            int h=i;
            if(asc[0]==0)
                h=i+1;
            temp=mn[h];
            mn[h]=asc[i];
            mn[j]=temp;
        }
    }
    int toint()
    {
        int i=0,num=0;
        if(flag==0)
        {
            while(i<sze)
            {
                num=num*10+mx[i];
                i=i+1;
            }
        }
        else
        {
            while(i<sze)
            {
                num=num*10+mn[i];
                i=i+1;
            }
        }
        return num;
    }
public:
    void majic(int ha,int akh,int nnn)
    {
        innt(ha,akh);
        if(nnn==0)
        {
            exchange(already());
            cout<<toint()<<"\t";
            flag=1;
            exchange(already());
            cout<<toint()<<endl;
        }
        else
        {
            flag=1;
            exchange(already());
            cout<<-1*toint()<<endl;
            flag=0;
            exchange(already());
            cout<<-1*toint()<<"\t";
        }
        finish();
    }
};
int main()
{

    int x,cpy,sze,neg;
    int times;
    cout<<"Enter the number of times to enter\n";
    cin>>times;
    digit_swap obj[times];
    for(int i=0;i<times;i++)
    {
        sze=0;
        neg=0;
        cout<<"Enter the number\n";
        cin>>x;
        if(x<0)
        {
            x=-x;
            neg=1;
        }
        cpy=x;
        while(cpy!=0)
        {
            sze=sze+1;
            cpy=cpy/10;
        }
        obj[i].majic(sze,x,neg);
    }
    return 0;
}
