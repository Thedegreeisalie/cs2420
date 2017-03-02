#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int word, height, l_height, r_height;
        
        Node* left = nullptr;
        Node* right = nullptr;
        
        Node(int);
        ~Node();
};

#endif