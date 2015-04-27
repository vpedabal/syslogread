#include <stdio.h>
#include "util.h"

duration_t convert_to_days(double seconds)
{
    duration_t duration;

    duration.msec = (seconds - (unsigned long int)seconds)*1000;
    duration.seconds= (unsigned long int)(seconds) % 60;
    seconds = seconds/60;
    duration.minutes= (unsigned long int)(seconds) % 60;
    seconds = seconds/60;
    duration.hours  = (unsigned long int)(seconds) % 24;
    seconds = seconds/24;
    duration.days   = (unsigned long int)(seconds);    
    return duration;
}

