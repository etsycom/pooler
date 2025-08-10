#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("usage: pooler [input path] [output path]");
        return 0;
    }

    long  PakSize                 = 0l;
    int   PakLength               = strlen(argv[1]);
    FILE* pak                     = NULL;
    FILE* zip                     = NULL;
    char* buf                     = NULL;
    char  filename[PakLength + 5] = {};
    char  XorKey                  = 'x';

    if ((pak = fopen(argv[1], "rb")) == NULL) {
        printf("unable to open file '%s'\n", argv[1]);
        return 1;
    }

    strncpy(filename, argv[1], PakLength);
    strcat(filename, ".zip");
    zip = fopen(filename, "wb");

    fseek(pak, 0, SEEK_END);
    PakSize = ftell(pak);
    rewind(pak);
    buf = (char*)malloc(PakSize);

    for (long index = 0l; index < PakSize; index++) {
        buf[index] = fgetc(pak);
        fprintf(zip, "%c", buf[index] ^ XorKey);
    }

    free(buf);
    return 0;
}
