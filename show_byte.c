#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (int i = 0; i < len; i++) {
        printf("%.2x",start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}


void print_bin(int number){
    int bit = sizeof(int)*8;
    int i;
    for(i = bit - 1;i >= 0;i--){
        int bin = (number & (1 << i)) >> i;
        printf("%d", bin);
    }
    printf("\n");
}

void disBin(char ch)
{
    int i = 8;
    while(i--)
    {
        if((1<<i)&ch)
            printf("1");
        else
            printf("0");
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    putchar(10);
}
void getFloatBin(float num,char bin[])
{
    int t = 1;//用来按位与操作
    int *f = (int*)(&num);//将float的解释成int，即float的地址转成int*
    for(int i=0;i<32;i++)
    {
    //从最高位开始按位与，如果为1，则bin[i]=1，如果为0，则bin[i]=0
    //这里没有将bin存成字符，而是数字1 0
        bin[i] = (*f)&(t<<31-i)?1:0;
    }
}

int main(int argc, char *argv[])
{
    // show_int(1);
    show_float(15213);
    show_float(-128);
    disBin(100);
    char c[32];
    getFloatBin(100.0,c);
    // show_double(1);
    for(int i=0;i<32;i++)
    {
        printf("%d",c[i]);
        if(i==0)
            printf(", ");
        if(i==8)
            printf(", ");
    }
    return 0;
}