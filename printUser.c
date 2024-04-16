#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Usuario que ejecutó el proceso: %s\n", getlogin());
    return 0;
}
