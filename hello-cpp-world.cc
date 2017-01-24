#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> findMatches(std::string, std::string, std::vector<std::string>*, std::vector<std::string>*);
void printVoFV(std::vector<std::vector<std::string>>*);
void printVector(std::vector<std::string>*);

int main() {
    std::string line, startWord, endWord;
    std::ifstream dictionaryFile ("data/dictionary.txt");
    std::vector<std::string> dictionary, matches;
    std::vector<std::vector<std::string>> matchesList;
    
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
    
    //next get two words from the user to use as our start and ends
    // std::cout << "Enter your starting word and press enter please: ";
    // getline(std::cin, startWord);
    // std::cout << std::endl << "Enter your ending word and press enter please: ";
    // getline(std::cin, endWord);
    
    startWord = "pops";
    endWord  = "poop";
    matches.push_back(startWord);
    matchesList.push_back(matches);
    int k =0;
    while(matchesList[matchesList.size()-1][matchesList[matchesList.size()-1].size()-1] != endWord)
    {
        matchesList.push_back(findMatches(matchesList[matchesList.size()-1][matchesList[matchesList.size()-1].size()-1], endWord, &dictionary, &(matchesList[k])));
        k++;
        printVoFV(&matchesList);
    }
    std::cout << "Hello World!" << std::endl;
}
/*
Take a reference to a vector and return a vector that is one element larger, the last element should be one char different from the second to last element

*/

std::vector<std::string> findMatches(std::string startWord, std::string endWord, std::vector<std::string>* dict, std::vector<std::string>* smallVector)
{
    
    for(int i =0; i < (*dict).size(); i++)
    {
        int errs = 0;
        std::vector<std::string> tmpVector = (*smallVector);
        std::string dictWord=(*dict)[i];
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
            if(std::find(tmpVector.begin(), tmpVector.end(), dictWord) != tmpVector.end())
            {
                tmpVector.push_back(dictWord);
                return tmpVector;
            }
            else
            {
                return findMatches(startWord, endWord, dict, smallVector);
            }
        }
    }
}

void printVector(std::vector<std::string>* vectorToBePrinted)
{
    for(int interator = 0; interator < (*vectorToBePrinted).size()-1; interator++)
    {
        std::cout << (*vectorToBePrinted)[interator] << ", ";
    }
}

void printVoFV(std::vector<std::vector<std::string>>* godThisIsAHugeVector)
{
    for(int iterator0 = 0; iterator0 < (*godThisIsAHugeVector).size()-1; iterator0++)
    {
        printVector(&(*godThisIsAHugeVector)[iterator0]);
        std::cout << std::endl;
    }
}
