#include <stdio.h>
#include <stdlib.h>
#include "dasm.h"

uint8_t* readall(char* fname,int32_t *fsize) {
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("ERROR: Unable to open file %s\n", fname);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    *fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *buf = malloc(*fsize);
    fread(buf, *fsize, 1, fp);
    fclose(fp);
    return buf;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <rom_file>\n", argv[0]);
        return 1;
    }
    int32_t size,pc=0;
    uint8_t *buf = readall(argv[1],&size);
    if(buf==NULL) return -1;
    while (pc < size) pc += dasm(buf, pc);
    free(buf);
}
