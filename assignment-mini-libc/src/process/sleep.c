#include <time.h>
unsigned int sleep(unsigned int seconds){
    struct timespec required;
    struct timespec remaining;
    required.tv_sec = seconds;
    required.tv_nsec = 0;
    nanosleep(&required, &remaining);
    return remaining.tv_sec;
}
