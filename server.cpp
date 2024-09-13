#include "server.h"
// Write a server class
// Import methods from the server.h
class Server {
  public:
    std::string port;
    Server(std::string port) {
      this->port = port;
    };

    int start() {
        //TODO
        //create server socket.
        int server_socket_fd; //file descriptior of server socket.
        struct sockaddr_in server_addr; //structure for server address it helps to config and bind server socket.
        server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(server_socket_fd < 0){
            std::cerr << "Failed to create server socket." << std::endl;
            exit(1);
        }

        //config server socket.
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(std::stoi(port));
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY allows the server to listen on all available network interfaces.
        //bind  socket to port.
        if(bind(server_socket_fd,(struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
            std::cerr << "Failed to bind server socket." << std::endl;
            exit(1);
        }


        //listens on socket.
        if(listen(server_socket_fd, 5) < 0){
            std::cerr << "Failed to listen on server socket." << std::endl;
            exit(1);
        }

        std::cout << "Server started on port : " << port << std::endl;

        return server_socket_fd;
    };
    void stop(){
        //TODO
        //close the server socket.
    };

    ~Server(){};
};
