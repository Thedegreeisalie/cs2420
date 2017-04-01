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
    return (array[currentPos].info == 1);
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
    // {
    //     while(isActive(currentPos))
    //     {
    //         currentPos++;
    //     }
    // }
    
    array[currentPos] = x;
    if(++currentSize > (array.size() /2))
        rehash();
        
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
    for (unsigned int i = 0; i < array.size(); i++)
    {
        //I don't know why it prints twice like that and it's really odd.
        std::cout << i << " " << array[i].value << std::endl;
    }
}
void HashTable::rehash()
{
    std::vector<HashObj> OldArray = array;
    //create a double the old size array
    
    array.resize(2*OldArray.size());
    tableSize = array.size();
    for (unsigned int i = 0; i < tableSize; i++)
        array[i] = HashObj();
        
    //copy the old over
    currentSize = 0;
    for (unsigned int j = 0; j < tableSize; j++)
        {
            if(OldArray[j].info == 1)
                insert(OldArray[j]);
                // currentSize += 1;
        }
    
}