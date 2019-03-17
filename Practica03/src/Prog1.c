#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  while (1) {
    printf("Aqui estoy %d \n", getpid());
  }
  return 0;
}

/**
@file Prog1.c
@author Damian Meza Madrid
@date 16 Marzo 2019
@brief  Programa que imprime el mensaje "Aqui estoy" seguido de el id del proceso de un ciclo infinito
*/
