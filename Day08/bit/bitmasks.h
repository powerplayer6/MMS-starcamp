#include <stdio.h>
#include <stdint.h>

void setBit(uint64_t *mask, unsigned bit);
void clearBit(uint64_t *mask, unsigned bit);
int checkBit(uint64_t mask, unsigned bit);
void flipBit(uint64_t *mask, unsigned bit);