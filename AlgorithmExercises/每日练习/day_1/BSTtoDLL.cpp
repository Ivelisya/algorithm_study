#include <iostream>
using namespace std;
#include <list>
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution
{
public:
    // 中序遍历，连接双向链表
    void InOrder(Node *root, Node *&prev, Node *&head)
    {
        if (root == NULL)
            return;

        // 递归左子树
        InOrder(root->left, prev, head);

        // 当前节点处理
        if (prev != NULL)
        {
            prev->right = root; // 上一个节点的右指针指向当前节点
            root->left = prev;  // 当前节点的左指针指向上一个节点
        }
        else
        {
            head = root; // 第一个节点设置为头节点
        }

        prev = root; // 更新前一个节点为当前节点

        // 递归右子树
        InOrder(root->right, prev, head);
    }

    Node *treeToDoublyList(Node *root)
    {
        if (root == NULL)
            return NULL; // 处理空树的情况

        Node *prev = NULL;
        Node *head = NULL;

        // 通过中序遍历将树转换为双向链表
        InOrder(root, prev, head);

        // 由于是双向链表，确保尾节点的右指针指向头节点，头节点的左指针指向尾节点
        if (head != NULL && prev != NULL)
        {
            prev->right = head; // 尾节点指向头节点
            head->left = prev;  // 头节点指向尾节点
        }

        return head; // 返回双向链表的头节点
    }
};
