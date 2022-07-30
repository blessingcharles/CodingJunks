#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

struct AVLNode{
    AVLNode* left , *right  ;
    int data , height ;
    
    AVLNode(int val){
        data = val ;
        left = NULL ; right = NULL ;
        height = 1 ;
    }
    int balance_factor(){
        if(not left and not right){
            return 0 ;
        }
        if(not left) 
            return -(right->height) ;
        if(not right)
            return left->height ;
        
        return (left->height - right->height) ;
    }
};

class AVLTree{
public:
    AVLNode* root ;
    AVLTree(){
        root = NULL ;
    }
    int getHeight(AVLNode* node){
        if(not node) return 0 ;
        return node->height ;
    }
    AVLNode* rightRotate(AVLNode* node){
        AVLNode* ll = node->left ;
        AVLNode* llr = ll->right ;
        ll->right = node ;
        node->left = llr ;
        node->height = max(getHeight(node->left) , getHeight(node->right))+1 ;
        ll->height = max(getHeight(ll->left) , getHeight(ll->right))+1 ;

        return ll ;
    }
    AVLNode* leftRotate(AVLNode* node){
        AVLNode* rr = node->right ;
        AVLNode* rrl = rr->left ;

        rr->left = node ;
        node->right = rrl ;
        node->height = max(getHeight(node->left) , getHeight(node->right))+1 ;
        rr->height = max(getHeight(rr->left) , getHeight(rr->right))+1 ;

        return rr ;
    }
    AVLNode* _insert(AVLNode* node , int data){
        if(not node){
            return new AVLNode(data);
        }
        if(data < node->data){
            node->left = _insert(node->left , data);
        }
        else if(data > node->data){
            node->right = _insert(node->right , data) ;
        }
        node->height = max(getHeight(node->left) , getHeight(node->right))+1 ;

        int bf = node->balance_factor() ;
        if(abs(bf) <= 1) return node ;

        //ll imbalance perform right rotation
        if(bf > 1 and node->left->data > data){
            return rightRotate(node);
        }
        // lr imbalance left rotate and right rotate
        else if(bf > 1 and node->left->data < data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // rr imbalance
        else if(bf < 1 and node->right->data < data){
            return leftRotate(node);
        }
        // rl imbalance 
        node->right = rightRotate(node->right);
        return leftRotate(node);

    }
    void insert(int data){
        root = _insert(root , data);
    }
    void preorder(AVLNode* root){
        if(not root) return ;
        cout << root->data << " " ;
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){
    AVLTree *t = new AVLTree() ;
    t->insert(10);
    t->insert(20);
    t->insert(30);
    t->insert(40);
    t->insert(50);
    t->insert(25);

    t->preorder(t->root);
}