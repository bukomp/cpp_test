#include <stdio.h>
#include <iostream>
#include <cinttypes>

#include "./utils/time_utils/time_utils.h"
#include "./utils/slow_timer/slow_timer.h"
#include "./utils/fast_timer/fast_timer.h"


int main() {
    const char* text = "Which timer is faster?";
    printf("%s\n\n", text);

    // Ask from the user for the number of milliseconds to count
    const int milliseconds_to_count = get_mils_to_count_from_user();

    const int slow_timer_time = init_timing(&slow_timer, milliseconds_to_count);

    std::cout << std::endl;
   
    const int fast_timer_time = init_timing(&fast_timer, milliseconds_to_count);

    const int difference = fast_timer_time - slow_timer_time;

    // Print the difference
    printf("Difference is: %i ms\n\n", difference<0?-difference:difference);
    
    fast_timer_time > slow_timer_time 
    ? printf("Fast timer is faster!\n") 
    : printf("Slow timer is faster!\n");
    
    // read line
    std::cin.get();
}   



