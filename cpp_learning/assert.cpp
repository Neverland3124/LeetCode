#define NDEBUG
#include <cassert>

int main() {
    int x = 0;
    assert(x != 0); // This will be ignored
    return 0;
}
