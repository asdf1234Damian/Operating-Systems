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
  int i = *(int*)arg;
  for (size_t j = 0; j < m; j++) {
    matrixA [myIndex(i,j)]+=matrixB[myIndex(i,j)];
  }
  pthread_exit(NULL);
}
/// \endcode

int main(int argc, char const *argv[]) {
  system("clear");
  /// Se leen los tamaños de las matrices, y se le asigna la memoria correspondiente junto al arreglo de threads
  /// \code
  scanf("%d %d",&n,&m);
  matrixA = (int*)malloc(sizeof(int)*n*m);
  matrixB = (int*)malloc(sizeof(int)*n*m);
  threads = (pthread_t*)malloc(sizeof(pthread_t)*m);
  indexes = (int*)malloc(sizeof(int)*m);
  /// \endcode

  /// Se lee la matriz A
  /// \code
  printf("Matriz A: \n");
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      scanf("%d", &matrixA[myIndex(i, j)]);
    }
  }
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%d ", matrixA[myIndex(i, j)]);
    }
    printf("\n");
  }
  /// \code

  /// Se lee la matriz A
  /// \code
  printf("\nMatriz B: \n");
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      scanf("%d", &matrixB[myIndex(i, j)]);
    }
  }
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%d ", matrixB[myIndex(i, j)]);
    }
    printf("\n");
  }
  /// \code

  /// Se crean los hilos y los datos correspondientes para cada uno de ellos
  /// \code
  printf("\nMatriz resultante: \n");
  for (int i = 0; i < m; i++) {
    indexes[i] = i;
    pthread_create(&threads[i], NULL, addRow, (void *)&indexes[i]);
  }
  /// \endcode

  /// Se imprime la matriz
  /// \code
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%d ",matrixA[myIndex(i,j)]);
    }
    printf("\n");
  /// \code
  }





}
