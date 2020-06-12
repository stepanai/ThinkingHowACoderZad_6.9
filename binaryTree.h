//
// Created by stepanai on 12.06.2020.
//

#ifndef ZAD_6_9_BINARYTREE_H
#define ZAD_6_9_BINARYTREE_H


class binaryTree {
public:
    binaryTree();
    ~binaryTree();
    int leafCount()const;
    void add(int data);
    void addHeapy(int data);
    void print()const ;

private:
    struct nodeTree{
        int data;
        nodeTree *left;
        nodeTree *right;
    };
    void toHeapy(nodeTree* current)const;
    nodeTree const* parrent(nodeTree const*root, nodeTree const*current) const;
    nodeTree* addNode(nodeTree *&root,int data);
    void printTree(nodeTree const*p, int level)const;
    void deleteTree(nodeTree *&root);
    int leafCount(nodeTree const*root)const;

    nodeTree *_root;
};


#endif //ZAD_6_9_BINARYTREE_H
