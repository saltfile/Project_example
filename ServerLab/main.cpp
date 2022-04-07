#include "self_main.h"











int fun1 (){
    int a = 0x00000008;
    int b = 0x00000007;
    int c = a|b;
    return  a|b;
}

int main() {
//    ser_start();
    u8 up[4] = {0,0,0,28};
    int len = crc16(up);
    cout<<len;
    u8 f[4] = {0xd6,0xd0,0xb9,0xfa};
    char a[4];
    a[0] = f[0];
    a[1] = f[1];
    a[2] = f[2];
    a[3] = f[3];

    string sr = "中国";

    cout<<sr;

//    u8 u[4] = {0,0,0,2};
//    int res = 0;
//    for(int i=0;i<sizeof(u);i++){
//        res += (u[i] & 0xff) << ((3-i)*8);
//    }
//    cout<<res;



//    u8 buma=-19;
//    printf("%d\n",buma);
//    printf("%c\n",buma);
//    buma =(u8) (buma^SELECT);
//    printf("%d\n",buma);
//    printf("%c\n",buma);
//
//    short a = 30;
//    int size = sizeof(a);
//    printf("%d",size);
    return 0;
}
