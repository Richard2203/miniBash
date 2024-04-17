#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/wait.h>

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

void bash(){
    char prompt[1000], input[100], archivo[50], num_str[10];
    int num;
    getPrompt(prompt); 
    do{
        // Prompt
        printf("%s ", prompt);
        
        
        fgets(input, sizeof(input), stdin);

        // Dividimos la entrada en palabras
        sscanf(input, "%s %s", archivo, num_str);

        if(!strcmp(archivo,"exit")) exit(EXIT_SUCCESS); // Mover la salida del bucle aquí
        
        if (num_str[0] != '\0') {
            num = atoi(num_str);
        } else num = 0;

        // Path completo del archivo
        char path[1050];
        sprintf(path, "%s/%s", getcwd(NULL, 0), archivo); 

        int pid, estado;
        pid = fork();
        if(pid==-1){
            perror("Error al crear el proceso hijo.");
        } else if(pid==0) {
            // Si existe segundo argumento se envia 
            if (num_str[0] != '\0') {
                estado = execl(path, archivo, num_str, NULL);
            } else {
                estado = execl(path, archivo, NULL);
            }

            if (estado==-1) {
                printf("No se pudo ejecutar el archivo %s\n",archivo);
                perror("Error...");
                _exit(2);
            }
        } else {
            pid = wait(&estado);
        }
    }while(1);
}


int main() {
    system("clear");
    bash();
    return 0;
}
