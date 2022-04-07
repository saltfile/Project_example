//
// Created by saltfish on 2021/12/31.
//

#include "../self_main.h"
//计数器
int size_of_buf(u8 *buf){
    for(int i = 0;i < 1024;i++){
        if(buf[i] == NULL){
            return i+1;
        }
    }
    return sizeof(buf);
}

void buf_back(u8 *buf){
    for(int i = 0;i < 1024;i++){
        if(buf[i] == NULL){
            buf[i] = '\0';
            return ;
        }
    }
    buf[1023] = '\0';
}


void read1(int socketfd){
    ssize_t n;
    u8 buf[1024];

    char *ptr = (char *)buf;
    memset(ptr,0,1024);
    int time = 0;
    for (;;) {
        fprintf(stdout, "收到消息");
        if ((n = read(socketfd, buf, 1024)) == 0)
            return;

        time++;
        cout<<buf<<endl;
        cout<<"========================"<<endl;
        int len = size_of_buf(buf);
//        printf("%c\n",buf[0]);
        fun_xor(buf);
        cout<<len<<endl;
        for(int i = 0;i < len;i++){
            printf("%d\n",buf[i]);
        }
        u8 arr[4];
//        int j= 0;
//        for(int i = 4;i < 8;i++){
//            arr[j] = buf[i];
//            j++;
//        }
        int_unbyte(arr,len-1);
        for(int i = 0;i < sizeof(arr);i++){
            printf("%d",arr[i]);
        }
        int crc = crc16(arr);
        short crcRe = getShort(buf[2],buf[1]);
        printf("%x||%x",crc,crcRe);


        cout<<"------------------>"<<crc<<endl;
        cout<<"------------------>"<<crcRe<<endl;
        string str = get_Result(buf);
        cout<<str<<endl;
        cout<<str.size()<<endl;
        memset(ptr,0,1024);
        usleep(1000);
    }
}

int ser_start(){
    int listenfd,connfd;
    socklen_t client;
    struct  sockaddr_in cliaddr,seraddr;

    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&seraddr,sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_port = htons(8585);

    bind(listenfd,(struct sockaddr *) &seraddr,sizeof(seraddr));
    listen(listenfd,1024);

    for(;;){
        client = sizeof(cliaddr);
        connfd = accept(listenfd,(struct  sockaddr *) &cliaddr,&client);
        read1(connfd);
    }


}















