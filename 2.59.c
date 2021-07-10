#include <stdio.h>


int main(){
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;

    unsigned int res = (x & 0xFF) | (y & ~0xFF);
    printf("0x%x\n",res);
    return 0;
}