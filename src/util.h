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
int * generate_number_list(int n);

void print_int_list(int n_numb, int * list);

#endif
