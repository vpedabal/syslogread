#include <stdio.h>

#include "util.h"
#include "syslog.h"
#include "strings.h"

int main(int argc, char **argv)
{
    uint64_t tot_lines = 0;
    printf("SIGAR Test Application\n");
    if(argc <=1) {
        tot_lines = get_total_lines("/home/vpedabal/git-repos/myapps/syslogread/testfile");
        printf("Total lines: %lu\n", tot_lines);
       get_line("/home/vpedabal/git-repos/myapps/syslogread/testfile", 9);

    } else {
        tot_lines = get_total_lines(argv[1]);
        printf("Total lines: %lu\n", tot_lines);
        get_line(argv[1], 9);

    }
    return 0;
}
