#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Usuario que ejecutó el proceso: %s\n", getlogin());
    _exit(20);
}
