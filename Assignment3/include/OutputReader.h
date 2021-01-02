
#ifndef ASSIGNMENT3_OUTPUTREADER_H
#define ASSIGNMENT3_OUTPUTREADER_H

#include <map>
#include <iostream>
#include <cassert>
#include "connectionHandler.h"

class OutputReader {
private: bool terminate=false;
public:
    OutputReader(const std::string& host, int port, ConnectionHandler &connectionHandler);
    bool shouldTerminate() const;
    void run(const std::string& host, int port, ConnectionHandler &connectionHandler);
};


#endif //ASSIGNMENT3_OUTPUTREADER_H
