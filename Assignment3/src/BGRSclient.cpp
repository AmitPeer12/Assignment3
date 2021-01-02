#include <stdlib.h>
#include "../include/connectionHandler.h"
#include "../include/inputReader.h"
#include "../include/outputReader.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        return 1;
    }

    outputReader outputReader;
    inputReader inputReader;
    while (!outputReader.shouldTerminate()) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        inputReader.run(line, connectionHandler);
        }
    return 0;
}