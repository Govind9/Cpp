#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;
struct code
{
    int step;
    code* agla=NULL;
};
struct node
{
	char ch=NULL;
	int freq=0,left=-1,right=-1,skip=0;
	code *cryptic=NULL;
	node* next=NULL;
};
class everything
{
	public:
		node *head=NULL,*arr=NULL;
		int sze=0,trr;
		void add(char newch)
		{
			if(head)
			{
			    int h=0;
				node *ptr=head;
				while(ptr)
				{
					if(ptr->ch==newch)
					{
						h=1;
						break;
					}
					ptr=ptr->next;
				}
				if(h)
                {
                    ptr->freq++;
                }
                else
                {
                    node *newnode=new node;
                    newnode->ch=newch;
                    newnode->freq++;
                    node *temp;
                    temp=head;
                    head=newnode;
                    newnode=temp;
                    head->next=newnode;
                    sze++;
                }
			}
			else
            {
                head=new node;
                head->ch=newch;
                head->freq++;
                sze++;
            }
        }
        void for_d(int x)
        {
            sze=x;
            trr=2*sze-1;
            arr=new node[trr];
            for(int i=0;i<x;i++)
            {
                arr[i].skip=1;
            }
        }
		void the_array()
		{
			trr=2*sze-1;
			arr=new node[trr];
			node* ptr=head;
			for(int i=0;i<sze;i++)
			{
			    arr[i]=*ptr;
                arr[i].skip=1;
                ptr=ptr->next;
            }
		}
		int minimum()
		{
            int x,mini;
            for(x=0;!arr[x].skip;x++);
            mini=arr[x].freq;
            for(int i=0;i<trr;i++)
            {
                if(!arr[i].skip)
                {}
                else
                {
                    if(arr[i].freq<mini)
                    {
                        mini=arr[i].freq;
                        x=i;
                    }
                }
            }
            return x;
		}
		int second_minumum()
		{
            int s=minimum();
            int buffer,x;
            for(x=0;!arr[x].skip;x++);
            if(s==x)
            {
                for(x++;!arr[x].skip;x++);
                buffer=arr[x].freq;
            }
            else
            {
                buffer=arr[x].freq;
            }
            for(int i=0;i<trr;i++)
            {
                if((!arr[i].skip)||(i==s))
                {}
                else
                {
                    if(arr[i].freq<buffer)
                    {
                        buffer=arr[i].freq;
                        x=i;
                    }
                }
            }
            return x;
		}
		void huffman()
		{
		    int c=sze,m,sm;
		    while(c<trr)
            {
                m=minimum(),sm=second_minumum();
                arr[c].freq=arr[m].freq+arr[sm].freq;
                arr[c].left=m;
                arr[c].right=sm;
                arr[c].skip=1;
                arr[m].skip=arr[sm].skip=0;
                traverse(m,0);
                traverse(sm,1);
                c++;
            }
		}
		void traverse(int c,int n)
		{
		    if(arr[c].left>=0)
            {
                traverse(arr[c].left,n);
            }
            if(arr[c].right>=0)
            {
                traverse(arr[c].right,n);
            }
            else
            {
                codes(c,n);
            }
		}
		void codes(int c,int x)
		{
            if(arr[c].cryptic)
            {
                code *nami=new code;
                nami->step=x;
                code* tmp;
                tmp=arr[c].cryptic;
                arr[c].cryptic=nami;
                arr[c].cryptic->agla=tmp;

            }
            else
            {
                arr[c].cryptic=new code;
                arr[c].cryptic->step=x;
            }
        }
        void show_code(int c)
        {
            code* pntr=arr[c].cryptic;
            while(pntr)
            {
                cout<<arr[c].cryptic->step;
                pntr=pntr->agla;
            }
        }
        void display()
        {
            for(int i=0;i-sze;i++)
            {
                cout<<arr[i].ch<<"\t";
                show_code(i);
                cout<<endl;
            }
        }
		void majic()
		{
			the_array();
			huffman();
			//display();
		}
		~everything()
		{
		    delete [] arr;
		}
};
class extract
{
public:
    ifstream f1;
    ofstream f2;
    int n;
    int remain;
    everything obj;
    int sze,trr;
    char che,h[100]="gobi.dni";
    void reading()
    {
        int a[7]={-1,-1,-1,-1,-1,-1,-1};
        f1.open(h);
        f1>>sze;
        f1.get(che);
        f1>>remain;
        f1.get(che);
        trr=2*sze-1;
        obj.for_d(sze);
        for(int i=0;i<sze;i++)
        {
            f1.get(che);
            obj.arr[i].ch=che;
            f1>>obj.arr[i].freq;
            f1.get(che);
        }
        obj.huffman();
        f2.open("temp2.txt");
        int flag=0;
        while(f1.get(che))
        {
            if(flag)
            {
                for(int i=0;i<7;i++)
                {
                    if(a[6-i]==-1)
                        a[6-i]=0;
                    f2<<a[6-i];
                }
            }
            flag=1;
            for(int i=0;i<7;i++)
                a[i]=-1;
            n=int(che)-128;
            if(n<0)
                n=n+256;
            for(int i=0;i<7;i++)\
            {
                a[i]=n%2;
                n=n/2;
            }
        }
        for(int i=0;i<remain;i++)
        {
            if(a[6-i]==-1)
                a[6-i]=0;
            f2<<a[6-i];
        }
        f1.close();
        f2.close();
    }
    void treeing()
    {
        int i;
        f1.open("temp2.txt");
        i=trr-1;
        f2.open("govi.txt");
        while(f1.get(che))
        {
            if(obj.arr[i].ch)
            {
                f2<<obj.arr[i].ch;
                i=trr-1;
            }
            switch(che)
            {
                case '0':i=obj.arr[i].left;
                         break;
                case '1':i=obj.arr[i].right;
                         break;
                default :break;
            }
        }
        f2<<obj.arr[i].ch;
        f2.close();
        f1.close();
        remove("temp2.txt");
    }
    void karnama()
    {
        reading();
        treeing();
    }
};
class compress
{
    public:
        ifstream f1;
        ofstream f2;
        everything obj;
        char che,h[100]="gobi.txt";
        int reman=0;
		void code_making()
		{
            f1.open(h);
			while(f1.get(che))
			{
				obj.add(che);
			}
			f1.close();
			obj.majic();
		}
		void intermediation()
		{
		    f2.open("temp.txt");
			int n,i;
			f1.open(h);
			while(f1.get(che))
			{
				for(i=0;i<obj.sze;i++)
				{
					if(obj.arr[i].ch==che)
					{
						break;
					}
				}
                code *p=obj.arr[i].cryptic;
                while(p)
                {
                    f2<<p->step;
                    reman++;
                    if(reman==7)
                        reman=0;
                    p=p->agla;
                }
			}
			f1.close();
			f2.close();
		}
		void finale()
		{
		    int n=128,i;
            f1.open("temp.txt");
            f2.open("gobi.dni");
            f2<<obj.sze;
            f2<<' '<<reman;
            for(int i=0;i<obj.sze;i++)
            {
                f2<<' '<<obj.arr[i].ch<<obj.arr[i].freq;
            }
            f2<<'a';
            for(i=0;f1.get(che);i++)
            {
                switch(che)
                {
                    case '1': n=n+pow(2,6-i);
                                break;
                    default : break;
                }
                if(i==6)
                {
                    i=-1;
                    f2<<char(n);
                    n=128;
                }
            }
            if(i)
                f2<<char(n);
            f1.close();
            f2.close();
            remove("temp.txt");
        }
		void jadu()
		{
		    code_making();
		    intermediation();
		    finale();
		}
};

