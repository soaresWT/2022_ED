#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value = 0, Node *left = nullptr, Node *right = nullptr)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree
{
    Node *root{nullptr};
    BTree()
    {
    }

    Node *criar(stringstream &ss)
    {
        string data;
        ss >> data;

        if (data == "#")
            return nullptr;

        int value{};
        stringstream(data) >> value;

        Node *node = new Node(value);
        node->left = criar(ss);
        node->right = criar(ss);
        return node;
    }

    BTree(string serial)
    {
        stringstream ss(serial);
        root = criar(ss);
    }

    ~BTree()
    { // destrutor da árvore
        __destroy(this->root);
    }

    void __destroy(Node *node)
    {
        if (node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    void show_in_order()
    {
        cout << "[ ";
        __show_in_order(root);
        cout << "]\n";
    }

    void __show_in_order(Node *node)
    {
        if (node == nullptr)
            return;
        __show_in_order(node->left);
        cout << node->value << " ";
        __show_in_order(node->right);
    }
};

int main()
{
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show_in_order();
}