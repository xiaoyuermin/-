#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<string.h>
//输入几个参数是由自己决定的。即main函数的参数怎样写也是由你自己决定的。
int main(int argc,char* argv[]){
  if(argc!=3){
    printf("usage ./server [ip] [port]\n");//Usage:使用，用法，惯例。
    return 1;//如果出错，则返回1.
}
int fd=socket(AF_INET,SOCK_DGRAM,0);//是基于udp协议写的一个服务器。为什么我们要首先创建一个socket,因为我们先要为连接做好准备，创建socket的实质其实是在端口处申请一块内存空间，存放我们的字节流
if(fd<0){
 perror("socket");
 return 1;
}
struct sockaddr_in addr;//创建一个结构体，这个结构体里的变量包含有16位地址类型，16位端口号，32位ip地址，还有8字节的数据流。
addr.sin_family=AF_INET;//给这个结构体里的变量进行一个赋值。
addr.sin_addr.s_addr=inet_addr(argv[1]);//该函数所处的头文件为#include<arpa/inet.h>网络字节序其实也就是我们的二进制数。
addr.sin_port=htons(atoi(argv[2]));//
int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));//进行的是唯一的一个识别。
if(ret<0){
 perror("bind");
 return 1;
}
while(1){
 struct sockaddr_in peer;
socklen_t len=sizeof(peer);
 char buf[1024]={0};
 ssize_t read_size=recvfrom(fd,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
 //recvfrom(fd,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
 if(read_size<0){
  perror("recvfrom");
  continue;
}
buf[read_size]='\0';
printf("client %s:%d say: %s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
sendto(fd,buf,strlen(buf),0,(struct sockaddr*)&peer,len);
}
close(fd);
return 0;

}


 
