

#include <vector>
#include <string>
#include <iostream>

#include "HashObj.h"

//this template can be found in the class textbook pg 205
class HashTable
{
    public:
        HashTable();
        //constructor doesn't have to do anything
        int tableSize = 10;
        //there should be more logic to this other then passing the key as a string but there isn't
        unsigned int hashFunction(HashObj &);
        
        bool contains (HashObj) ;
        
        //used just by the constructor for fun
        void makeEmpty();
        bool insert(HashObj & );
        int findNext(HashObj &);
        bool remove(HashObj & );
        
        void printTable();
        
        std::string find(int key);

    private:

        std::vector<HashObj> array;
        int currentSize;
        
        bool isActive(int currentPos ) ;
        
        int findPos(HashObj&);
        
        void rehash();
        
};
