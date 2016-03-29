#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
string SYMTAB1[100],LITTAB1[100],TII2[100],opcode[100],s,ss;
string MOT1[]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
string MOT3[]={"00","01","02","03","04","05","06","07","08","09","10"};
string MOT2[]={"AD","IS","IS","IS","IS","IS","IS","IS","IS","IS","IS"};
int ssize=0,lsize=0,lc=0,n,LC[100],memory[100],rgstr[100],inc=0,tsize=0,TII1[100],LITTAB2[100],SYMTAB4[100],SYMTAB2[100],SYMTAB3[100];
void display()
{
    cout<<"LC\t    code\tregister\tmemory\n\n";
    for(int i=1;i-lc;i++)
    {
        cout<<LC[i]<<"\t    "<<opcode[i]<<"\t          "<<rgstr[i]<<"\t        "<<memory[i]<<endl;
    }
}
void symbol_search(string s)
{
    if(s[0]=='=')
    {
        for(int i=0;i-lsize;i++)
        {
            if(s==LITTAB1[i])
            {
                memory[lc]=LITTAB2[i];
                goto l;
            }
        }
        TII1[tsize]=LC[lc];
        TII2[tsize]=s;
        tsize++;
        l: ;
    }
    else
    {
        for(int i=0;i-ssize;i++)
        {
            if(s==SYMTAB1[i])
            {
                memory[lc]=SYMTAB3[i];
                goto ll;
            }
        }
        TII1[tsize]=LC[lc];
        TII2[tsize]=s;
        tsize++;
        ll : ;
    }
}
void completion()
{
     for(int i=0;i-tsize;i++)
        {
            for(int j=0;j-ssize;j++)
            {
                if(TII2[i]==SYMTAB1[j])
                {
                    int k=1;
                    while(1)
                    {
                        if(LC[k]==TII1[i])
                            break;
                        k++;
                    }
                    memory[k]=SYMTAB3[j];
                    break;
                }
            }
        }
}
int main()
{

    ifstream f("ABC.txt");
    f>>s;
    f>>n; //get the starting address
    LC[0]=n;

    while(!f.eof())
    {
        f>>s;
        if(s=="END")
        {
            //lc++;
            f.close();
            completion();
           // memory[1]=212;
            display();
            return tsize;
        }
        //lc++;
        b:for(int i=0;i-11;i++)
        {
            if(s==MOT1[i])
            {
                if(i==0)
                {
                   lc++;
                    LC[lc]=LC[lc-1]+inc;

                    opcode[lc]=MOT3[i];
                    rgstr[lc]=0;
                    memory[lc]=0;
                }
                if(i>=1&&i<=8)
                {
                   lc++;
                    LC[lc]=LC[lc-1]+inc;
                    opcode[lc]=MOT3[i];
                    f>>s;
                    if(s=="AREG"||s=="LT")
                        rgstr[lc]=1;
                    if(s=="BREG"||s=="LE")
                        rgstr[lc]=2;
                    if(s=="CREG"||s=="EQ")
                        rgstr[lc]=3;
                    if(s=="DREG"||s=="GT")
                        rgstr[lc]=4;
                    if(s=="GE")
                        rgstr[lc]=5;
                    if(s=="ANY")
                        rgstr[lc]=6;
                    f>>s; //stepping over the comma between the two operands
                    f>>s; //this shal contain a symbol,constant or literal
                    symbol_search(s);
                }
                if(i==9||i==10)
                {
                    lc++;
                    LC[lc]=LC[lc-1]+inc;
                    opcode[lc]=MOT3[i];
                    rgstr[lc]=0;
                    f>>s;
                    symbol_search(s);
                }
                inc=1;
                goto skip;
            }

        }
        ss=s;
        f>>s;
        for(int i=0;i-11;i++)
        {
            if(s==MOT1[i])
            {
                SYMTAB1[ssize]=ss;
                SYMTAB3[ssize]=LC[lc]+1;
                ssize++;
                goto b;
            }
        }
        for(int i=0;i-ssize;i++)
        {
            if(ss==SYMTAB1[i])
            {
                goto lll;
            }
        }
        lc++;
        LC[lc]=LC[lc-1]+inc;
        SYMTAB1[ssize]=ss;
        SYMTAB3[ssize]=LC[lc];

        if(s=="DS")
        {
            f>>n;
            inc=n;
            SYMTAB4[ssize]=n;
        }
        if(s=="DC")
        {
           f>>n;
           inc=1;
           SYMTAB1[ssize]=ss;
           SYMTAB2[ssize]=n;
           SYMTAB4[ssize]=1;
           opcode[lc]="00";
           rgstr[lc]=0;
           memory[lc]=n;
        }
        ++ssize;
        lll : ;
        skip: ;
    }

    return 0;
}
