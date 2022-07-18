#include <iostream>

#include <bits/stdc++.h>
using namespace std;

void solve(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)  return;
    
    solve(root->right, head);
    root->right = head;
    if (head) head->left = root; 

    head = root;
    solve(root->left, head);
}
TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *head = NULL;
    solve(root, head);
    return head;
}
int main()
{
    
}