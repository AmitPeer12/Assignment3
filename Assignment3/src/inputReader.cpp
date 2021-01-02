#include "../include/inputReader.h"
#include "../include/connectionHandler.h"
#include <string>

//Constructor
inputReader::inputReader() {
    opcodes.insert({"ADMINREG",1});
    opcodes.insert({"STUDENTREG",2});
    opcodes.insert({"LOGIN",3});
    opcodes.insert({"LOGOUT",4});
    opcodes.insert({"COURSEREG",5});
    opcodes.insert({"KDAMCHECK",6});
    opcodes.insert({"COURSESTAT",7});
    opcodes.insert({"STUDENTSTAT",8});
    opcodes.insert({"ISREGISTERED",9});
    opcodes.insert({"UNREGISTER",10});
    opcodes.insert({"MYCOURSES",11});
}
void inputReader::run(string input,ConnectionHandler &connectionHandler){
    string task = split(input);
    int opcode = opcodes.at(task);
    switch (opcode) {
        case 1:
        case 2:
        case 3:
             type1(opcode,input,connectionHandler);
        case 4:
        case 11:
             type4(opcode,connectionHandler);
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
             type2(opcode,input,connectionHandler);
        case 8:
             type3(opcode,input,connectionHandler);
        default:
            std::cout<<"Illegale Argument"<< std::endl;
    }
}

 void inputReader::insert_string_to_char_array(char *arr, string str, int &offset) {
    for(int i=0; i<str.length(); i++) {
        arr[offset+i] = str[i];
    }
    offset+=str.length();
}
 void inputReader::insert_integer_to_char_array(char *arr, int num, int &offset) {
    arr[offset] = num;
    offset+=1;
}
void inputReader::type1(int opcode,string& input,ConnectionHandler &connectionHandler) {
    string userName = split(input);
    string password = split(input);
    int messageSize = 4 + userName.length() + password.length();
    char output [messageSize];
    int offset = 0;
    insert_integer_to_char_array(output, 0, offset);
    insert_integer_to_char_array(output, opcode, offset);
    insert_string_to_char_array(output, userName, offset);
    insert_integer_to_char_array(output, 0, offset);
    insert_string_to_char_array(output, password, offset);
    insert_integer_to_char_array(output, 0, offset);
    //bufSize?
    connectionHandler.sendBytes(output,messageSize);
};

void inputReader::type2(int opcode,string& input,ConnectionHandler &connectionHandler) {
    string courseNumber = split(input);
    int course = std::stoi(courseNumber);
    char output [4];
    output[0] = 0;
    output[1] = opcode;
    output[3] = ((course>>8) & 0xff);
    output[4] = (course&0xff);
//bufSize?
    connectionHandler.sendBytes(output,4);

}
void inputReader::type3(int opcode,string& input,ConnectionHandler &connectionHandler) {
    string userName = split(input);
    int messageSize = userName.length() + 3;
    int offset = 0;
    char output [messageSize];
    insert_integer_to_char_array(output,0,offset);
    insert_integer_to_char_array(output,opcode,offset);
    insert_string_to_char_array(output,userName,offset);
    insert_integer_to_char_array(output,0,offset);
    connectionHandler.sendBytes(output,messageSize);
}
void inputReader::type4(int opcode,ConnectionHandler &connectionHandler) {
    char output[2];
    int offset = 0;
    insert_integer_to_char_array(output, 0, offset);
    insert_integer_to_char_array(output, opcode, offset);
    //bufSize?
    connectionHandler.sendBytes(output,2);
}

std::string inputReader::split(string& input) {
    //return max value possible for LOGOUT
    int i = input.find_first_of(' ');
    input.erase(0,i);
     return (input.substr(0,i));
}


