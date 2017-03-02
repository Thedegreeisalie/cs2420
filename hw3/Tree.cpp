#include "Tree.h"

// Tree::Tree()
// {
//     std::string nodeToInsert;
//     std::cout << "Enter a number you want to insert into the BST, integers only please" << std::endl;
//     std::cin >> nodeToInsert;
//     root = new Node(std::stoi(nodeToInsert));
    
//     while(nodeToInsert != "q")//in reality anything not int will quit and this could be replaced by while(true)
//     {
//         std::cout << "Enter a number you want to insert into the BST, integers only please" << std::endl;
//         std::cin >> nodeToInsert;
//         int newbie = std::stoi(nodeToInsert);
//         std::cout << "Inserting works" << std::endl;
//         insertNode(newbie, root);
//         printTree(root);
//     }
// }

Tree::Tree(std::string numberFileName)
{
    std::string nodeToInsert;
    std::ifstream numberFile (numberFileName);
    std::ofstream outFile ("out.txt");
    //reading part
    if (numberFile.is_open())
    {
        while (getline(numberFile,nodeToInsert))
        {
            insertNode(std::stoi(nodeToInsert), root);
            //writing part
            printTree(root, outFile, " ");
            outFile << "tree size: \n";
            // std::cout << nodeToInsert << std::endl;
        }
        numberFile.close();
    }
}

Tree::~Tree() 
{
    //todo: figure out how to get this to not destroy the tree until it's called.
    delete root;
}
void Tree::insertNode(int newbie, Node *location) 
{
    if(location == nullptr)
    {
        this->root = new Node(newbie);
    }
    else if (location->word > newbie)
    {
        if (location->left != nullptr)
        {
            insertNode(newbie, location->left);
        }
        else 
        {
            location->left = new Node(newbie);
        }
    }
    else if (location->word < newbie)
    {
        if (location->right != nullptr)
        {
            insertNode(newbie, location->right);
        }
        else 
        {
            location->right = new Node(newbie);
        }
    }
    else 
    {
        std::cout << "Um hey.. it looks like you already inserted that" << std::endl;
    }
}
// //to overload or not to overload that is a good question...
void Tree::printTree(Node* n)
{
    if (n->left != nullptr)
    {
            printTree(n->left);
    }
    std::cout << n->word << " ";
    if (n->right != nullptr)
    {
            printTree(n->right);
    }
}
// //meh I did it.
// void Tree::printTree(Node* n, std::ofstream& getOutFile)
// {
//     if (getOutFile.is_open())
//     {
//         getOutFile << n->word << " ";
//     }
//     if (n->left != nullptr)
//     {
//             printTree(n->left, getOutFile);
//     }
//     if (n->right != nullptr)
//     {
//             printTree(n->right, getOutFile);
//     }
// }
// this is excessive
void Tree::printTree(Node* n, std::ofstream& getOutFile, std::string tabs)
{
    if (tabs.size() != 0)
    {
        tabs = tabs + " ";
    }

    if (n->left != nullptr)
    {
            printTree(n->left, getOutFile, tabs);
    }
    if (getOutFile.is_open())
    {
        getOutFile << tabs << n->word << "\n";
    }
    if (n->right != nullptr)
    {
            printTree(n->right, getOutFile, tabs);
    }
}

int calcNodeHeight()
{
    
}