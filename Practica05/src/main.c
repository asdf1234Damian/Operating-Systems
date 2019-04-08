#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  /// Se crean los dos pipes y las variables auxiliares par leer y guardar la suma de los numeros pares e impares. Si alguno falla, termina el programa
  /// \code
  int buf ;
  int pipePar[2], sumpar=0;
  int pipeImp[2], sumimp=0;
  if (pipe(pipePar)==-1 || pipe(pipeImp)==-1) {
    printf("Error al crear los pipes \n");
    return 1;
  }
  /// \endcode
  /// Se crea un arreglo de integers de tamano igual al primer parametro en argv[]
  /// \code
  char *p;
  int n  = strtol(argv[1],&p,10);
  int *nums = (int*)malloc(sizeof(int)*n);
  srand(time(NULL));
  for (unsigned char i = 0; i < n; i++) {
    nums[i]=rand()%10;
    printf("Padre (%d): num alteatorio %d: %d\n",getpid(),i+1,nums[i]);
  }
  /// \endcode

  pid_t cpid;
  cpid = fork();
  if (cpid<0) {
    return 1;
  }
  if (cpid) {
    cpid = fork();
      if (cpid<0) {
        return 1;
      }
      if (cpid) {
        write(pipePar[1],nums, sizeof(int)*n);
        close(pipePar[1]);
        wait(NULL);
        read(pipePar[0],&sumpar, sizeof(int));
        close(pipePar[0]);
        printf("Padre (%d): Suma pares %d \n",getpid() ,sumpar);
      }else{
        for (size_t i = 0; i < n; i++) {
          read(pipePar[0],&buf, sizeof(buf));
          if (buf%2==0) {
            printf("Hijo de pares(%d) : sumando %d \n",getpid(),buf );
            sumpar += buf;
          }
        }
        close(pipePar[0]);
        write(pipePar[1], &sumpar, sizeof(sumpar));
        close(pipePar[1]);
        exit(EXIT_SUCCESS);
      }
    write(pipeImp[1],nums, sizeof(int)*n);
    close(pipeImp[1]);
    wait(NULL);
    read(pipeImp[0],&sumimp, sizeof(int));
    close(pipeImp[0]);
    printf("Padre (%d): Suma impares: %d \n",getpid(), sumimp);
    }else{
      for (size_t i = 0; i < n; i++) {
        read(pipeImp[0],&buf, sizeof(buf));
        if (buf%2) {
          printf("Hijo de impares(%d) : sumando %d \n",getpid(),buf );
          sumimp += buf;
        }
      }
      close(pipeImp[0]);
      write(pipeImp[1], &sumimp, sizeof(sumimp));
      close(pipeImp[1]);
      exit(EXIT_SUCCESS);
  }
  return 0;
}
