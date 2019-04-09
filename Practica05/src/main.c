#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  /// Se crean los dos pipes y las variables auxiliares par leer y guardar la suma de los numeros pares e impares. Si alguno falla, termina el programa
  /// \code
  int buf ;
  int pipePar[2], sumpar=0, parC=0;
  int pipeImp[2], sumimp=0, impC=0;
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
    if (nums[i]%2) {
      impC++;
    }else{
      parC++;
    }
    printf("Padre (%d): num alteatorio %d: %d\n",getpid(),i+1,nums[i]);
  }
  /// \endcode

  /// El padre hace 2 forks
  /// \code
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
  /// \endcode

  /// Despues el padre escribe los numeros en su pipe correspondiente
  /// \code
      if (cpid) {
        for (size_t i = 0; i < n; i++) {
          if (nums[i]%2==0) {
            write(pipePar[1],&nums[i], sizeof(int));
          }else{
            write(pipeImp[1],&nums[i], sizeof(int));
          }
        }
  /// \endcode

  /// Cierra los pipes y espera una respeusta
  /// \code
        close(pipePar[1]);
        close(pipeImp[1]);
        wait(NULL);
        wait(NULL);
  /// \endcode

  /// Se leen e imprimen la respuestas correspondientes de cada pipe , despues se cierran
  /// \code
        read(pipePar[0],&sumpar, sizeof(int));
        close(pipePar[0]);
        printf("Padre (%d): Suma pares %d \n",getpid() ,sumpar);
        read(pipeImp[0],&sumimp, sizeof(int));
        close(pipeImp[0]);
        printf("Padre (%d): Suma impares: %d \n",getpid(), sumimp);
        /// \endcode

        /// El segundo hijo (innermost) se dedica a sumar los numeros pares segun el contador, cierra el pipe despues.
        /// \code
      }else{
        for (size_t i = 0; i < parC; i++) {
          read(pipePar[0],&buf, sizeof(int));
          printf("Hijo de pares(%d) : sumando %d \n",getpid(),buf );
          sumpar += buf;
        }
        close(pipePar[0]);
  /// \endcode

  /// Escribe el resultado en el pipe, cierra el pipe y termina el proceso hijo con estado (EXIT_SUCCESS); para que el padre salga de wait(NULL)
  /// \code
        write(pipePar[1], &sumpar, sizeof(sumpar));
        close(pipePar[1]);
        exit(EXIT_SUCCESS);
      }
  /// \endcode

  /// El el primer hijo hace lo mismo, pero para sus numeros correspondientes (impares)
  /// \code
    }else{
      for (size_t i = 0; i < impC; i++) {
        read(pipeImp[0],&buf, sizeof(int));
        printf("Hijo de impares(%d) : sumando %d \n",getpid(),buf );
        sumimp += buf;
      }
      close(pipeImp[0]);
      write(pipeImp[1], &sumimp, sizeof(sumimp));
      close(pipeImp[1]);
      exit(EXIT_SUCCESS);
  }
  /// \endcode
  return 0;
}
