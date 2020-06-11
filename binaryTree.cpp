//
// Created by stepanai on 12.06.2020.
//

#include <iostream>
#include "binaryTree.h"

binaryTree::binaryTree() {
    _root=nullptr;
}

void binaryTree::add(int data) {
    addNode(_root,data);
}

binaryTree::nodeTree* binaryTree::addNode(binaryTree::nodeTree *&root, int data) {
    if (!root){
        nodeTree *pnew = new nodeTree;
        pnew->data=data;
        pnew->left=nullptr;
        pnew->right=nullptr;
        root=pnew;
        return pnew;
    }
    else {
        if (data<root->data)
            return addNode(root->right,data);
        else
            return addNode(root->left,data);
    }
}

void binaryTree::print() const{
    printTree(_root,0);
}

void binaryTree::printTree(binaryTree::nodeTree const*p, int level) const{
    if (p){
        printTree(p->right, level+1);
        for (int i=0;i<level;i++)std::cout<<"    ";
        std::cout<<p->data<<std::endl;
        printTree(p->left, level+1);
    }
}

void binaryTree::deleteTree(binaryTree::nodeTree *&root) {
    if (!root)
        return;
    //if (root->left)
    deleteTree(root->left);
    //if (root->right)
    deleteTree(root->right);
    delete root;
}

binaryTree::~binaryTree() {
    deleteTree(_root);
}

int binaryTree::leafCount(binaryTree::nodeTree const*root) const{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    return leafCount(root->left)+leafCount(root->right);
}

int binaryTree::leafCount() const{
    return leafCount(_root);
}

void binaryTree::toHeapy(binaryTree::nodeTree *current) {
    nodeTree *parr=parrent(_root,current);
    if (parr)
        if (current->data>parr->data){
            int temp=current->data;
            current->data=parr->data;
            parr->data=temp;
            toHeapy(parr);
        }
}

binaryTree::nodeTree *binaryTree::parrent(binaryTree::nodeTree *root, binaryTree::nodeTree *current) const{
    if (!current || current==root)
        return nullptr;
    if (root){
        if (current->data<root->data){
            if (root->right->data==current->data)
                return root;
            else
                return parrent(root->right,current);
        }
        else{
            if (root->left->data==current->data)
                return root;
            else
                return parrent(root->left,current);
        }
    }
    return 0;
}

void binaryTree::addHeapy(int data) {
    toHeapy(addNode(_root,data));
}