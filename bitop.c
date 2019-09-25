#include<stdio.h>
#include<stdlib.h>

#define SET(number, n) (number) |= 1UL << (n)
#define CLEAR(number, n) (number) &= ~(1UL << (n))
#define TOGGLE(number, n) (number) ^= 1UL << (n)
#define CHECK(number, n) ((number) >> (n)) & 1UL
#define CHANGE(number, x, n) (number) ^= (-(x) ^ (number)) & (1UL << n)
#define COUNT_NUM_BIT_IS_ONE(number) ((number)^(number-1))

int main(void)
{
    int num = 0x00000000;
    printf("%d\n", num);            // 0

    SET(num, 0);                    // 0...00000001;
    printf("%d\n", num);            // 1

    SET(num, 1);                    // 0...00000011;
    printf("%d\n", num);            // 3

    CLEAR(num, 1);                  // 0...00000001;
    printf("%d\n", num);            // 1

    TOGGLE(num, 2);                 // 0...00000101;
    printf("%d\n", num);            // 5

    TOGGLE(num, 2);                 // 0...00000001;
    printf("%d\n", num);            // 1
    printf("%d\n", CHECK(num, 0));  // 0
    printf("%d\n", CHECK(num, 1));  // 1

    CHANGE(num, 1, 4);              // 0...00010001;
    printf("%d\n", num);            // 17;
    
    int test = 0x01001101;
    printf("%d\n", COUNT_NUM_BIT_IS_ONE(test));

    return 0;
}
