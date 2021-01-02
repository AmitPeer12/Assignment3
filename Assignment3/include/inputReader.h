
#ifndef ASSIGNMENT3_INPUTREADER_H
#define ASSIGNMENT3_INPUTREADER_H
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../include/connectionHandler.h"
using std::string;

class inputReader {
    std::map<std::string, int> opcodes;

public:
    inputReader();
    void run(string input,ConnectionHandler& connectionHandler);


private:
    static void insert_integer_to_char_array(char *arr, int num, int &offset);
    static void insert_string_to_char_array(char *arr, string str, int &offset);
    void type1(int opcode,string& input,ConnectionHandler &connectionHandler);
    void type2(int opcode,string& input,ConnectionHandler &connectionHandler);
    void type3(int opcode,string& input,ConnectionHandler &connectionHandler);
    void type4(int opcode,ConnectionHandler &connectionHandler);
    std::string split(string&);
};

#endif //ASSIGNMENT3_INPUTREADER_H
