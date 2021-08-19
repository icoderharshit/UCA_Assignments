/*
 * Solution to Question 1-8
 * Assignment-3 (Bits and Bytes)
 * @Harshit Sharma , 1910990073
*/
#include <stdio.h>

int bitAnd(int x, int y) {  
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ((~x & y) & ~(x & ~y));
}

int bitSign(int x) {
    return (x == 0) ? 0 : ((((x >> 31) & 1) == 1) ? -1 : 1);
}

int getByte(int x, int n) {
    return (x >> 8*n & 255);
}

int conditional(int x, int y, int z) {
  
      	int mask = (!x + ~0x00);

  return ((~mask) & z) | ((mask) & y);
}

int logicalShift(int x, int n) {
    return ((x >> n) & ~(((1 << 31) >> n) << 1));
}

int bang(int x) {
    int minus_x = ~x + 1;
    
    int bits = (minus_x | x) >> 31; /* -1 or 0 */
    return bits + 1;
}

int invert(int x, int p, int n) {
    return  x ^ (~(~0 << n) << p);
}

int main() {
    printf("%d", bitSign(-23));

    return 0;
}
