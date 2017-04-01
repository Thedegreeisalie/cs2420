#ifndef _HASHOBJ_H_
#define _HASHOBJ_H_
//not the fun kind
#include <string>

class HashObj
{
        public:
            unsigned int info;
            HashObj();
            HashObj(int, std::string&);
            int key;
            std::string value;
            
};

#endif