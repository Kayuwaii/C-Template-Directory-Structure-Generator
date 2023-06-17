#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include "helpers/filesystemHelpers.h"

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        char basepath[150];
        if (getcwd(basepath, sizeof(basepath)) == NULL)
        {
            perror("Error getting current directory");
            return 1;
        }

        for (int i = 1; i < argc; i++)
        {
            char baseDirPath[255];
            char codepath[255];
            char codeLibpath[300];
            char outpath[255];
            snprintf(baseDirPath, sizeof(baseDirPath), "%s/%s/", basepath, argv[i]);
            snprintf(codepath, sizeof(codepath), "%s/%s/code", basepath, argv[i]);
            snprintf(codeLibpath, sizeof(codeLibpath), "%s/libs", codepath);
            snprintf(outpath, sizeof(outpath), "%s/%s/output", basepath, argv[i]);

            MakeDirectory(baseDirPath);
            MakeDirectory(codepath);
            MakeDirectory(codeLibpath);
            MakeDirectory(outpath);

            char makefilePath[270];
            snprintf(makefilePath, sizeof(makefilePath), "%s/makefile", baseDirPath);
            MakeFile(makefilePath, "#replace main for proper name\nmain:\n\tgcc -c libs/helpers.c -o libs/helpers.o\n\tgcc -c main.c -o main.o\n\tgcc main.o helpers/helpers.o -o main.run\n\trm -f libs/helpers.o\n\trm -f main.o\n\nmain-save:\n\tgcc -c libs/helpers.c -o libs/helpers.o\n\tgcc -c main.c -o main.o\n\tgcc main.o helpers/helpers.o -o main.run\n\tmv main.run output/main.run\n\trm -f libs/helpers.o\n\trm -f main.o\n");

            
            char hPath[315];
            char cPath[315];
            snprintf(hPath, sizeof(hPath), "%s/helpers.h", codeLibpath);
            snprintf(cPath, sizeof(cPath), "%s/helpers.c", codeLibpath);
            MakeFile(hPath, "#ifndef WHATEVER_H_INCLUDED\n#define WHATEVER_H_INCLUDED\n\n#endif\n");
            MakeFile(cPath, "#include \"helpers.h\"\n");
        }
    }

    return 0;
}
