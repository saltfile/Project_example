//
// Created by saltfish on 2022/1/2.
//

#include "../self_main.h"

u8* fun_xor(u8 *bytes){
    for(int i  = 0; i < sizeof(bytes);i++){
        bytes[i]=(u8) (bytes[i]^SELECT);
    }
    return bytes;
}


void int_unbyte(u8 *arr,int num){
    u8 arrs[4];
    arr[3] = (u8) (num & 0xff);
    arr[2] = (u8) (num >> 8 & 0xff);
    arr[1] = (u8) (num >> 16 & 0xff);
    arr[0] = (u8) (num >> 24 & 0xff);
    arr = arrs;
}


string get_Result(u8 *bytes){
    u8 len[4];
    len[0] = bytes[4];
    len[1] = bytes[5];
    len[2] = bytes[6];
    len[3] = bytes[7];
    int pack_size = 0;
    int str_size = 0;
    for(int i=0;i<sizeof(len);i++){
         pack_size+= (len[i] & 0xff) << ((3-i)*8);
    }
    int j = 8;
    str_size = pack_size-9;
    u8 str_result_byte[str_size];

    for(int i = 0;i < str_size;i++){
        str_result_byte[i] = (u8) (bytes[j]^SELECT);
        j++;
    }
    //字节转字符串
    char str_result_char[str_size+1];
    for(int i = 0;i < str_size;i++){
        str_result_char[i] = str_result_byte[i];
    }
    str_result_char[str_size] = 0;
    string str_result_string = str_result_char;
    return str_result_string;

}

