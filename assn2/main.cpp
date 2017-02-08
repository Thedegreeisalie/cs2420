#include "Tree.h"
#include <fstream>
#include <iostream>

int main() 
{
    std::string line;
    std::vector<std::string> dictionary;
    std::ifstream dictionaryFile ("data/dictionary.txt");
    //maybe start my reading dictionary into a string vector to make searching easier?
    if (dictionaryFile.is_open())
    {
        while (getline(dictionaryFile, line))
        {
            std::string tmp = line;
            // '\r' at the end of each line  get rid of it 
            dictionary.push_back(tmp.substr(0,tmp.length()-1));
        }
    }
    dictionaryFile.close();
    
    std::string startWord = "pops";
    std::string endWord  = "poop";
    
    std::cout << "wat" << std::endl;
    
    return 0;
}