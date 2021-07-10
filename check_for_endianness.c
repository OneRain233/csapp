#include<stdio.h>


int check_for_endianness()
{
    unsigned int x = 0x12345678;
    char *c = (char*)&x;
    printf("%x\n",*c);
    if (*c == 0x78)
    {
        return 1;//little endian
    }
    else{
        return 0;//bign endian
    }
    // return 0;
}


int main()
{
    int res = check_for_endianness();
    if(res == 1){
        printf("%s\n","Little endian");
    }
    else{
        printf("%s\n","Big endian");
    }
    return 0;
}