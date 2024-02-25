#include <chrono>
#include <iostream>
#include <cinttypes>
#include <string>

using namespace std;


/**
 * Retrieves the current time in milliseconds since the epoch.
 *
 * @return the current time in milliseconds
 */
int get_mils () {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * Retrieves a number input from the user and returns it as an integer.
 *
 * @return the integer value entered by the user
 *
 * @throws std::exception if the input cannot be converted to an integer
 */
int get_mils_to_count_from_user() {
    cout << "Please enter a number: ";
    string response_from_user;
    std::cin >> response_from_user;

    int response_from_user_int;
    size_t response_from_user_length = response_from_user.length();
    
    try
    {
        response_from_user_int = stoull(response_from_user, &response_from_user_length);
    }
    catch(const std::exception& e)
    {
        cout << "\r\033[F\x1b[2K";
        return get_mils_to_count_from_user();
    }

    return response_from_user_int;
}


/**
 * Initializes the timing mechanism and calculates the duration of a given function.
 *
 * @param timer a function pointer to the timer function
 * @param milliseconds_to_count the number of milliseconds to count
 *
 * @return the duration of the timer function in milliseconds
 *
 * @throws None
 */
int init_timing(void (*timer)(const int milliseconds_to_count), const int milliseconds_to_count){
    // Capture the start time
    const int start_time = get_mils();

    // Execute the timer function
    (*timer)(milliseconds_to_count);

    // Capture the end time
    const int end_time = get_mils();

    // Capture duration
    const int duration = end_time-start_time;

    // Calculate and print the duration
    printf("Took: %i ms\n", duration);

    return duration;
}