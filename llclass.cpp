#include<iostream>

using namespace std;

class LinkedList
{
    struct Linked
    {
        int data;
        Linked *node;
    } *lob;

public:
    void accept()
    {
        Linked *temp = new Linked;
        cout<<"\nEnter Data";
        cin>>temp->data;
        temp->node=NULL;
        temp->node=lob;
        lob=temp;
        delete temp;

    }


    void searchval()
    {
        int c;
        int i=0, flag =1;
        cout<<"\nEnter data to be searched?";
        cin>>c;
        Linked *temp = new Linked;
        temp=lob;
        while(temp)
        {
            if(temp->data==c)
            {
                cout<<"\ndata found at position= "<<i;
                flag++;
            }
            temp=temp->node;
            if(flag!=1)
                cout<<"\ndata was never found!!!";
        }

    }


    void Delete()
    {
        Linked *temp = new Linked;
        temp=lob;
        lob=lob->node;
        cout<<"\DATA DELETED !!!!!"<<temp->data;
        delete temp;

    }
};


main()
{
    LinkedList lob1;
    lob1.accept();
    lob1.searchval();
    lob1.Delete();
}
