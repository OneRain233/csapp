#include "stdio.h"


int A(int x) {
    return !~x;
}

int B(int x){
    return !x;
}

int C(int x) {
    printf("%X\n",(x | ~0xff));
    return !~(x|~0xff);
}


int D(int x) {
    // printf("%ld\n",sizeof(int));
    printf("%x\n",(x >> 24));
    printf("%x\n",(x >> 24)&0xff);


    return B((x >> ((sizeof(int)-1) << 3)) & 0xff);
}

int main(){
    unsigned int all_zeros = 0;
    unsigned int all_ones = ~0;

    // printf("%d\n", A(all_ones));
    // printf("%d\n", B(all_zeros));
    // printf("%d\n", C(all_ones));
    printf("%d\n", D(0x00345678));
    // printf("%d\n", B(all_zeros));

}