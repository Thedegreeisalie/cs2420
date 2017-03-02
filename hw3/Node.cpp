#include "Node.h"

Node::Node(int initWord){
    this->word = initWord;
}

Node::~Node()
{
    delete left;
    delete right;
}