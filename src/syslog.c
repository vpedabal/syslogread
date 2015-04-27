#include "syslog.h"
#include "util.h"
#include <unistd.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <errno.h>


uint64_t get_total_lines(char *filename)
{
    FILE *fptr;
    size_t len = 0;
    ssize_t linesize = 0;
    uint64_t linecount=0;
    char *buffer = NULL;

    fptr = fopen (filename, "r");
    if(fptr == NULL) {
        printf("Unable to open file");
    } else {
            while ((linesize = getline(&buffer, &len, fptr)) != -1) 
                linecount++;
    }
    return linecount;
}

void get_line(char *filename, uint64_t line)
{
    FILE *fptr;
    size_t len = 0;
    ssize_t linesize = 0;
    uint64_t index;
    char *buffer = NULL;

    printf("%lu, %s\n",line, filename);

    fptr = fopen (filename, "r");
    if(fptr == NULL) {
        printf("Unable to open file");
    } else {
        for (index = 0; index < line; index++)
        {
            if ((linesize = getline(&buffer, &len, fptr)) == -1)
            {
                printf("Requested line is not present in log yet\n");
                return;
            }
        }
        printf("Line : %lu - %s", index, buffer);
    }

}


