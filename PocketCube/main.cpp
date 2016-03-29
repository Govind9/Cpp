#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

string moves[18]={"U","Ui","U2","D","Di","D2","R","Ri","R2","L","Li","L2","F","Fi","F2", "B","Bi","B2"};
char color[6]={'Y','G','W','B','O','R'};
int range[6]={4, 4, 4, 4, 4, 4};
int solution[15]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

class CubeState
{
	public:
		char configuration[24];
		vector<int> parent;
		CubeState()
		{
			for(int i=0,k=0;i<24;i=i+4,k++)
			{
				for(int j=0;j<4;j++)
				{
					configuration[i+j]=color[k];
				}
			}
		}
		void printMe()
		{
			for(int i=0;i<24;i++)
			{
				cout<<configuration[i]<<" ";
			}
			cout<<endl;
		}
};

queue<CubeState> Q;

bool check(CubeState *obj)
{
    for(int i=0; i<6; i++)
    {
        int k=i*4;
        char temp=obj->configuration[k];
        for(int j=1; j<4; j++)
        {
            if(obj->configuration[k+j]!=temp)
                return false;
        }
    }
    return true;
}

void showMoves()
{
    for(int i=0;i<18;i++)
    {
        cout<<i<<"\t"<<moves[i]<<endl;
    }
}

CubeState generateNew(CubeState obj, int i)
{
	char temp1, temp2;
	switch(i)
	{
		case 0: //U
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[15];
			obj.configuration[15]=obj.configuration[22];
			obj.configuration[14]=obj.configuration[21];
			obj.configuration[21]=obj.configuration[4];
			obj.configuration[22]=obj.configuration[5];
			obj.configuration[4]=obj.configuration[19];
			obj.configuration[5]=obj.configuration[16];
			obj.configuration[19]=temp1;
			obj.configuration[16]=temp2;
			temp1=obj.configuration[0];
			obj.configuration[0]=obj.configuration[3];
			obj.configuration[3]=obj.configuration[2];
			obj.configuration[2]=obj.configuration[1];
			obj.configuration[1]=temp1;
			break;
		}
		case 1: //Ui
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[15];
			obj.configuration[14]=obj.configuration[19];
			obj.configuration[15]=obj.configuration[16];
			obj.configuration[16]=obj.configuration[5];
			obj.configuration[19]=obj.configuration[4];
			obj.configuration[4]=obj.configuration[21];
			obj.configuration[5]=obj.configuration[22];
			obj.configuration[21]=temp1;
			obj.configuration[22]=temp2;
			temp1=obj.configuration[0];
			obj.configuration[0]=obj.configuration[1];
			obj.configuration[1]=obj.configuration[2];
			obj.configuration[2]=obj.configuration[3];
			obj.configuration[3]=temp1;
			break;
		}
		case 2: //U2
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[15];
			char temp3=obj.configuration[22];
			char temp4=obj.configuration[21];
			obj.configuration[14]=obj.configuration[4];
			obj.configuration[15]=obj.configuration[5];
			obj.configuration[21]=obj.configuration[19];
			obj.configuration[22]=obj.configuration[16];
			obj.configuration[19]=temp4;
			obj.configuration[16]=temp3;
			obj.configuration[4]=temp1;
			obj.configuration[5]=temp2;
			temp1=obj.configuration[0];
			temp2=obj.configuration[1];
			obj.configuration[0]=obj.configuration[2];
			obj.configuration[1]=obj.configuration[3];
			obj.configuration[2]=temp1;
			obj.configuration[3]=temp2;
			break;
		}
		case 6:  //R
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[13];
			obj.configuration[14]=obj.configuration[2];
			obj.configuration[13]=obj.configuration[1];
			obj.configuration[2]=obj.configuration[6];
			obj.configuration[1]=obj.configuration[5];
			obj.configuration[6]=obj.configuration[10];
			obj.configuration[5]=obj.configuration[9];
			obj.configuration[10]=temp1;
			obj.configuration[9]=temp2;
			temp1=obj.configuration[16];
			obj.configuration[16]=obj.configuration[19];
			obj.configuration[19]=obj.configuration[18];
			obj.configuration[18]=obj.configuration[17];
			obj.configuration[17]=temp1;
			break;
		}
		case 7:  //Ri
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[13];
			obj.configuration[14]=obj.configuration[10];
			obj.configuration[13]=obj.configuration[9];
			obj.configuration[10]=obj.configuration[6];
			obj.configuration[9]=obj.configuration[5];
			obj.configuration[6]=obj.configuration[2];
			obj.configuration[5]=obj.configuration[1];
			obj.configuration[2]=temp1;
			obj.configuration[1]=temp2;
			temp1=obj.configuration[16];
			obj.configuration[16]=obj.configuration[17];
			obj.configuration[17]=obj.configuration[18];
			obj.configuration[18]=obj.configuration[19];
			obj.configuration[19]=temp1;
			break;
		}
		case 8:  //R2
		{
			temp1=obj.configuration[14];
			temp2=obj.configuration[13];
			char temp3=obj.configuration[1];
			char temp4=obj.configuration[2];
			obj.configuration[13]=obj.configuration[5];
			obj.configuration[14]=obj.configuration[6];
			obj.configuration[1]=obj.configuration[9];
			obj.configuration[2]=obj.configuration[10];
			obj.configuration[5]=temp2;
			obj.configuration[6]=temp1;
			obj.configuration[9]=temp3;
			obj.configuration[10]=temp4;
			temp1=obj.configuration[16];
			temp2=obj.configuration[17];
			obj.configuration[16]=obj.configuration[18];
			obj.configuration[17]=obj.configuration[19];
			obj.configuration[18]=temp1;
			obj.configuration[19]=temp2;
			break;
		}
		case 12:  //F
		{
			temp1=obj.configuration[8];
			temp2=obj.configuration[9];
			obj.configuration[8]=obj.configuration[18];
			obj.configuration[9]=obj.configuration[19];
			obj.configuration[18]=obj.configuration[2];
			obj.configuration[19]=obj.configuration[3];
			obj.configuration[2]=obj.configuration[22];
			obj.configuration[3]=obj.configuration[23];
			obj.configuration[22]=temp1;
			obj.configuration[23]=temp2;
			temp1=obj.configuration[4];
			obj.configuration[4]=obj.configuration[7];
			obj.configuration[7]=obj.configuration[6];
			obj.configuration[6]=obj.configuration[5];
			obj.configuration[5]=temp1;
			break;
		}
		case 13:  //Fi
		{
			temp1=obj.configuration[8];
			temp2=obj.configuration[9];
			obj.configuration[8]=obj.configuration[22];
			obj.configuration[9]=obj.configuration[23];
			obj.configuration[22]=obj.configuration[2];
			obj.configuration[23]=obj.configuration[3];
			obj.configuration[2]=obj.configuration[18];
			obj.configuration[3]=obj.configuration[19];
			obj.configuration[18]=temp1;
			obj.configuration[19]=temp2;
			temp1=obj.configuration[4];
			obj.configuration[4]=obj.configuration[5];
			obj.configuration[5]=obj.configuration[6];
			obj.configuration[6]=obj.configuration[7];
			obj.configuration[7]=temp1;
			break;
		}
		case 14:  //F2
		{
			temp1=obj.configuration[8];
			temp2=obj.configuration[9];
			char temp3=obj.configuration[22];
			char temp4=obj.configuration[23];
			obj.configuration[8]=obj.configuration[2];
			obj.configuration[9]=obj.configuration[3];
			obj.configuration[22]=obj.configuration[18];
			obj.configuration[23]=obj.configuration[19];
			obj.configuration[2]=temp1;
			obj.configuration[3]=temp2;
			obj.configuration[18]=temp3;
			obj.configuration[19]=temp4;
			temp1=obj.configuration[4];
			temp2=obj.configuration[5];
			obj.configuration[4]=obj.configuration[6];
			obj.configuration[5]=obj.configuration[7];
			obj.configuration[6]=temp1;
			obj.configuration[7]=temp2;
			break;
		}
		case 9:  //L
		{
			temp1=obj.configuration[15];
			temp2=obj.configuration[12];
			obj.configuration[15]=obj.configuration[11];
			obj.configuration[12]=obj.configuration[8];
			obj.configuration[11]=obj.configuration[7];
			obj.configuration[8]=obj.configuration[4];
			obj.configuration[7]=obj.configuration[3];
			obj.configuration[4]=obj.configuration[0];
			obj.configuration[3]=temp1;
			obj.configuration[0]=temp2;
			temp1=obj.configuration[20];
			obj.configuration[20]=obj.configuration[23];
			obj.configuration[23]=obj.configuration[22];
			obj.configuration[22]=obj.configuration[21];
			obj.configuration[21]=temp1;
			break;
		}
		case 10:  //Li
		{
			temp1=obj.configuration[15];
			temp2=obj.configuration[12];
			obj.configuration[15]=obj.configuration[3];
			obj.configuration[12]=obj.configuration[0];
			obj.configuration[3]=obj.configuration[7];
			obj.configuration[0]=obj.configuration[4];
			obj.configuration[7]=obj.configuration[11];
			obj.configuration[4]=obj.configuration[8];
			obj.configuration[11]=temp1;
			obj.configuration[8]=temp2;
			temp1=obj.configuration[20];
			obj.configuration[20]=obj.configuration[21];
			obj.configuration[21]=obj.configuration[22];
			obj.configuration[22]=obj.configuration[23];
			obj.configuration[23]=temp1;
			break;
		}
		case 11:  //L2
		{
			temp1=obj.configuration[15];
			temp2=obj.configuration[12];
			char temp3=obj.configuration[0];
			char temp4=obj.configuration[3];
			obj.configuration[15]=obj.configuration[7];
			obj.configuration[12]=obj.configuration[4];
			obj.configuration[0]=obj.configuration[8];
			obj.configuration[3]=obj.configuration[11];
			obj.configuration[7]=temp1;
			obj.configuration[4]=temp2;
			obj.configuration[8]=temp3;
			obj.configuration[11]=temp4;
			temp1=obj.configuration[20];
			temp2=obj.configuration[21];
			obj.configuration[20]=obj.configuration[22];
			obj.configuration[21]=obj.configuration[23];
			obj.configuration[22]=temp1;
			obj.configuration[23]=temp2;
			break;
		}
		case 3:  //D
		{
			temp1=obj.configuration[12];
			temp2=obj.configuration[13];
			obj.configuration[12]=obj.configuration[17];
			obj.configuration[13]=obj.configuration[18];
			obj.configuration[17]=obj.configuration[6];
			obj.configuration[18]=obj.configuration[7];
			obj.configuration[6]=obj.configuration[23];
			obj.configuration[7]=obj.configuration[20];
			obj.configuration[23]=temp1;
			obj.configuration[20]=temp2;
			temp1=obj.configuration[8];
			obj.configuration[8]=obj.configuration[11];
			obj.configuration[11]=obj.configuration[10];
			obj.configuration[10]=obj.configuration[9];
			obj.configuration[9]=temp1;
			break;
		}
		case 4:  //Di
		{
			temp1=obj.configuration[12];
			temp2=obj.configuration[13];
			obj.configuration[12]=obj.configuration[23];
			obj.configuration[13]=obj.configuration[20];
			obj.configuration[23]=obj.configuration[6];
			obj.configuration[20]=obj.configuration[7];
			obj.configuration[6]=obj.configuration[17];
			obj.configuration[7]=obj.configuration[18];
			obj.configuration[17]=temp1;
			obj.configuration[18]=temp2;
			temp1=obj.configuration[8];
			obj.configuration[8]=obj.configuration[9];
			obj.configuration[9]=obj.configuration[10];
			obj.configuration[10]=obj.configuration[11];
			obj.configuration[11]=temp1;
			break;
		}
		case 5:  //D2
		{
			temp1=obj.configuration[12];
			temp2=obj.configuration[13];
			char temp3=obj.configuration[18];
			char temp4=obj.configuration[17];
			obj.configuration[12]=obj.configuration[6];
			obj.configuration[13]=obj.configuration[7];
			obj.configuration[18]=obj.configuration[20];
			obj.configuration[17]=obj.configuration[23];
			obj.configuration[6]=temp1;
			obj.configuration[7]=temp2;
			obj.configuration[20]=temp3;
			obj.configuration[23]=temp4;
			temp1=obj.configuration[8];
			temp2=obj.configuration[9];
			obj.configuration[8]=obj.configuration[10];
			obj.configuration[9]=obj.configuration[11];
			obj.configuration[10]=temp1;
			obj.configuration[11]=temp2;
			break;
		}
		case 15:  //B
		{
			temp1=obj.configuration[11];
			temp2=obj.configuration[10];
			obj.configuration[11]=obj.configuration[21];
			obj.configuration[10]=obj.configuration[20];
			obj.configuration[20]=obj.configuration[0];
			obj.configuration[21]=obj.configuration[1];
			obj.configuration[1]=obj.configuration[17];
			obj.configuration[0]=obj.configuration[16];
			obj.configuration[16]=temp2;
			obj.configuration[17]=temp1;
			temp1=obj.configuration[15];
			obj.configuration[15]=obj.configuration[14];
			obj.configuration[14]=obj.configuration[13];
			obj.configuration[13]=obj.configuration[12];
			obj.configuration[12]=temp1;
			break;
		}
		case 16:  //Bi
		{
			temp1=obj.configuration[11];
			temp2=obj.configuration[10];
			obj.configuration[11]=obj.configuration[17];
			obj.configuration[10]=obj.configuration[16];
			obj.configuration[17]=obj.configuration[1];
			obj.configuration[16]=obj.configuration[0];
			obj.configuration[0]=obj.configuration[20];
			obj.configuration[1]=obj.configuration[21];
			obj.configuration[20]=temp2;
			obj.configuration[21]=temp1;
			temp1=obj.configuration[15];
			obj.configuration[15]=obj.configuration[12];
			obj.configuration[12]=obj.configuration[13];
			obj.configuration[13]=obj.configuration[14];
			obj.configuration[14]=temp1;
			break;
		}
		case 17:  //B2
		{
				temp1=obj.configuration[11];
				temp2=obj.configuration[10];
				char temp3=obj.configuration[16];
				char temp4=obj.configuration[17];
				obj.configuration[11]=obj.configuration[1];
				obj.configuration[10]=obj.configuration[0];
				obj.configuration[16]=obj.configuration[20];
				obj.configuration[17]=obj.configuration[21];
				obj.configuration[1]=temp1;
				obj.configuration[0]=temp2;
				obj.configuration[21]=temp4;
				obj.configuration[20]=temp3;
				temp1=obj.configuration[12];
				temp2=obj.configuration[13];
				obj.configuration[12]=obj.configuration[14];
				obj.configuration[13]=obj.configuration[15];
				obj.configuration[14]=temp1;
				obj.configuration[15]=temp2;
				break;
			}

	}
	return obj;
}

unsigned long long code_generator(CubeState obj)
{
    int temp[6];
    for(int i= 0 ; i<6; i++)
    {
        temp[i]=0;
        int t=0;
        for (int j=i*4; j<((i*4)+4); j++)
        {
            switch(obj.configuration[j])
            {
                case('Y'):
				{
                    t=0;
                    break;
				}
                case('G'):
                {
					t=1;
                    break;
                }
				case('W'):
                {    t=5;
                    break;
                }
				case('B'):
                {
					t=21;
                    break;
                }
				case('O'):
                {
					t=85;
                    break;
                }
				case('R'):
                {
					t=341;
                    break;
				}
			}
            temp[i]=temp[i]+t;
        }
    }
    sort(temp,temp+6);
    unsigned long long code=0;
    for (int i=0; i<6; i++)
    {
        if(i<4)
            code=code*(1000);
        if(i>3)
            code=code*(10000);
        code=code+temp[i];
    }
    return code;
}

CubeState scramble(CubeState one)
{
    string s;
    int ch;
    cout<<"Enter Your choice\n1 for entering scramble sequence\n";
    cout<<"2 for entering color schema\n";
    cin>>ch;
    if(ch==2)
    {
        cout<<"Enter 24 color characters\n";
        cin>>s;
        if(s.length()!=24)
        {
            cout<<"Wrong Sequence (Exactly 24 characters needed)\n";
            return one;
        }
        bool sym;
        for(int i=0;i<24;i++)
        {
            sym=true;
            for(int j=0;j<6;j++)
            {
                if(color[j]==s[i])
                {
                    sym=false;
                    if(range[j]>0)
                    {
                        range[j]--;
                        j=7;
                        one.configuration[i]=s[i];
                    }
                    else
                    {
                        cout<<"Wrong Sequence (No color shal be present more than 4 times)\n";
                        return one;
                    }
                }
            }
            if(sym)
            {
                cout<<"Wrong Sequence(Only standard colors are needed)\n";
                return one;
            }
        }
        //cout<<"Wonderfull\n";
        return one;
    }
    if(ch==1)
    {
        cout<<"Enter the scramble sequence\n";
        cin>>s;
        //s="RFiRFiURU2F2RiUiR";  //This one yields a 10 move solution
        //s="RiDiRDRiDiRDU2RiDiRDRiDiRDRiDiRDRiDiRDU2";
        //s="RURiUiRiFR2UiRiUiRURiFi";
        //s="FRUiRiUiRURiFiRURiUiRiFRFiU2";  //This one has a 11 move solution
        string x;
        for(int i=0;i<s.length();i++)
        {
            x="";
            x=s[i];
            if(s[i+1]=='i'||s[i+1]=='2')
            {
                x=x+s[i+1];
                i++;
            }
            for(int j=0;j<18;j++)
            {
                if(x==moves[j])
                {
                    one=generateNew(one, j);
                    break;
                }
            }
        }
        //one=generateNew(one, 1);one=generateNew(one, 12);one=generateNew(one, 2);
        //one=generateNew(one, 13);one=generateNew(one, 2);one=generateNew(one, 7);
        //one=generateNew(one, 12);one=generateNew(one, 0);one=generateNew(one, 6);
        //one=generateNew(one, 14);one=generateNew(one, 2);one=generateNew(one, 11);
        //one=generateNew(one, 17);one=generateNew(one, 9);one=generateNew(one, 0);
        return one;
    }
    else
    {
        cout<<"Wrong choice\n";
        return one;
    }
}

void giveSolution(CubeState obj)
{
    for(int i=0;i<obj.parent.size();i++)
    {
        cout<<moves[obj.parent.at(i)]<<" ";
    }
}

int main()
{
    int level;
    unsigned long long code;
    CubeState cube, cu ,temp;
    set <unsigned long long> cube_set;
    cube=scramble(cube);
    //string h="YYGYGOGGWWWWBBBBOOOYRRRR";
    //string h="YYGGROGGWWWWBBBBOOOYRRYR";
    //for(int i=0;i<24;i++)
    {
        //cube.configuration[i]=h[i];
    }
    cout<<"Configuration after scramble:\n\n";
    cube.printMe();
    cout<<"\n\nSolve sequence:\n\n";
    code=code_generator(cube);
    cube_set.insert(code);
    Q.push(cube);
    while(!Q.empty())
    {
        if(check(&Q.back()))
        {
            giveSolution(Q.back());
            //Some how free up all the memory here.
            break;
        }
        cu=Q.front();
        Q.pop();
        for(int i=0; i<18; i++)
        {
            temp=generateNew(cu, i);
            code=code_generator(temp);
            if(cube_set.find(code)!=cube_set.end())
            {
                continue;
            }
            else
            {
                cube_set.insert(code);
                temp.parent.push_back(i);
                level=temp.parent.size();
                if(level>11)   //   confirm it first.
                {
                    cout<<"Invalid Configuration\n";
                    return 0;
                }
                Q.push(temp);
            }
            if(check(&Q.back()))
            {
                break;
            }
        }
    }
    return 0;
}
