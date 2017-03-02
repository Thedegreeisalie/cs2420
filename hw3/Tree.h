#ifndef _TREE_H_
#define _TREE_H_

#include "Node.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class Tree
{
    private:
        Node* root = nullptr;
    public:
        
        Tree();
        Tree(std::string);
        ~Tree();
        void insertNode(int, Node*);
        void printTree(Node*);
        void printTree(Node*, std::ofstream&);
        void printTree(Node*, std::ofstream&, std::string);
        int calcNodeHeight(Node*);
        int calcTreeHeight();
};

#endif