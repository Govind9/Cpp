#include<iostream>
using namespace std;
class link
{
    int data;
    link *next;
public:
    link* insrt(link*s)
    {
        int range;
        cout<<"how many u wanna insert\n";
        cin>>range;
        for(int i=0;i<range;i++)
        {
            int d;
            cout<<"enter element\n";
            cin>>d;
            link * ne;
            ne=new link;
            ne->data=d;
            ne->next=NULL;
            if(s==NULL)
                s=ne;
            else
            {
                link*s1=s;
                while(s1->next!=NULL)
                    s1=s1->next;
                    s1->next=ne;
            }}
            return s;

            }
        link * remv(link*s)
        {
            if(s==NULL)
            {
                cout<<"underflow\n";
                return NULL;
            }
            int d;
            cout<<"enter the data to be deleted\n";
            cin>>d;
            if(d==s->data)
            {
                cout<<"deleted\n";
                s=s->next;
            }
            else
            {
                link *s1=s;
                while(s1->next!=NULL)
                {
                    if(s1->next->data==d)
                    {
                        cout<<"deleted\n";
                        s1->next=s1->next->next;
                        return s;
                    }
                    s1=s1->next;
                }
                cout<<"not found\n";
            }
            return s;
        }
    void traverse(link*s)
    {
        if(s!=NULL)
        {
            link*s1=s;
            while(s1->next!=NULL)
            {
                cout<<s1->data<<endl;
                s1=s1->next;
            }
            if(s1->next==NULL)
                cout<<s1->data<<endl;
        }
        else
            cout<<"list is empty\n";
    }
};
int main()
{
    link* head;
    head=NULL;
    int ch;
    do
    {
        cout<<"1-insrt,2-dlt,3-show,0-exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: head=head->insrt(head);
            break;
            case 2 : head=head->remv(head);
            break;
            case 3: head->traverse(head);
            break;
            case 0:
                break;
        }
    }
    while(ch!=0);
    return 0;
}
