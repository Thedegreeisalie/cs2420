#include "Node.h"

Node::Node(std::string word)
{
    this->left=nullptr;
    this->sibling=nullptr;
}

Node::Node(std::string word, std::string parent)
{
    Node newbie = Node(word);
    newbie.parent = parent;   
}