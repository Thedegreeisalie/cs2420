#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
    public:
        std::string word;
        std::string parent;
        Node *left;
        Node *sibling;
        Node(std::string);
        Node(std::string, std::string);
};

#endif