#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYS_nanosleep 35

int nanosleep(const struct timespec *req, struct timespec *rem){
    int result;
    result = syscall(SYS_nanosleep, req, rem);
    if (result < 0) {
        errno = -result;
        return -1;
    }

    return 0;
}
