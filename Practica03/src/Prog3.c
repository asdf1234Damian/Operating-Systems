#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static volatile sig_atomic_t sigCatch = 1;
static void sig_hand(int _){
  (void)_;
  sigCatch = 0;
}

int main(int argc, char const *argv[]) {

  signal(SIGINT,sig_hand);

  while(sigCatch) {
    printf("Aqui estoy %d \n", getpid());
  }

  printf("Terminado por interrupcion del sistema operativo\n");
  return 0;
}
/**
@file Prog3.c
@author Damian Meza Madrid
@date 16 Marzo 2019
@brief Programa que imprime el mensaje "Aqui estoy" seguido de el id del proceso durante hasta que se interrumpido por la senal ctrl+c
*/
