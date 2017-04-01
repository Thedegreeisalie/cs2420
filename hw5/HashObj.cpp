#include "HashObj.h"

// HashObj::HashObj(){};
HashObj::HashObj(int key, std::string& value)
{
    this->info = 1;//0 for empty 1 for active and >1 for deleted
    this->key = key;
    this->value =  value ;
};
HashObj::HashObj()
{
    this->info = 0;
    this->value = "";
}