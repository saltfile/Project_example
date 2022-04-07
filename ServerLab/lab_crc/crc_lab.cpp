//
// Created by saltfish on 2022/1/4.
//

#include "../self_main.h"


int revert(int src) {
    int lowByte = (src & 0xFF00) >> 8;
    int highByte = (src & 0x00FF) << 8;
    return lowByte | highByte;
}


int getShort(u8 a,u8 b){
    return (int) ((a & 0xFF)| (b << 8));
}




int crc16(u8 *bytes){
    int res = INIT_VALUE;
    for(int i = 0;i < 4;i++){
        printf("%d    ",bytes[i]);
        res = res ^ bytes[i];
        for (int i = 0; i < BITS_OF_BYTE; i++) {
            res = (res & 0x0001) == 1 ? (res >> 1) ^ POLYNOMIAL : res >> 1;
        }
    }

    return revert(res);

}
