#include <iostream>

using namespace std;
class node
{
public:
    char info;
    node *link;
    node * push(node *para)

    {
        cout<<"Enter the element\n";
        char d;
        cin>> d;
        node *ne=new node;
        ne->info=d;
        ne->link=NULL;
        if(para==NULL)
        {
            para=ne;

        }
        else
        {
            para->link=ne;
            para=ne;
        }
        return para;
    }
    node * pop(node * para,node * para1)
    {
        if(para==NULL)
            cout<<"Underflow\n";
        else
        {
            node *temp=para1;
            while(temp->link->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=NULL;
        }
        return para;
    }
    void show(node * para,node *para1)
    {
        if(para==NULL)
            cout<<"Stack is empty\n";
        else
        {
            node * temp=para1;
            while(temp->link!=NULL)
            {
                cout<<temp->info<<" ";
                temp=temp->link;
            }
            cout<<temp->info<<endl;
        }
    }
    node * concept(node *para)
    {
        return para;
    }
};


int main()
{
    node *top=NULL;
    node *first=NULL;

    int ch;
    int i=0,j=0;
     do
    {
        i++;
        cout<<"1-push,2-pop,3-show,0-exit\n";
        cin>>ch;
        if(ch==1)
        {
            j++;
        }
        switch(ch)
        {
            case 1: {top=top->push(top);
                     if(i==1||j==1)
                        first=top->concept(top);}

            break;
            case 2 : top=top->pop(top,first);
            break;
            case 3: top->show(top,first);
            break;
            case 0:
                break;
        }
    }
    while(ch!=0);
    return 0;
}
