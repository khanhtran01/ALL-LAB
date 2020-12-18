#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class K, class D, int M> // K: key, D: data, M: order
class BTree {
    /// Convention: Left sub-tree < Root's key <= Right sub-tree

public:
    class Entry;
    class Node;

private:
    Node* root;

public:
    BTree() : root(0) { }
    ~BTree() { }

    ///////////////////////////////////////////////////
    ///             CLASS `Entry`                   ///
    ///////////////////////////////////////////////////
public:
    class Entry {
    private:
        K key;
        D data; // accept all type
        Node* rightPtr;
        friend class BTree<K, D, M>;

    public:
        Entry(K key = K{}, D value = D{}) : key(key), data(value), rightPtr(0) {}
        ~Entry() { }
        string toString() {
            stringstream ss;
            ss << "<"
               << this->key << ","
               << this->data
               << ">";
            return ss.str();
        }
    };

    ///////////////////////////////////////////////////
    ///             CLASS `Node`                    ///
    ///////////////////////////////////////////////////
public:
    class Node {
    private:
        Node* firstPtr;
        int numEntries;
        Entry entries[M-1];

        friend class BTree<K, D, M>;

    public:
        Node() : firstPtr(0), numEntries(0) {};

        ~Node() { }
        string toString() {
            // hidden code
            return ss.str();
        }
        bool isFull() {
            return (numEntries >= M-1);
        }
    };

    /////////////////////////////////////////////////////////////
    ///         CLASS `BTree`: method implementation          ///
    /////////////////////////////////////////////////////////////
public:
    string toStringPreOrder();
    void insert(const K& key, const D& data);

    /// BEGIN STUDENT CODE
    /// ==================================================
    /// search(key, outNodePtr, outEntryIdx)
    bool search(const K& key, Node*& outNodePtr, int& outEntryIdx) {
        int i = M-1;
        while(key < this->root->entries[i])
        {
            i--;
            if ( i == 0)
            {
                
            }
        }
        if (key > this->root->entries[M-1])
        {

        }
    }
    /// END STUDENT CODE
};