#include "filesystemHelpers.h"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void MakeDirectory(const char *path)
{
    if (mkdir(path, 0777) == -1)
    {
        fprintf(stderr, "Error creating directory '%s': ", path);

        switch (errno)
        {
        case EACCES:
            fprintf(stderr, "Permission denied\n");
            break;
        case EEXIST:
            fprintf(stderr, "Directory already exists\n");
            break;
        case ELOOP:
            fprintf(stderr, "Too many symbolic links encountered\n");
            break;
        case ENAMETOOLONG:
            fprintf(stderr, "File name too long\n");
            break;
        case ENOENT:
            fprintf(stderr, "No such file or directory\n");
            break;
        case ENOSPC:
            fprintf(stderr, "No space left on device\n");
            break;
        default:
            fprintf(stderr, "Unknown error\n");
            break;
        }
    }
}

void MakeFile(const char *filePath, const char *content)
{
    int i;
    FILE *fptr;
    char fn[50];
    fptr = fopen(filePath, "w"); // "w" defines "writing mode"
    int length = strlen(content);

    for (i = 0; i < length; i++)
    {
        /* write to file using fputc() function */
        fputc(content[i], fptr);
    }
    fclose(fptr);
}