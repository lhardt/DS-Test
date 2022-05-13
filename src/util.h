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

// Creates uma lista (não) ordenada de 1 a n, incluso
int * generate_number_list(int n, int random);

//busca os valores do inicio, meio e fim de um vetor int
//e retorna como outro vetor
int getNumberPos (int *list, int pos, int tam);

//retorna numero em uma posição da lista.
//posição pode significar inicio/meio/fim ou uma posição real
int * getInicioMeioFim(int *list, int tam);

//imprime lista int
void print_int_list(int n_numb, int * list);

#endif
