#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/*
Jeremiah Moore a02082167 bled for this.
just hit the big purple button next to run and this'll go along swimmingly

I hope......
*/

std::string findMatch(std::string,  std::vector<std::string>*, std::vector<std::string>*);

int main() {
    bool missing = true;
    std::string line, startWord, endWord, queryWord;
    std::ifstream dictionaryFile ("data/dictionary.txt");
    std::vector<std::string> dictionary, matches;
    std::queue<std::vector<std::string>> matchesList;
    
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
    
    startWord = "pops";
    endWord  = "poop";
    
    //next get two words from the user to use as our start and ends
    std::cout << "Enter your starting word and press enter please: ";
    getline(std::cin, startWord);
    std::cout << std::endl << "Enter your ending word and press enter please: ";
    getline(std::cin, endWord);
    
    //create the inital ladder and add it to the queue
    queryWord = startWord;
    matches.push_back(startWord);
    matchesList.push(matches);

    //while the matchelist is not empty
    while (!matchesList.empty())
    {
        //get the first ladder (should also be the smallest)
        std::vector<std::string> ladder;
        ladder = matchesList.front();
        startWord = ladder[ladder.size()-1];
        //grab all the possible matches and add them to a the queue
        std::string query = "Honestly this is horrible";
        while(query != "")
        {
            query = findMatch(ladder[ladder.size()-1], &dictionary, &ladder);
            if(query == endWord)
            {
                std::cout << "ladder found" << std::endl;
                for(int interator = 0; interator < ladder.size(); interator++)
                { 
                    //wtf is this junk? How do I get rid of it?
                    std::string tmp = ladder[interator];
                    std::cout << tmp << std::endl;
                    //Well it got rid of itself i guess
                }
                std::cout << query << std::endl;
                return 1;
            }
            else if (query == "")
            {   
               break;
            }
            std::vector<std::string> tmpVector = ladder;
            tmpVector.push_back(query);
            matchesList.push(tmpVector);
        }
        //get rid of that ladder it's not needed anymore
        matchesList.pop();
    }

}

std::string findMatch(std::string startWord,  std::vector<std::string>* dictionary, std::vector<std::string>* queue)
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
        if (errs==1 && (std::find((*queue).begin(), (*queue).end(), dictWord) != (*queue).end()) == 0)
        {   
            (*dictionary).erase((*dictionary).begin() + i);
            return dictWord;
        }
    }
    return "";
}