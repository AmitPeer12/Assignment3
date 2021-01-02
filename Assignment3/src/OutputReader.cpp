#include <thread>
#include "../include/OutputReader.h"
#include "../include/connectionHandler.h"


bool OutputReader::shouldTerminate() const {
    return terminate;
}

void OutputReader::run(const std::string& host, int port, ConnectionHandler &connectionHandler) {
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        exit(1);
    }
    while (!terminate) {
        int answer[4];
        if (!connectionHandler.getBytes(answer, 4)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        if (answer[1] == 12) {
            if (answer[3] == 4)
                terminate = true;
            std::string info;
            if (!connectionHandler.getFrameAscii(info, '\0')) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
            std::cout << &"ACK "[answer[3]] + info << std::endl;

        } else if (answer[1] == 13)
            std::cout << &"ERR "[answer[3]] << std::endl;
        else {
            std::cout << "Illegal input from Server. Exiting...\n" << std::endl;
            break;
        }
    }
}

OutputReader::OutputReader(const std::string &host, int port, ConnectionHandler &connectionHandler) {
    run(host,port,connectionHandler);
}


