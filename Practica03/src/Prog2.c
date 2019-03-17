#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  time_t startTime = time(NULL);
  do {
    printf("Aqui estoy %d \n", getpid());
  } while(30!=difftime(time(NULL),startTime));
  return 0;
}
/**
@file Prog2.c
@author Damian Meza Madrid
@date 16 Marzo 2019
@brief  Programa que imprime el mensaje "Aqui estoy" seguido de el id del proceso durante 30 segundos.
*/
