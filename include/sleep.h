#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

inline void sleep_ms(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        sleep(milliseconds / 1000);
    #endif
};