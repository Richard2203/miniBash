#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void getPrompt(char *prompt) {
    // Nombre de usuario
    char *username = getlogin();
    if (username == NULL) {
        perror("Error al obtener el nombre de usuario");
        return;
    }

    // Nombre del host
    char hostname[255];
    if (gethostname(hostname, 255) != 0) {
        perror("Error al obtener el nombre del host");
        return;
    }

    // path actual
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Error al obtener la ruta del directorio actual");
        return;
    }

    sprintf(prompt, "%s@%s:~%s$", username, hostname, cwd);
}

int main() {
    char prompt[1024];
    getPrompt(prompt); 
    printf("%s\n", prompt);

    

    return 0;
}
