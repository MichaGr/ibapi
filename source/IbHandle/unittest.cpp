#include "Client.h"

int main(int argc, char** argv)
{
    Client* client = new Client();

    client->connect("127.0.0.1",4002,0);

    client->disconnect();

    delete client;
    client = nullptr;
}
