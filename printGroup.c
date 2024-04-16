#include <stdio.h>
#include <unistd.h>

int main() {
    printf("ID del grupo del proceso: %d\n", getgid());
    return 0;
}
