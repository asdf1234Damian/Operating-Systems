#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int n=0,m=0;
int *matrixA,*matrixB, *indexes;
pthread_t *threads;

/// Funcion para no tener que hacer un arreglo bidimensional
/// \code
int myIndex(int i,int j){
  return i + j*m;
}
/// \endcode


/// Funcion para agregar todos los elementos dentro de la misma fila del arrelgo  dado el indice de la misma
/// \code
void *addRow(void *arg){
  int j = *(int*)arg;
  for (size_t i = 0; i < n; i++) {
    matrixA[myIndex(i,j)]+=matrixB[myIndex(i,j)];
  }
  pthread_exit(NULL);
}
/// \endcode

int main(int argc, char const *argv[]) {
  system("clear");
  /// Se leen los tamaños de las matrices, y se le asigna la memoria correspondiente junto al arreglo de threads
  /// \code
  scanf("%d %d",&n,&m);
  matrixA = (int*)malloc(sizeof(int)*(n+1)*(m+1));
  matrixB = (int*)malloc(sizeof(int)*(n+1)*(m+1));
  threads = (pthread_t*)malloc(sizeof(pthread_t)*(m+1));
  indexes = (int*)malloc(sizeof(int)*(m+1));
  /// \endcode

  /// Se lee la matriz A
  /// \code
  for (size_t j = 0; j < m; j++) {
    for (size_t i = 0; i < n; i++) {
      scanf("%d", &matrixA[myIndex(i, j)]);
    }
  }
  printf("\nMatriz A: \n");
  for (size_t j = 0; j < m; j++) {
    for (size_t i = 0; i < n; i++) {
      printf("%d ", matrixA[myIndex(i, j)]);
    }
    printf("\n");
  }

  /// \code

  /// Se lee la matriz A
  /// \code
  printf("\nMatriz B: \n");
  for (size_t j = 0; j < m; j++) {
    for (size_t i = 0; i < n; i++) {
      scanf("%d", &matrixB[myIndex(i, j)]);
    }
  }
  for (size_t j = 0; j < m; j++) {
    for (size_t i = 0; i < n; i++) {
      printf("%d ", matrixB[myIndex(i, j)]);
    }
    printf("\n");
  }

  /// \code

  /// Se crean los hilos y los datos correspondientes para cada uno de ellos
  /// \code
  for (int j = 0; j < m; j++) {
    indexes[j] = j;
    pthread_create(&threads[j], NULL, addRow, (void *)&indexes[j]);
  }
  /// \endcode

  /// Se imprime la matriz
  /// \code
  for (int j = 0; j < m; j++) {
    pthread_join(threads[j], NULL);
  }
  printf("\nMatriz resultante: \n");
  for (size_t j = 0; j < m; j++) {
    for (size_t i = 0; i < n; i++) {
      printf("%d ", matrixA[myIndex(i, j)]);
    }
    printf("\n");
  }
  /// \code
}
