#include <ctime>

class Timer
{
    public:
        Timer(); // Initialize and prepare to start.
        void reset(); // Reset timer.
        int start(); // Start timer.
        int stop(); // Stop timer.
        int result(); // Return elapsed time [ms].

    private:
        clock_t timeStarted, timeEnded;
        bool testTimer();
    // Everything else you need, both fields and methods.
};
