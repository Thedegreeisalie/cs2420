#include "Tree.h"

Tree::Tree(std::string start, std::string end)
{
    std::string line;
    std::vector<std::string> dictionary, sibs;
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
    
    root = new Node(start);
    
    getSibs(root, &dictionary);
}

std::vector<std::string> Tree::getSibs(Node* n, std::vector<std::string>* dictionary)
{
    std::vector<std::string>sibs;
    std::string query = findMatch(n->word, dictionary);

    while(query != "")
    {
        sibs.push_back(query);
        query = findMatch(n->word, dictionary);
        std::cout << query << std::endl;
    }
    return sibs;
}

std::string Tree::findMatch(std::string startWord,  std::vector<std::string>* dictionary)
{
    for(int i =0; i < (*dictionary).size(); i++)
    {
        int errs = 0;
        std::string dictWord = (*dictionary)[i];
        if(startWord.length() == dictWord.length()) 
        {
            for(int j = 0; j < startWord.length(); j++)
            {
                if (startWord[j] != dictWord[j])
                {
                    errs++;
                }
            }
        }
        if (errs==1)
        {   
            (*dictionary).erase((*dictionary).begin() + i);
            return dictWord;
        }
    }
    return "";
}