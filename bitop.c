#include<stdio.h>
#include<stdlib.h>

#define SET(number, n) number |= 1UL << n
#define CLEAR(number, n) number &= ~(1UL << n)
#define TOGGLE(number, n) number ^= 1UL << n
#define CHECK(number, n) (number >> n) & 1UL

int main(void)
{
    int num = 0x00000000;
    printf("%d\n", num);            // 0

    SET(num, 0);                    // 0x00000001;
    printf("%d\n", num);            // 1
    
    SET(num, 1);                    // 0x00000011;
    printf("%d\n", num);            // 3
    
    CLEAR(num, 1);                  // 0x00000001;
    printf("%d\n", num);            // 1
    
    TOGGLE(num, 2);                 // 0x00000101;
    printf("%d\n", num);            // 5
    
    TOGGLE(num, 2);                 // 0x00000001;
    printf("%d\n", num);            // 1
    printf("%d\n", CHECK(num, 0));  // 0
    printf("%d\n", CHECK(num, 1));  // 1

    return 0;
}
