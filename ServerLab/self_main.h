//
// Created by saltfish on 2021/12/31.
//

#ifndef SERVERLAB_SELF_MAIN_H
#define SERVERLAB_SELF_MAIN_H
#include <error.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <vector>
#include <time.h>
#include <iconv.h>
#include <bitset>
using namespace std;
typedef unsigned char u8;

static int SELECT = -113;
static int BITS_OF_BYTE = 8;
static int POLYNOMIAL = 0xA001;
static int INIT_VALUE = 0xFFFF;

int crc16(u8 *bytes);
void int_unbyte(u8 *arr,int num);
int getShort(u8 a,u8 b);
void read1(int socket);
int ser_start();
u8* fun_xor(u8 *bytes);
string get_Result(u8 *bytes);













#endif //SERVERLAB_SELF_MAIN_H
