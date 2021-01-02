
#ifndef ASSIGNMENT3_INPUTREADER_H
#define ASSIGNMENT3_INPUTREADER_H
#include <map>
#include <iostream>
#include <cassert>
#include <string>
using std::string;

class inputReader {
    std::map<std::string, int> opcodes;

public:
    inputReader();
    char[] run(std::string input);

private:
    static void insert_integer_to_char_array(char &arr[], int num, int &offset);
    static void insert_string_to_char_array(char &arr[], string str, int &offset);
    char[] type1(int opcode, string user, string pass);
    char[] type2(int opcode, int courseNumber);
    char[] type3(int opcode, string user);
    char[] type4(int opcode);
};

#endif //ASSIGNMENT3_INPUTREADER_H
