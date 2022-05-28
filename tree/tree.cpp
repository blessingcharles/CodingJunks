#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class Node{
public:
    Node* left , *right ;
    int val ;

    Node(int val){
        this->val = val ;
        this->left = NULL ;
        this->right = NULL ; 
    }
};

class Tree{
public:
    static void preorder(Node *head){
        if(not head){
            return ;
        }
        cout << head->val << " " ;
        Tree::preorder(head->left);
        Tree::preorder(head->right);
    }
    static void postorder(Node *head){
        if(not head){
            return ;
        }
        Tree::preorder(head->left);
        Tree::preorder(head->right);
        cout << head->val << " " ;
    }
    static void inorder(Node *head){
        if(not head){
            return ;
        }
        Tree::preorder(head->left);
        cout << head->val << " " ;
        Tree::preorder(head->right);
    }

    static void topView(Node *head){
        queue<pair<Node*,int>> q ;    // {node , side level}
        /* 
            root is at center so 0  

                root 0
               /    \
           -1 l1    r1  1 
              \
              l1r1  0  

            root will hide l1r1 

            1. Perform level order traversal
            maintain a hasmap to store each side level
            1b. if the sidelevel is already present means , the current node is hidden by some other node at top
            2b. else the current node is visible
        */
        
        q.push({head , 0});
        pair<Node* , int> cur_node ;
        unordered_map<int , int> memo ;    // {side level , value }

        while(not q.empty()){
            cur_node = q.front(); q.pop() ;
            if(memo.find(cur_node.second) != memo.end()){
                memo[cur_node.second] = cur_node.first->val ;
            }

            if(cur_node.first->left){
                q.push({cur_node.first->left , cur_node.second-1});
            }
            if(cur_node.first->right){
                q.push({cur_node.first->right , cur_node.second+1});
            }

        }

        // print the top level
        unordered_map<int,int>::iterator it = memo.begin();
        for(;it!=memo.end();it++){
            cout << it->second << " " ;
        }
    }

    static void bottomView(Node* head){
        /*
            the algorithm almost similar to top level
            except in top level , if the side value once occured we don't modify it
            in bottom level , we modify it because we are viewing it from the bottom
        */
        queue<pair<Node* , int>> q ;
        unordered_map<int,int> memo ;
        pair<Node* , int> cur_node ;
        
        while(not q.empty()){
            cur_node = q.front(); q.pop() ;
            memo[cur_node.second] = cur_node.first->val ;

            if(cur_node.first->left){
                q.push({cur_node.first->left , cur_node.second-1});
            }
            if(cur_node.first->right){
                q.push({cur_node.first->right , cur_node.second+1});
            }

        }

        // print the top level
        unordered_map<int,int>::iterator it = memo.begin();
        for(;it!=memo.end();it++){
            cout << it->second << " " ;
        }
    }


};


int main(){

    return 0 ;
}