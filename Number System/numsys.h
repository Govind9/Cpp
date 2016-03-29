#include<iostream>
#include<cstring>
using namespace std;
class numsys
{
	public:
		void DB()
		{
			int x,y,s;
			cout<<"Enter the Decimal number\n";
			cin>>x;
			if(x>2)
			{
				int n=x;
				for(int i=0;n>=2;i++)
				{
					s=i+2;
					n=(n-(n%2))/2;
				}
				int a[s];
				n=x;
				for(int i=0;n!=0;i++)
				{
					if(n<2)
					a[i]=n;
					else
					a[i]=n%2;
					n=(n-(n%2))/2;
				}
				cout<<"The Binary equivalent is = ";
				for(int i=s-1;i>=0;i--)
				{
					cout<<a[i];
				}
			}
			else
			{
				switch (x)
				{
					case 0: cout<<"The Binary equivalent is = 0";
					break;
					case 1: cout<<"The Binary equivalent is = 1";
					break;
					case 2: cout<<"The Binary equivalent is = 10";
					break;
				}
			}
		}
		void DO()
		{
			int x,y,s;
			cout<<"Enter the Decimal number\n";
			cin>>x;
			if(x>8)
			{
				int n=x;
				for(int i=0;n>=8;i++)
				{
					s=i+2;
					n=(n-(n%8))/8;
				}
				int a[s];
				n=x;
				for(int i=0;n!=0;i++)
				{
					if(n<8)
						a[i]=n;
					else
						a[i]=n%8;
					n=(n-(n%8))/8;
				}
				cout<<"The Octal equivalent is = ";
				for(int i=s-1;i>=0;i--)
				{
					cout<<a[i];
				}
			}
			else
			{
				switch (x)
				{
					case 0 : cout<<"The Octal equivalent is = 0";
					break;
					case 1 : cout<<"The Octal equivalent is = 1";
					break;
					case 2 : cout<<"The Octal equivalent is = 2";
					break;
					case 3 : cout<<"The Octal equivalent is = 3";
					break;
					case 4 : cout<<"The Octal equivalent is = 4";
					break;
					case 5 : cout<<"The Octal equivalent is = 5";
					break;
					case 6 : cout<<"The Octal equivalent is = 6";
					break;
					case 7 : cout<<"The Octal equivalent is = 7";
					break;
					case 8 : cout<<"The Octal equivalent is = 10";
					break;
				}
			}
		}
		void DH()
		{
			int x,y,s;
			cout<<"Enter the Decimal number\n";
			cin>>x;
			if(x>16)
			{
				int n=x;
				for(int i=0;n>=16;i++)
				{
					s=i+2;
					n=(n-(n%16))/16;
				}
				int a[s];
				n=x;
				for(int i=0;n!=0;i++)
				{
					if(n<16)
						a[i]=n;
					else
						a[i]=n%16;
					n=(n-(n%16))/16;
				}
				cout<<"The Hexadecimal equivalent of "<<x<<" (base 10) is = ";
				for(int i=s-1;i>=0;i--)
				{
					if(a[i]<10)
					{
						cout<<a[i];
					}
					else
					{
						switch (a[i])
						{
							case 10:cout<<"A";
							break;
							case 11:cout<<"B";
							break;
							case 12:cout<<"C";
							break;
							case 13:cout<<"D";
							break;
							case 14:cout<<"E";
							break;
							case 15:cout<<"F";
							break;
							default : cout<<"\nAh ki ho geya\n";
							break;
						}
					}
				}
			}
			else
			{
				switch(x)
				{
					case 0:cout<<"The Hexadecimal equivalent is =0";
					break;
					case 1:cout<<"The Hexadecimal equivalent is =1";
					break;
					case 2:cout<<"The Hexadecimal equivalent is =2";
					break;
					case 3:cout<<"The Hexadecimal equivalent is =3";
					break;
					case 4:cout<<"The Hexadecimal equivalent is =4";
					break;
					case 5:cout<<"The Hexadecimal equivalent is =5";
					break;
					case 6:cout<<"The Hexadecimal equivalent is =6";
					break;
					case 7:cout<<"The Hexadecimal equivalent is =7";
					break;
					case 8:cout<<"The Hexadecimal equivalent is =8";
					break;
					case 9:cout<<"The Hexadecimal equivalent is =9";
					break;
					case 10:cout<<"The Hexadecimal equivalent is =A";
					break;
					case 11:cout<<"The Hexadecimal equivalent is =B";
					break;
					case 12:cout<<"The Hexadecimal equivalent is =C";
					break;
					case 13:cout<<"The Hexadecimal equivalent is =D";
					break;
					case 14:cout<<"The Hexadecimal equivalent is =E";
					break;
					case 15:cout<<"The Hexadecimal equivalent is =F";
					break;
					case 16:cout<<"The Hexadecimal equivalent is =1O";
					break;
				}
			}
		}
		void BD()
		{
		int y=0;
		char a[100];
		cout<<"Enter the Binary Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		}
		}
		cout<<"The Decimal Equivalent is = ";
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*2;
		 }
		y=y+b[i];
		}
		cout<<y;
		}
		void OD()
		{
		int y=0;
		char a[100];
		cout<<"Enter the Octal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		}
		}
		cout<<"The Decimal Equivalent is = ";
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*8;
		 }
		y=y+b[i];
		}
		cout<<y;
		}
		void HB()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Hexadecimal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		case '8' : b[i]=8;
		break;
		case '9': b[i]=9;
		break;
		case 'A': b[i]=10;
		break;
		case 'B': b[i]=11;
		break;
		case 'C': b[i]=12;
		break;
		case 'D': b[i]=13;
		break;
		case 'E': b[i]=14;
		break;
		case 'F': b[i]=15;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*16;
		 }
		y=y+b[i];
		}
		im=y;
		int n=im;
		if(n>2)
		{
		for(int i=0;n>=2;i++)
		{
		 s=i+2;
		n=(n-(n%2))/2;
		}
		int c[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<2)
			c[i]=n;
			else
		c[i]=n%2;
		n=(n-(n%2))/2;
		}
		cout<<"The Binary equivalent is = ";
		for(int i=s-1;i>=0;i--)
		{
		cout<<c[i];
		}
		}
		else
		{
		switch (n)
		{
		case 0: cout<<"The Binary equivalent is = 0";
		break;
		case 1: cout<<"The Binary equivalent is = 1";
		break;
		case 2: cout<<"The Binary equivalent is = 10";
		break;
		}
		}
		}
		void HD()
		{
		int y=0;
		char a[100];
		cout<<"Enter the Hexadecimal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		case '8' : b[i]=8;
		break;
		case '9': b[i]=9;
		break;
		case 'A': b[i]=10;
		break;
		case 'B': b[i]=11;
		break;
		case 'C': b[i]=12;
		break;
		case 'D': b[i]=13;
		break;
		case 'E': b[i]=14;
		break;
		case 'F': b[i]=15;
		break;
		}
		}
		cout<<"The Decimal Equivalent is = ";
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*16;
		 }
		y=y+b[i];
		}
		cout<<y;
		}
		void BO()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Binary Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*2;
		 }
		y=y+b[i];
		}
		im=y;
		int n=im;
		if(n>8)
		{
		for(int i=0;n>=8;i++)
		{
		 s=i+2;
		n=(n-(n%8))/8;
		}
		int c[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<8)
			c[i]=n;
			else
		c[i]=n%8;
		n=(n-(n%8))/8;
		}
		cout<<"The Octal equivalent is = ";
		for(int i=s-1;i>=0;i--)
		{
		cout<<c[i];
		}
		}
		else
		{
		switch (n)
		{
		case 0 : cout<<"The Octal equivalent is = 0";
		break;
		case 1 : cout<<"The Octal equivalent is = 1";
		break;
		case 2 : cout<<"The Octal equivalent is = 2";
		break;
		case 3 : cout<<"The Octal equivalent is = 3";
		break;
		case 4 : cout<<"The Octal equivalent is = 4";
		break;
		case 5 : cout<<"The Octal equivalent is = 5";
		break;
		case 6 : cout<<"The Octal equivalent is = 6";
		break;
		case 7 : cout<<"The Octal equivalent is = 7";
		break;
		case 8 : cout<<"The Octal equivalent is = 10";
		break;
		}
		}
		}
		void HO()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Hexadecimal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		case '8' : b[i]=8;
		break;
		case '9': b[i]=9;
		break;
		case 'A': b[i]=10;
		break;
		case 'B': b[i]=11;
		break;
		case 'C': b[i]=12;
		break;
		case 'D': b[i]=13;
		break;
		case 'E': b[i]=14;
		break;
		case 'F': b[i]=15;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*16;
		 }
		y=y+b[i];
		}
		im=y;
		int n=im;
		if(n>8)
		{
		for(int i=0;n>=8;i++)
		{
		 s=i+2;
		n=(n-(n%8))/8;
		}
		int c[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<8)
			c[i]=n;
			else
		c[i]=n%8;
		n=(n-(n%8))/8;
		}
		cout<<"The Octal equivalent is = ";
		for(int i=s-1;i>=0;i--)
		{
		cout<<c[i];
		}
		}
		else
		{
		switch (n)
		{
		case 0 : cout<<"The Octal equivalent is = 0";
		break;
		case 1 : cout<<"The Octal equivalent is = 1";
		break;
		case 2 : cout<<"The Octal equivalent is = 2";
		break;
		case 3 : cout<<"The Octal equivalent is = 3";
		break;
		case 4 : cout<<"The Octal equivalent is = 4";
		break;
		case 5 : cout<<"The Octal equivalent is = 5";
		break;
		case 6 : cout<<"The Octal equivalent is = 6";
		break;
		case 7 : cout<<"The Octal equivalent is = 7";
		break;
		case 8 : cout<<"The Octal equivalent is = 10";
		break;
		}
		}
		}
		void OB()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Octal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*8;
		 }
		y=y+b[i];
		}
		im=y;
		int n=im;
		if(n>2)
		{
		for(int i=0;n>=2;i++)
		{
		 s=i+2;
		n=(n-(n%2))/2;
		}
		int c[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<2)
			c[i]=n;
			else
		c[i]=n%2;
		n=(n-(n%2))/2;
		}
		cout<<"The Binary equivalent is = ";
		for(int i=s-1;i>=0;i--)
		{
		cout<<c[i];
		}
		}
		else
		{
		switch (n)
		{
		case 0: cout<<"The Binary equivalent is = 0";
		break;
		case 1: cout<<"The Binary equivalent is = 1";
		break;
		case 2: cout<<"The Binary equivalent is = 10";
		break;
		}
		}
		}
		void BH()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Binary Number\n";
		cin>>a;
		int c[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : c[i]=0;
		break;
		case '1': c[i]=1;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 c[i]=c[i]*2;
		 }
		y=y+c[i];
		im=y;
		}
		int n=im;
		if(n>16)
		{
		for(int i=0;n>=16;i++)
		{
		 s=i+2;
		n=(n-(n%16))/16;
		}
		int b[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<16)
			b[i]=n;
			else
		b[i]=n%16;
		n=(n-(n%16))/16;
		}
		cout<<"The Hexadecimal equivalent is =  ";
		for(int i=s-1;i>=0;i--)
		{
		if(b[i]<10)
		cout<<b[i];
		else
		{switch (b[i])
		{
		case 10:cout<<"A";
		break;
		case 11:cout<<"B";
		break;
		case 12:cout<<"C";
		break;
		case 13:cout<<"D";
		break;
		case 14:cout<<"E";
		break;
		case 15:cout<<"F";
		break;
		default : cout<<"\nAh ki ho geya\n";
		break;
		}
		}
		}
		}
		else
		{
		switch(n)
		{
		case 0:cout<<"The Hexadecimal equivalent is =0";
		break;
		case 1:cout<<"The Hexadecimal equivalent is =1";
		break;
		case 2:cout<<"The Hexadecimal equivalent is =2";
		break;
		case 3:cout<<"The Hexadecimal equivalent is =3";
		break;
		case 4:cout<<"The Hexadecimal equivalent is =4";
		break;
		case 5:cout<<"The Hexadecimal equivalent is =5";
		break;
		case 6:cout<<"The Hexadecimal equivalent is =6";
		break;
		case 7:cout<<"The Hexadecimal equivalent is =7";
		break;
		case 8:cout<<"The Hexadecimal equivalent is =8";
		break;
		case 9:cout<<"The Hexadecimal equivalent is =9";
		break;
		case 10:cout<<"The Hexadecimal equivalent is =A";
		break;
		case 11:cout<<"The Hexadecimal equivalent is =B";
		break;
		case 12:cout<<"The Hexadecimal equivalent is =C";
		break;
		case 13:cout<<"The Hexadecimal equivalent is =D";
		break;
		case 14:cout<<"The Hexadecimal equivalent is =E";
		break;
		case 15:cout<<"The Hexadecimal equivalent is =F";
		break;
		case 16:cout<<"The Hexadecimal equivalent is =10";
		break;
		}
		}
		}
		void OH()
		{
		int y=0,im,s;
		char a[100];
		cout<<"Enter the Octal Number\n";
		cin>>a;
		int b[strlen(a)];
		for(int i=0;i<strlen(a);i++)
		{
		switch (a[i])
		{
		case '0' : b[i]=0;
		break;
		case '1': b[i]=1;
		break;
		case '2': b[i]=2;
		break;
		case '3': b[i]=3;
		break;
		case '4': b[i]=4;
		break;
		case '5': b[i]=5;
		break;
		case '6': b[i]=6;
		break;
		case '7': b[i]=7;
		break;
		}
		}
		for(int i=0;i<strlen(a);i++)
		{
		 for(int j=strlen(a)-i-1;j>0;j--)
		 {
		 b[i]=b[i]*8;
		 }
		y=y+b[i];
		}
		im=y;
		int n=im;
		if(n>16)
		{
		for(int i=0;n>=16;i++)
		{
		 s=i+2;
		n=(n-(n%16))/16;
		}
		int a[s];
		 n=im;
		for(int i=0;n!=0;i++)
		{
		if(n<16)
			a[i]=n;
			else
		a[i]=n%16;
		n=(n-(n%16))/16;
		}
		cout<<"The Hexadecimal equivalent is = ";
		for(int i=s-1;i>=0;i--)
		{
		if(a[i]<10)
		cout<<a[i];
		else
		{switch (a[i])
		{
		case 10:cout<<"A";
		break;
		case 11:cout<<"B";
		break;
		case 12:cout<<"C";
		break;
		case 13:cout<<"D";
		break;
		case 14:cout<<"E";
		break;
		case 15:cout<<"F";
		break;
		default : cout<<"\nAh ki ho geya\n";
		break;
		}
		}
		}
		}
		else
		{
		switch(n)
		{
		case 0:cout<<"The Hexadecimal equivalent is =0";
		break;
		case 1:cout<<"The Hexadecimal equivalent is =1";
		break;
		case 2:cout<<"The Hexadecimal equivalent is =2";
		break;
		case 3:cout<<"The Hexadecimal equivalent is =3";
		break;
		case 4:cout<<"The Hexadecimal equivalent is =4";
		break;
		case 5:cout<<"The Hexadecimal equivalent is =5";
		break;
		case 6:cout<<"The Hexadecimal equivalent is =6";
		break;
		case 7:cout<<"The Hexadecimal equivalent is =7";
		break;
		case 8:cout<<"The Hexadecimal equivalent is =8";
		break;
		case 9:cout<<"The Hexadecimal equivalent is =9";
		break;
		case 10:cout<<"The Hexadecimal equivalent is =A";
		break;
		case 11:cout<<"The Hexadecimal equivalent is =B";
		break;
		case 12:cout<<"The Hexadecimal equivalent is =C";
		break;
		case 13:cout<<"The Hexadecimal equivalent is =D";
		break;
		case 14:cout<<"The Hexadecimal equivalent is =E";
		break;
		case 15:cout<<"The Hexadecimal equivalent is =F";
		break;
		case 16:cout<<"The Hexadecimal equivalent is =10";
		break;
		}
		}
		}

};
