#include <iostream>
#include <list>
using namespace std;

int hashWith11(int key)
{
    return key % 11;
}
int hashWith15(int key)
{
    return key % 15;
}
int hashWith17(int key)
{
    return key % 17;
}

class ChainingHash
{
private:
    int (*hash)(int);
    list<int> *data;
    int size;

public:
    ChainingHash()
    {
        throw "Cannot create a hash with no hash function!";
    }

    ChainingHash(int size, int (*hash)(int))
    {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }

    void Insert(int key)
    {
        int slot = this->hash(key);
        this->data[slot].push_front(key);
    }

    void Remove(int key)
    {
        int slot = this->hash(key);
        data[slot].remove(key);
    }

    bool search(int key)
    {
        int slot = this->hash(key);
        list <int> temp = data[slot];
        for ( int i = 0 ; i < temp.size(); i++)
        {
            if (temp.back() == key)
            return 1;

            temp.pop_back();
        }
        return false;
    }
    int count()
    {
        int total = 0;
        for (int i = 0; i < this->size; i++)
        {
            total += this->data[i].size();
        }
        return total;
    }

    void dump()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};