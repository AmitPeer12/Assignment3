
#ifndef ASSIGNMENT3_OUTPUTREADER_H
#define ASSIGNMENT3_OUTPUTREADER_H

#include <map>
#include <iostream>
#include <cassert>
class outputReader {
private: bool terminate=false;
public:
    bool shouldTerminate();
    void run(std::string host, int port);
};


#endif //ASSIGNMENT3_OUTPUTREADER_H
