#include <stdio.h>


unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if(i < 0)
    {
        return x;
    }
    if(i > sizeof(x) - 1){
        return x;
    }

    unsigned int mask = ((unsigned)0xFF)<<(i << 3);
    unsigned int pos_byte = ((unsigned)b) << (i << 3);
    printf("x:0x%x\n",x);
    printf("~mask:0x%x\n", ~mask);
    printf("pos_byte:0x%x\n", pos_byte);
    printf("x & ~mask:0x%x\n",(x & ~mask));

    return (x & ~mask) | (pos_byte);
}

int main(){
    unsigned rep_0 = replace_byte(0x12345678, 2, 0xAB);
    printf("0x%x\n",rep_0);
    return 0;
}