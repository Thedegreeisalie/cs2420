#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Node
{
    public:
        std::string word;
        
        Node* left = nullptr;
        Node* right = nullptr;
        
        Node(std::string);
};

#endif