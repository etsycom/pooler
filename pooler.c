#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("usage: pooler <input file>");
        return 0;
    }

    long  PakSize                 = 0l;
    int   PakLength               = strlen(argv[1]);
    FILE* pak                     = NULL;
    FILE* zip                     = NULL;
    char* buf                     = NULL;
    char  filename[PakLength + 5] = {};
    char  XorKey                  = 'x';
    char  mode[8]                 = {};

    if ((pak = fopen(argv[1], "rb")) == NULL) {
        printf("unable to open file '%s'\n", argv[1]);
        return 1;
    }

    strncpy(filename, argv[1], PakLength);
    do {
        if (mode[0] != '\0')
            puts("please enter 'P' or 'Z'");
        fputs("pak or zip? [P/Z]: ", stdout);
        fgets(mode, 8, stdin);
        if (mode[0] == 'p' || mode[0] == 'P') {
            strcat(filename, ".pak");
            mode[0] = '\0';
        }
        else if (mode[0] == 'z' || mode[0] == 'Z') {
            strcat(filename, ".zip");
            mode[0] = '\0';
        }
    } while (mode[0] != '\0');
    zip = fopen(filename, "wb");

    fseek(pak, 0, SEEK_END);
    PakSize = ftell(pak);
    rewind(pak);
    buf = (char*)malloc(PakSize);

    for (long index = 0l; index < PakSize; index++) {
        buf[index] = fgetc(pak);
        fprintf(zip, "%c", buf[index] ^ XorKey);
    }

    fclose(pak);
    fclose(zip);
    free(buf);
    return 0;
}
