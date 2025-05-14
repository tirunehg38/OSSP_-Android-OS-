#include <time.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {
    // Set desired time (April 24, 2024 12:00:00 UTC)
    struct timespec ts = {
        .tv_sec = 1713960000,
        .tv_nsec = 0
    };

    // Attempt to set system clock
    int result = syscall(SYS_clock_settime, CLOCK_REALTIME, &ts);

    if (result == -1) {
        perror("Error setting time");
        return 1;
    }

    printf("Time successfully set to %ld\n", ts.tv_sec);
    return 0;
}
