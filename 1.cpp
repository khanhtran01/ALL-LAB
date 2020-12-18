#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n){
node *head = nullptr;
	node *curr = nullptr;
  for (int i = 0 ; i < n ; i ++)
  {
    node *ptr = new node();
    ifs >> ptr->data;
    ptr-> next = nullptr;
    if (head != NULL)
    {
      curr = head;
      while (curr->next != nullptr)
      {
        curr = curr->next;
      }
      curr->next = ptr;
    } else 
    head = ptr;
    //head ->next = curr;
  }
	return head;
}

node *insertNode(node *head, node *newNode, int position)
{
if (position <= 0) return head;
    else if (position == 1)
    {
      node *inser= new node();
      inser->data=head->data;
      inser->next=head->next;
      head->data=newNode->data;
      head->next = inser;
    }
    else 
    {
      node *ptr = new node();
      node *curr = new node();
      node *temp = new node();
      curr = head;
      ptr= newNode;
      for (int i = 0 ; i < position - 2 && curr->next != nullptr ; i++)
      {
        curr = curr -> next;
      }
      temp = curr -> next;
      curr->next = ptr;
      ptr ->next = temp;
    }
    return head;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);

    node *newNode = new node();
    ifs >> newNode->data;
    int position = 0;
    ifs >> position;
    head = insertNode(head, newNode, position);

    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
