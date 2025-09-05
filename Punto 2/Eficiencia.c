#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad : 7;     
    unsigned int id   : 24;     
    float *calificaciones;
    int numCalificaciones;
} Estudiante;

Estudiante* crearEstudiante(const char *nombre, const char *apellido, int edad, int id, float *notas, int numNotas) {
    Estudiante *e = (Estudiante*) malloc(sizeof(Estudiante));
    if (!e) {
        perror("Error al asignar memoria para el estudiante");
        exit(1);
    }
    
    e->nombre = (char*) malloc(strlen(nombre) + 1);
    e->apellido = (char*) malloc(strlen(apellido) + 1);
    strcpy(e->nombre, nombre);
    strcpy(e->apellido, apellido);

    e->edad = edad;
    e->id = id;

    e->numCalificaciones = numNotas;
    e->calificaciones = (float*) malloc(sizeof(float) * numNotas);
    for (int i = 0; i < numNotas; i++) {
        e->calificaciones[i] = notas[i];
    }

    return e;
}

void liberarEstudiante(Estudiante *e) {
    if (e) {
        free(e->nombre);
        free(e->apellido);
        free(e->calificaciones);
        free(e);
    }
}

void mostrarEstudiante(Estudiante *e) {
    printf("ID: %u | Nombre: %s %s | Edad: %u | Notas: ", e->id, e->nombre, e->apellido, e->edad);
    for (int i = 0; i < e->numCalificaciones; i++) {
        printf("%.2f ", e->calificaciones[i]);
    }
    printf("\n");
}

int main() {
    float notas1[] = {4.5, 3.8, 4.9};
    float notas2[] = {3.2, 2.9};

    Estudiante *e1 = crearEstudiante("Ana", "Maria", 20, 12456, notas1, 3);
    Estudiante *e2 = crearEstudiante("Carlos", "Rey", 22, 34565, notas2, 2);

    mostrarEstudiante(e1);
    mostrarEstudiante(e2);

    liberarEstudiante(e1);
    liberarEstudiante(e2);

    return 0;
}