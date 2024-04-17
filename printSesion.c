#include <stdio.h>
#include <unistd.h>

int main() {
    printf("ID de la sesión: %d\n", getsid(0));
    _exit(20);
}
