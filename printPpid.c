#include <stdio.h>
#include <unistd.h>

int main() {
    printf("ID del proceso padre: %d\n", getppid());
    return 0;
}
