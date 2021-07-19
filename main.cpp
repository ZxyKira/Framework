#include <stdio.h>
#include <stdlib.h>
#include "framework.h"

uint8_t buffer[64];
uint8_t data[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void showBuffer(){
    printf("<----------------------------->\n");
    for(int i=0; i<64; i++){
        printf("0x%02X ", buffer[i]);
        if(i%8==7)
            printf("\n");
    }
    printf("<----------------------------->\n");
}

int main(){
    printf("baseAddress ; 0x%08X\n", &buffer[0]);
    showBuffer();
    framework::util::BlockPool* blockPool = new framework::util::BlockPool(&buffer, 8, 8);
    showBuffer();

    blockPool->add(&data);
    showBuffer();
    blockPool->add(&data);
    showBuffer();
    blockPool->add(&data);
    showBuffer();
    blockPool->add(&data);
    showBuffer();
    blockPool->add(&data);
    showBuffer();

    return 0;
}

