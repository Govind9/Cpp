#include<iostream>
#include<cstring>
using namespace std;
class node
{
public:
    string info;
    node *link;
	node *b1,*b2,*b3;
	node *head;
	node()
	{
		b1=NULL;
		b2=NULL;
		b3=NULL;
		head=NULL;
	}
    node * push(node *para,string d)

    {
        node *ne=new node;
        ne->info=d;
        ne->link=NULL;
        if(para==NULL)
        {
            para=ne;
			para->head=para;
        }
        else
        {
            para->link=ne;
            para=ne;
        }
		ne->b1=ne->bck(ne);
		ne->b2=ne->bck(b1);
		ne->b3=ne->bck(b2);
        return para;

    }
    node * pop(node * para)
    {
        if(para==NULL)
            cout<<"Underflow\n";
        else
        {
            node *temp=para->head;
            while(temp->link->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=NULL;
        }
        return para;
    }
    void show(node * para)
    {
        if(para==NULL)
            cout<<"Stack is empty\n";
        else
        {
            node * temp=para->head;
            while(temp->link!=NULL)
            {
                cout<<temp->info<<" ";
                temp=temp->link;
            }
            cout<<temp->info<<endl;
        }
    }
	node *bck(node *para)
	{
	node *temp=para->head;
	while(temp->link!=NULL)
	{
		if(temp->link==para)
			return temp;
		temp=temp->link;
	}
	return NULL;
	}
};

int main()
{
	string postfix;
	cout<<"Enter a valid postfix expression\n";
	getline(cin,postfix);
	node *top=NULL;
	int i=0;
	while(postfix[i]!=' ')
	{
		top=top->push(top,"postfix[i]");
		i++;
	}
	return 0;
}
