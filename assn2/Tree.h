#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>

class Tree
{
    private:
        Node* root;
        std::vector<std::string> dict;
        std::vector<std::string> fam;
        std::string startWord;
        std::string endWord;
    
    public:
        Tree();
        void buildTree(std::string, std::string);
        void buildLevel(Node*, std::vector<std::string>);
        std::vector<std::string>getSibs(Node*);
        void printTree(Node*, std::string);
};


#endif