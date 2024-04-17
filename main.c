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
    char prompt[1000], archivo[50], num_str[10];
    int num;
    getPrompt(prompt); 
    do{
        // Prompt
        printf("%s", prompt);
        // Leer el nombre del archivo y el número adicional
        scanf("%s %s", archivo, num_str);
        // Salir si el usuario ingresa "exit"
        if(!strcmp(archivo,"exit")) exit(EXIT_SUCCESS); // Mover la salida del bucle aquí
        
        // Convertir el número adicional a entero
        num = atoi(num_str);

        // Path completo del archivo
        char path[1050];
        sprintf(path, "%s/%s", getcwd(NULL, 0), archivo); 

        int pid, estado;
        pid = fork();
        if(pid==-1){
            perror("Error al crear el proceso hijo.");
        } else if(pid==0) {
            estado = execl(path, archivo, 
                "argumento1", 
                "argumento2", 
                "4", 
                "5", 
                "5", 
                "bool", 
                "3.1415", 
                NULL
            );

            if (estado==-1) {
                printf("No se pudo ejecutar el archivo %s\n",archivo);
                perror("Error...");
                _exit(2);
            }
        } else {
            pid = wait(&estado);
            // exit(255); // Eliminar esta línea
        }
    }while(1);
}


int main() {
    system("clear");
    bash();
    return 0;
}
