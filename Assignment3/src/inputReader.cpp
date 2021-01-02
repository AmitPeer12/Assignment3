#include "../include/inputReader.h"
#include <string>
//Constructor
inputReader::inputReader() {
    opcodes.insert("ADMINREG",1);
    opcodes.insert("STUDENTREG",2);
    opcodes.insert("LOGIN",3);
    opcodes.insert("LOGOUT",4);
    opcodes.insert("COURSEREG",5);
    opcodes.insert("KDAMCHECK",6);
    opcodes.insert("COURSESTAT",7);
    opcodes.insert("STUDENTSTAT",8);
    opcodes.insert("ISREGISTERED",9);
    opcodes.insert("UNREGISTER",10);
    opcodes.insert("MYCOURSES",11);
}
char[] inputReader::run(string input){
    //function that split the string
    int opcode;
    try {
        opcode = opcodes.at(parts[0]);
    }
    catch {
        opcode = -1;
    }
    switch (opcode) {
        case 1:
        case 2:
        case 3:
            return inputReader::type1(opcode,parts[1],parts[2]);
        case 4:
        case 11:
            return type4(opcode);
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
            return type2(opcode,atoi(parts[1]));
        case 8:
            return type3(opcode, parts[1]);
        default:
            return nullptr;
    }
}

static void inputReader::insert_string_to_char_array(char &arr[], string str, int &offset) {
    for(int i=0; i<str.length(); i++) {
        arr[offset+i] = str[i];
    }
    offset+=str.length();
}
static void inputReader::insert_integer_to_char_array(char &arr[], int num, int &offset) {
    packet[offset] = num;
    offset+=1;
}
char[] inputReader::type1(int opcode, string user,string pass) {
    int length = user.length() + pass.length() + 4;
    char packet[length];
    int offset = 0;
    insert_integer_to_char_array(packet, 0, offset);
    insert_integer_to_char_array(packet, opcode, offset);
    insert_string_to_char_array(packet, user, offset);
    insert_integer_to_char_array(packet, 0, offset);
    insert_string_to_char_array(packet, pass, offset);
    insert_integer_to_char_array(packet, 0, offset);
    return packet;
};
char[] inputReader::type2(int opcode, int courseNumber) {
    char packet [4];
    packet[0] = 0;
    packet[1] = opcode;
    packet[3] = ((courseNumber>>8) & 0xff);
    packet[4] = (courseNumber&0xff);
    return packet;

}
char[] inputReader::type3(int opcode, string user) {
    int length = user.length() + 3;
    int offset = 0;
    insert_integer_to_char_array(packet,0,offset);
    insert_integer_to_char_array(packet,opcode,offset);
    insert_string_to_char_array(packet,user,offset);
    insert_integer_to_char_array(packet,0,offset);
    return packet;
}
char[] inputReader::type4(int opcode) {
    char packet[2];
    insert_integer_to_char_array(packet, 0, offset);
    insert_integer_to_char_array(packet, opcode, offset);
    return packet;
}

