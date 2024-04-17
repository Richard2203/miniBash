#include <stdio.h>
#include <unistd.h>

int main() {
    printf("ID del proceso actual: %d\n", getpid());
    _exit(20);
}
