/*
filename: BST.cpp
Developer Name: Seonghyun Moon
Date: May 19/2023
Time Complexity:O(n)
*/
#include <iostream>
using namespace std;

class Node
{
     public:
        int value;
        Node *lChild;
        Node *rChild;
        Node(int v, Node* l, Node* r):value(v),lChild(l),rChild(r){}
        Node(int v) :value(v),lChild(nullptr),rChild(nullptr){}
};
class Tree 
{
    public:
        Node* root;

        Tree():root(nullptr){}

        void CreateBinaryTree(int arr[], int size) 
        {
            root=CreateBinaryTree(arr,0,size - 1);
        }
        Node* CreateBinaryTree(int arr[], int start, int end) 
        {
            if (start > end)
            {
                return nullptr;
            }
            int mid = (start + end) / 2;
            Node* node = new Node(arr[mid]);
            node->lChild = CreateBinaryTree(arr, start, mid - 1);
            node->rChild = CreateBinaryTree(arr, mid + 1, end);

            return node;
        }

        void PrintInOrder() 
        {
            PrintInOrder(root);
            cout << endl;
        }
        void PrintInOrder(Node* node) 
        {
            if (node == nullptr)
            {
                return;
            }
            PrintInOrder(node->lChild);
            cout << node->value << " ";
            PrintInOrder(node->rChild);
        }
        //Make a function that makes numbers in Inorder Traversal of BST to print values.
        void InsertNode(int value) 
        {
            root = InsertNode(value, root);
        }
        Node* InsertNode(int value, Node* node) 
        {
            if (node == nullptr)
            {
                return new Node(value);
            }
            if (value < node->value)
            {
                node->lChild = InsertNode(value, node->lChild);
            }
            else if (value > node->value)
            {
                node->rChild = InsertNode(value, node->rChild);
            }
            return node;
        }
        //Make a function that inserts value to Binary search tree. 
        bool Find(int value) 
        {
            Node* current = root;

            while (current != nullptr) 
            {
                if (value == current->value)
                {
                    return true;
                }
                else if (value < current->value)
                {
                    current = current->lChild;
                }
                else
                {
                    current = current->rChild;
                }    
            }

            return false;
        }
        int FindMin() 
        {
            Node* current = root;

            while (current->lChild != nullptr)
            {
                current = current->lChild;
            }
            return current->value;
        }
        //Make a function that finds the node with the minimum value.
        int FindMax() 
        {
            Node* current = root;

            while (current->rChild != nullptr)
            {
                current = current->rChild;
            }
            return current->value;
        }
        //Make a function that finds the node with the maximum value.
        Node* FindMax(Node* cur) 
        {
            while (cur->rChild != nullptr)
            {
                cur = cur->rChild;
            }
            return cur;
        }

        void DeleteNode(int value) 
        {
            root = DeleteNode(root, value);
        }

        Node* DeleteNode(Node* node, int value) 
        {
            if (node == nullptr)
            {
                return nullptr;
            }
            if (value < node->value)
            {
                node->lChild = DeleteNode(node->lChild, value);
            }
            else if (value > node->value)
            {
                node->rChild = DeleteNode(node->rChild, value);
            }
            else 
            {
                if (node->lChild == nullptr) 
                {
                    Node* temp = node->rChild;
                    delete node;
                    return temp;
                }
                else if (node->rChild == nullptr) 
                {
                    Node* temp = node->lChild;
                    delete node;
                    return temp;
                }

                Node* temp = FindMax(node->lChild);
                node->value = temp->value;
                node->lChild = DeleteNode(node->lChild, temp->value);
            }

            return node;
        }
        //Make a function that removes a node from the binary search tree.
};
int main() 
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    Tree bst;
    bst.CreateBinaryTree(arr, size);

    cout << "In-Order Traversal: ";
    bst.PrintInOrder();

    int valueToInsert = 6;
    cout << "Inserting " << valueToInsert << " into the BST."<<endl;
    bst.InsertNode(valueToInsert);

    cout << "In-Order Traversal after insertion: ";
    bst.PrintInOrder();

    int valueToSearch = 3;
    if (bst.Find(valueToSearch))
        cout << valueToSearch << " exists in the BST."<<endl;
    else
        cout << valueToSearch << " does not exist in the BST."<<endl;

    int minValue = bst.FindMin();
    cout << "Minimum value in the BST: " << minValue << endl;

    int maxValue = bst.FindMax();
    cout << "Maximum value in the BST: " << maxValue << endl;

    int valueToDelete = 2;
    cout << "Deleting " << valueToDelete << " from the BST."<<endl;
    bst.DeleteNode(valueToDelete);

    cout << "In-Order Traversal after deletion: ";
    bst.PrintInOrder();

    return 0;
}
