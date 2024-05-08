#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

    // insert node helper function
    Node *insert(Node *node, int data)
    {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    // inorder traversal helper function
    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // helper function: preorder traversal
    void preorderTraversal(Node *node)
    {
        cout << node->data << endl;
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // helper function: preorder traversal
    void postorderTraversal(Node *node)
    {
        preorderTraversal(node->left);
        preorderTraversal(node->right);
        cout << node->data << endl;
    }

public:
    BinaryTree() : root(nullptr) {}

    // insert node
    void insert(int data)
    {
        root = insert(root, data);
    }

    // inorder traversal
    void inorderTraversal()
    {
        inorderTraversal(root);
        cout << endl;
    }

    // preorder traversal
    void preorderTraversal()
    {
        preorderTraversal(root);
        cout << endl;
    }

    // preorder traversal
    void postorderTraversal()
    {
        postorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree b;

    b.insert(5);
    b.insert(2);
    b.insert(10);
    b.insert(6);
    b.insert(1);

    b.inorderTraversal();
    b.preorderTraversal();
    b.postorderTraversal();
    return 0;
}