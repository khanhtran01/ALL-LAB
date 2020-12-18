#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)
{
    node *head = nullptr;
    node *curr = nullptr;
    for (int i = 0 ; i < n ; i++)
    {
    
    node *ptr = new node();
    ifs >> ptr->data;
    ptr -> next = nullptr;
    if ( head != nullptr)
    {  
        curr=head;
        while (curr->next != nullptr)
        {
            curr = curr->next;

        }
        curr->next=ptr;
    }
    else head = ptr;
}
return head;
}

bool isEqual(node *head1, node *head2)
{
int i=0 , j =0;
    node *curr1 = new node();
    curr1 = head1;
    while (curr1 != nullptr)
    {
        i++;
        curr1=curr1->next;
    }
     node *curr2 = new node();
     curr2 = head2;
    while (curr2 != nullptr)
    {
        j++;
        curr2=curr2->next;
    }
    if (i!=j) return 0;
    else {
        while (head1 != nullptr)
        {
            if (head1->data != head2->data) return 0;
            head1 = head1->next;
            head2 = head2->next;
        }
        
    }return 1;
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n <= 0)
  {
    cout << "Invalid n" << endl;
    return 0;
  }
  node *head1 = createLinkList(n);

  int m = 0;
  ifs >> m;
  if (m <= 0)
  {
    cout << "Invalid m" << endl;
    return 0;
  }
  node *head2 = createLinkList(m);

  cout << isEqual(head1, head2) << endl;

  ifs.close();
  return 0;
}
