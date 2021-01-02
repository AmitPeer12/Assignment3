

#ifndef ASSIGNMENT3_BGRSCLIENT_H
#define ASSIGNMENT3_BGRSCLIENT_H

class BGRSclient
{
private:
    int sock;
    std::string host;
    string response_data = "";
    int port;
    struct sockaddr_in server;

public:
//    BGRSclient();
//    bool conn(string, int);
//    bool send_data(string data);
//    string receive(int);
};

#endif //ASSIGNMENT3_BGRSCLIENT_H
