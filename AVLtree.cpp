#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    Node *RotateLeft(Node *root)
    {
        Node *newRoot = root->pRight;
        Node *temp = newRoot->pLeft;

        newRoot->pLeft = root;
        root->pRight = temp;

        return newRoot;
    }

    Node *RotateRight(Node *root)
    {
        Node *newRoot = root->pLeft;
        Node *temp = newRoot->pRight;

        newRoot->pRight = root;
        root->pLeft = temp;

        return newRoot;
    }

    int checkBalance(Node *root)
    {
        return getHeightRec(root->pRight) - getHeightRec(root->pLeft);
    }

    Node *InsertRecur(Node *root, T value)
    {
        if (root == nullptr)
        {
            Node *newptr = new Node(value);
            root = newptr;
            root->balance = EH;
            return root;
        }
        if (root->data <= value)
            root->pRight = InsertRecur(root->pRight, value);
        if (root->data > value)
            root->pLeft = InsertRecur(root->pLeft, value);

        int check = checkBalance(root);

        if (check < -1 && root->pLeft->data > value)
            return RotateRight(root);
        if (check > 1 && root->pRight->data <= value)
            return RotateLeft(root);
        if (check < -1 && root->pLeft->data <= value)
        {
            root->pLeft = RotateLeft(root->pLeft);
            return RotateRight(root);
        }
        if (check > 1 && root->pRight->data > value)
        {
            root->pRight = RotateRight(root->pRight);
            return RotateLeft(root);
        }

        return root;
    }

    Node *RemoveRecur(Node *root, T value)
    {
        if (root == nullptr)
            return root;
        if (root->data == value)
        {
            Node *temp = maxValueRoot(root->pLeft);
            if (temp != nullptr)
            {
                root->data = temp->data;
                root->pLeft = RemoveRecur(root->pLeft, temp->data);
                return root;
            }
            else
            {
                temp = root->pRight;
                delete root;
                root = nullptr;
                return temp;
            }
        }

        if (root->data <= value)
            root->pRight = RemoveRecur(root->pRight, value);
        if (root->data > value)
            root->pLeft = RemoveRecur(root->pLeft, value);
        int check = checkBalance(root);

        if (check > 1 && root->pRight->data >= value)
            return RotateLeft(root);
        if (check < -1 && root->pLeft->data < value)
            return RotateRight(root);

        if (check < -1 && root->pLeft->data >= value)
        {
            root->pLeft = RotateLeft(root->pLeft);
            return RotateRight(root);
        }
        if (check > 1 && root->pRight->data < value)
        {
            root->pRight = RotateRight(root->pRight);
            return RotateLeft(root);
        }
        return root;
    }

    void insert(const T &value)
    {
        //TODO
        this->root = InsertRecur(this->root, value);
    }

    Node *maxValueRoot(Node *root)
    {
        Node *current = root;
        if (current == nullptr)
            return current;
        while (current->pRight != nullptr)
        {
            current = current->pRight;
        }
        return current;
    }

    void remove(const T &value)
    {
       this->root = RemoveRecur(this->root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
int main()
{
    AVLTree<int> avl;
    int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63, 99, 100};
    for (int i = 0; i < 12; i++)
    {
        avl.insert(arr[i]);
    }
    for (int i = 11; i >= 0; i--)
    {
        avl.remove(arr[i]);
    }
    avl.printTreeStructure();
}