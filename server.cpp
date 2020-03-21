#include <string>
#include <thread>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <iostream>
//#include <bits/stdc++.h>
#include <sys/stat.h>
#include <cstdio>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  struct sockaddr_in servaddr, cliaddr;

  memset(&servaddr, '\0', sizeof(servaddr));
  memset(&cliaddr, '\0', sizeof(cliaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(5000);

  bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
  
  char buf[90];
  char *hello = "You did it form server";
  int n;
  socklen_t len;
  len = sizeof(cliaddr);


   n = recvfrom(sockfd,(char *) buf, 90, MSG_WAITALL,(struct sockaddr *) &cliaddr, &len);

  buf[n] = '\0';

  cout << "client" << buf;

  sendto(sockfd,(const char *)hello, strlen(hello), 0, (const struct sockaddr *) &cliaddr, len);
  cout << "message sent";


  //std::cerr << "server is not implemented yet" << std::endl;
  return 0;
}
