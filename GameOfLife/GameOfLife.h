#include<iostream>
#include<cstdlib>
#include<ctime>
#define lenght 20
#define lenght2 20
using namespace std;
class GameOfLife
{
		char parent[lenght][lenght2],child[lenght][lenght2];
		void brahma()
		{
			for(int i=0;i<lenght;i++)
			{
				for(int j=0;j<lenght2;j++)
				{
					parent[i][j]=child[i][j];
				}
			}
		}
		int vishnu(int i,int j)
		{
			int neighbours=0;
			for(int k=-1;k<2;k++)
			{
				for(int l=-1;l<2;l++)
				{
					if((i+k)<0||(j+l)<0||(!k && !l)||(i+k)>=lenght||(j+l)>=lenght2)
						continue;
					else
					{
 						parent[i+k][j+l]=='*' ? neighbours++ :neighbours=neighbours;
					}
				}
			}
			return neighbours;
		}
		void mahesh()
		{
			for(int i=0;i<lenght;i++)
			{
				for(int j=0;j<lenght2;j++)
				{
					if(parent[i][j]=='*')
					{
						if(vishnu(i,j)<2||vishnu(i,j)>3)
							child[i][j]='_';
						else
							child[i][j]='*';
					}
					else
					{
						if(vishnu(i,j)==3)
							child[i][j]='*';
						else
							child[i][j]='_';
					}
				}
			}
		}
		void display()
		{
		    for(int i=0;i<lenght;i++)
			{
				for(int j=0;j<lenght2;j++)
				{
					cout<<parent[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	public:
		GameOfLife()
		{
			for(int i=0;i<lenght;i++)
			{
				for(int j=0;j<lenght2;j++)
				{
					//srand(static_cast<unsigned>(time(0)));
					rand()%2 ? parent[i][j]='*' : parent[i][j]='_';
					child[i][j]='_';
				}
			}
		}
		void majic()
		{
			cout<<"Enter The No. Of Generations\n";
			int gens;
			cin>>gens;
			for(int i=0;i<gens;i++)
			{
			    display();
				mahesh();
				brahma();
				cout<<endl<<endl<<endl<<endl<<endl;
			}
		}
};
