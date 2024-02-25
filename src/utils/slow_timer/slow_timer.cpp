#include "slow_timer.h"


void slow_timer(int milliseconds_to_count) {
    printf("Slow timer:\n");
    int milliseconds = 0; 
    do {
        printf("\r%i", milliseconds++);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    } while (milliseconds < milliseconds_to_count);
    std::cout << std::endl; // Move to a new line after the loop completes
}
