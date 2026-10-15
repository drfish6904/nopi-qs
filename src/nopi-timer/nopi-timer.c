#include "../nopi-qs/nopi-qs.h"
#define _POSIX_C_SOURCE 200809L

#include "nopi-timer.h"

#define _POSIX_C_SOURCE 200809L
#define NSEC_PER_SEC NOPI_NSEC_PER_SEC
#define NSEC_PER_MSEC NOPI_NSEC_PER_MSEC

double
nopi_timer_qs (
    nopi_qs_t *qs
)
{
    struct timespec start, end;

    clock_gettime (
        TIME_MONOTONIC,
        &start
    );
    
    nopi_qs (
        qs
    );

    clock_gettime (
        TIME_MONOTONIC,
        &end
    );

    return (end.tv_sec - start.tv_sec) + 
        ((end.tv_nsec - start.tv_nsec) / NSEC_PER_MSEC);
}