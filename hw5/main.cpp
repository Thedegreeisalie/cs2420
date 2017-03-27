#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <vector>


/*
Pick your 20 favorite fruit from the list provided.
Begin with a hashtable of size 10
Insert your fruit into the table, printing the table (using printTable()) after inserting elements 4,5,9,10,20.  I want to see your inserts working, and your rehash function working after the table fills up by half.
After inserting 20 items, run the find() function on your 3 favorite fruit.  (to show me your find function works)
Delete your 3 least favorite fruit in the list.  As mentioned, marking as deleted is fine.  Then run the find() function on these same 3 fruit to show me they are gone.  A simple message “item not found” is fine.  You do not need to rehash after deleting 3 items.
Print your tree again after the 3 items have been deleted
*/


int main() {

    std::string line;
    std::ifstream numberFile("fruit.csv");
    
    //keeper of the keys
    std::vector<unsigned int> hagrid;
    std::vector<std::string> maxime;
    
    if (numberFile.is_open())
    { 
        //the first element of the csv is the title headers
        getline(numberFile, line);
        //just throw everything into some vectors so that they can be accessed quickly
        while (getline(numberFile, line))
        {
            // std::cout << line << std::endl;
            std::string key = line.substr(0, line.find(","));
            // std::cout << key << std::endl;
            std::string value = line.substr(line.find(",")+1, line.length());
            // std::cout << value << std::endl;
            maxime.push_back(value);
            hagrid.push_back(std::stoi(key));
        }
        numberFile.close();
    }

    /*
    Pick your 20 favorite fruit from the list provided
        How about the first twenty?
    */
    for (unsigned int i =0; i < 20; i++)
    {
        //insert them into the hashtable
    }
    
    return 0;
}