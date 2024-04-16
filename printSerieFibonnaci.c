#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if (n < 0) {
        fprintf(stderr, "Numero invàlido.\n");
        return 1;
    }
    printf("El elemento %d de la serie Fibonacci es: %d\n", n, fibonacci(n));
    return 0;
}
