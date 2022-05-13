#ifndef UTIL_H
#define UTIL_H

//
// Trabalho Semestral de Estruturas de Dados
// Ana Laura e Léo Hardt
// INF01203C - Renata Galante
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Creates a random list of the numbers from 1 to n, inclusive
int * generate_number_list(int n, int random);

void print_int_list(int n_numb, int * list);

int getNumberPos (int *list, int pos, int tam);

int * getInicioMeioFim(int *list, int tam);

#endif
