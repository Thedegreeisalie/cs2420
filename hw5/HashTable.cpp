#include "HashTable.h"

HashTable::HashTable()
{
    makeEmpty();
}

unsigned int HashTable::hashFunction(HashObj & x)
{
    return (x.key % tableSize);
}

bool HashTable::contains (HashObj x) 
{
    return isActive( findPos( x ));
}

void HashTable::makeEmpty()
{
    currentSize = 0;
    for (int i =0; i < tableSize; i++)
    {
        array.push_back(HashObj());
    }
        
}

bool HashTable::isActive(int currentPos ) 
{
    return array[currentPos].info == 1;
}

int HashTable::findPos(HashObj & x) 
{
    int offset = 1;
    int currentPos = hashFunction(x);
    
    while( array[ currentPos ].info != 0 && array[ currentPos ].value != x.value)
    {
        currentPos += offset; //Ith probe
        offset += 1;
        if (currentPos >= array.size())
            currentPos -= array.size();
    }
    
    return currentPos;
};

bool HashTable::insert(HashObj & x)
{
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return false;
        
    array[currentPos] = x;
    if(++currentSize > array.size() /2)
        //rehash();
        
    return true;
}
bool HashTable::remove(HashObj & x)
{
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;
    
    array[currentPos].info = 2;
        return true;
}

void HashTable::printTable()
{
    std::cout << "start table"<< std::endl;
    for (unsigned int i = 0; i < tableSize; i++)
    {
        std::cout << array[i].value << std::endl;
    }
}