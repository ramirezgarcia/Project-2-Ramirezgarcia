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
#include <socket.h>


int main( int argc, char* argv[])
{
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  struct sockaddr_in servaddr;

  memset(&servaddr, '\0', sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(5000);

  bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
  
  char buf[90];
  char *hello = "You did it form client";
  int len, n;
   len = sizeof(cliaddr);

  sendto(sockfd,(const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));

    cout << "message sent";

   n = recvfrom(sockfd,(char *) buf, 90, MSG_WAITALL,(struct server *) &servaddr, &len);
   buf[n] = '\0';

  cout << "client" << buf;
  close(sockfd);
  return 0;

  //std::cerr << "client is not implemented yet" << std::endl;
}
