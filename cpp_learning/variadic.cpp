#include <cstdarg>
#include <iostream>

void simpleLogger(const char* format, ...) {
    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (*format == 'd') {
            int i = va_arg(args, int);
            std::cout << i << "d ";
        } else if (*format == 'c') {
            char c = va_arg(args, int);
            std::cout << c << "c ";
        } else if (*format == 'f') {
            double d = va_arg(args, double);
            std::cout << d << "f ";
        } else if (*format == 'g') {
            char* s = va_arg(args, char*);
            // or add const 
            // const char* s = va_arg(args, const char*);
            std::cout << s << "g ";
        }
        ++format;
    }
    va_end(args);
    std::cout << std::endl;
}

int main() {
    simpleLogger("dcfg", 42, 'x', 3.14, "hello world!");
    return 0;
}
