#ifndef _TREE_H_
#define _TREE_H_

#include "Node.h"
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>

class Tree
{
    private:
        Node* root;
        std::vector<std::string> dict;
        std::vector<std::string> fam;
        std::string startWord;
        std::string endWord;
    
    public:
        Tree(std::string, std::string);
        void buildLevel(Node*, std::vector<std::string>, std::string, std::vector<std::string>);
        std::vector<std::string>getSibs(Node*, std::vector<std::string>*);
        void printTree(Node*, std::string);
        std::string findMatch(std::string, std::vector<std::string>*);
};


#endif