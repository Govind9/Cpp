#include<iostream>
#include<algorithm>
using namespace std;
class digit_swap
{
		int *a,*wrk,*asc,*dsc,*mx,*mn;
		int sze,flag;

		/*void toarray(int num)
		{
			while(num!=0)
			{
				sze=sze+1;
				num=num/10;
			}
			a=new int[sze];
			wrk=new int[sze];
			asc=new int[sze];
			dsc=new int[sze];
			mx=new int[sze];
			mn=new int[sze];
			for(int i=0;i<sze;i++)
			{
				a[i]=num%10;
				wrk[i]=a[i];
				mx[i]=a[i];
				mn[i]=a[i];
				num=num/10;
			}
		}*/
		int toint()
		{
			int i=0,num=0;
			if(flag==0)
			{
				while(i<sze)
				{
					num=num*10+mx[i];
				}
			}
			else
			{
				while(i<sze)
				{
					num=num*10+mn[i];
				}
			}
			return num;
		}
		void exchange(int i)
		{
			int j;

					for(j=0;j<sze;j++)
					{
						if(mx[j]==asc[j])
							break;
					}
			if(flag==0)
			{
				int temp;
				temp=mx[i];
				mx[i]=asc[i];
				mx[j]=temp;
			}
			else
			{
				int temp;
				temp=mn[i];
				mn[i]=asc[i];
				mn[j]=temp;
			}
		}
		int already()
		{
			int i=0;
			if(flag==0)
			{
				for(i=0;i<sze;i++)
				{
					if(wrk[i] != asc[i])
						return i;
				}
				return i;
			}
			else
			{
				for(i=0;i<sze;i++)
				{
					if(wrk[i] != dsc[i])
						return i;
				}
				return i;
			}
		}
		void arrange()
		{
			sort(asc,asc+sze);
			for(int i=0;i<sze;i++)
            {
                dsc[sze-i]=asc[i];
            }
		}

	public:
	    digit_swap()
	    {

	    }
	    digit_swap(int se,int num)
    {
        sze=se;
        flag=0;
			 a=new int[sze];
			 wrk=new int[sze];
			 asc=new int[sze];
			 dsc=new int[sze];
			 mx=new int[sze];
			 mn=new int[sze];
			for(int i=0;i<sze;i++)
			{
				a[sze-i]=num%10;
				wrk[sze-i]=a[sze-i];
				mx[sze-i]=a[sze-i];
				mn[sze-i]=a[sze-i];
				num=num/10;
			}
			arrange();
			for(int i=0;i<sze;i++)
    cout<<a[i];
    for(int i=0;i<sze;i++)
    cout<<wrk[i]<<endl;
    for(int i=0;i<sze;i++)
    cout<<mn[i]<<endl;
    for(int i=0;i<sze;i++)
    cout<<mx[i]<<endl;
    for(int i=0;i<sze;i++)
    cout<<asc[i]<<endl;
    for(int i=0;i<sze;i++)
    cout<<dsc[i];
	    }
		void magic()
		{
			int x;
			x=already();
            exchange(x);
			cout<<"The largest number possible is: "<<toint()<<endl;
			flag=1;
			x=already();
			exchange(x);
			cout<<"The smallest number possible is: "<<toint()<<endl;
		}
		~digit_swap()
		{
			delete[] a;
			delete[] wrk;
			delete[] asc;
			delete[] dsc;
			delete[] mx;
			delete[] mn;
		}
};
