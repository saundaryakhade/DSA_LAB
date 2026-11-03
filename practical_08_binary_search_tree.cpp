#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int roll;
    string name;
    Node* left;
    Node* right;

    Node(int r, string n)
    {
        roll = r;
        name = n;
        left = right = nullptr;
    }
};

class BST
{
    Node* root;

    Node* insert(Node* node, int roll, string name)
    {
        if (node == nullptr)
            return new Node(roll, name);

        if (roll < node->roll)
            node->left = insert(node->left, roll, name);
        else if (roll > node->roll)
            node->right = insert(node->right, roll, name);
        else
            cout << "Roll number already exists!\n";

        return node;
    }

    Node* search(Node* node, int roll)
    {
        if (node == nullptr || node->roll == roll)
            return node;

        if (roll < node->roll)
            return search(node->left, roll);

        return search(node->right, roll);
    }

    Node* minNode(Node* node)
    {
        while (node && node->left)
            node = node->left;

        return node;
    }

    Node* maxNode(Node* node)
    {
        while (node && node->right)
            node = node->right;

        return node;
    }

    Node* remove(Node* node, int roll)
    {
        if (node == nullptr)
            return nullptr;

        if (roll < node->roll)
            node->left = remove(node->left, roll);

        else if (roll > node->roll)
            node->right = remove(node->right, roll);

        else
        {
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* succ = minNode(node->right);

            node->roll = succ->roll;
            node->name = succ->name;

            node->right = remove(node->right, succ->roll);
        }

        return node;
    }

    void inorder(Node* n)
    {
        if (!n)
            return;

        inorder(n->left);
        cout << n->roll << " - " << n->name << " ";
        inorder(n->right);
    }

    void preorder(Node* n)
    {
        if (!n)
            return;

        cout << n->roll << " - " << n->name << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void postorder(Node* n)
    {
        if (!n)
            return;

        postorder(n->left);
        postorder(n->right);
        cout << n->roll << " - " << n->name << " ";
    }

public:

    BST()
    {
        root = nullptr;
    }

    void insert(int roll, string name)
    {
        root = insert(root, roll, name);
    }

    void findMin()
    {
        Node* n = minNode(root);

        if (n)
            cout << "Smallest roll number: "
                 << n->roll << " - " << n->name << endl;
        else
            cout << "Tree is empty!\n";
    }

    void findMax()
    {
        Node* n = maxNode(root);

        if (n)
            cout << "Largest roll number: "
                 << n->roll << " - " << n->name << endl;
        else
            cout << "Tree is empty!\n";
    }

    void searchStudent(int roll)
    {
        Node* n = search(root, roll);

        if (n)
            cout << "Student FOUND: "
                 << n->roll << " - " << n->name << endl;
        else
            cout << "Student with roll " << roll
                 << " NOT found.\n";
    }

    void predecessor(int roll)
    {
        Node* cur = root;
        Node* pred = nullptr;

        while (cur)
        {
            if (roll > cur->roll)
            {
                pred = cur;
                cur = cur->right;
            }
            else
                cur = cur->left;
        }

        if (pred)
            cout << "Predecessor of " << roll << ": "
                 << pred->roll << " - " << pred->name << endl;
        else
            cout << "No predecessor for " << roll << endl;
    }

    void successor(int roll)
    {
        Node* cur = root;
        Node* succ = nullptr;

        while (cur)
        {
            if (roll < cur->roll)
            {
                succ = cur;
                cur = cur->left;
            }
            else
                cur = cur->right;
        }

        if (succ)
            cout << "Successor of " << roll << ": "
                 << succ->roll << " - " << succ->name << endl;
        else
            cout << "No successor for " << roll << endl;
    }

    void deleteStudent(int roll)
    {
        if (search(root, roll) == nullptr)
        {
            cout << "Roll " << roll
                 << " not found. Cannot delete.\n";
            return;
        }

        root = remove(root, roll);

        cout << "Student with roll "
             << roll << " deleted.\n";
    }

    void display()
    {
        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPreorder: ";
        preorder(root);

        cout << "\nPostorder: ";
        postorder(root);

        cout << endl;
    }
};

int main()
{
    BST tree;

    cout << "===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";

    tree.insert(50, "Aarav");
    tree.insert(30, "Riya");
    tree.insert(70, "Kabir");
    tree.insert(20, "Sneha");
    tree.insert(40, "Rohan");
    tree.insert(60, "Meera");
    tree.insert(80, "Arjun");

    cout << "\nBST Display after inserting records:\n";
    tree.display();

    cout << "\n[1] Minimum key:\n";
    tree.findMin();

    cout << "\n[2] Maximum key:\n";
    tree.findMax();

    cout << "\n[3] Search:\n";
    tree.searchStudent(40);
    tree.searchStudent(99);

    cout << "\n[4] Predecessor:\n";
    tree.predecessor(50);
    tree.predecessor(20);

    cout << "\n[5] Successor:\n";
    tree.successor(50);
    tree.successor(80);

    cout << "\n[6] Delete:\n";
    tree.deleteStudent(20);
    tree.deleteStudent(30);
    tree.deleteStudent(50);
    tree.deleteStudent(99);

    cout << "\n[7] BST Display after deletions:\n";
    tree.display();

    return 0;
}
