#include "fast_timer.h"

void fast_timer(int milliseconds_to_count) {
    printf("Fast timer:\n");
    int milliseconds = 0; 
    do {
        printBuffer(&milliseconds);
        milliseconds++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    } while (milliseconds < milliseconds_to_count);
    std::cout << std::endl; // Move to a new line after the loop completes
}

/**
 * Prints a buffer of 4 digits
 * 
 * currently acts very weird, but it works, kinda...
*/
void printBuffer(const int *ms) {
    std::ios_base::sync_with_stdio(false);

    char buf[3]; // or some other nice, large enough size
    char* const last = buf+sizeof(buf);
    char* out = buf;

    for (int i = 0; i < 4; i++) {
        out += snprintf(out, last-out, "%i",*ms);
    }

    *out = '\0';
    printf("%s\r", buf);
}