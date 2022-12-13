#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define LOWER 1
#define UPPER 9

#include "mylib/mylib.h"

void multiply_vector_matrix(int *Matrix, int *Vector, int N, int *vector_expected)
{
  int *vector_result = (int*)malloc(N * sizeof(int));

  if (vector_result == NULL)
  {
    printf("Malloc is failed!\n");
    return;
  }
  
  matVecMult(Matrix, Vector, vector_result, N);

  int i;
  for (i = 0; i < N; i++)
  {
    printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, vector_result[i], i, vector_expected[i]);
    assert(vector_result[i] == vector_expected[i]);
  }
}

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* Matrix, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Matrix[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* Vector, int N){
    for(int i=0; i<N; i++){
        Vector[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main()
{
  int Total_test_cases = 3;
  int N = 2;

  int matrix_input_test_case[3][4] = {
    {5, 4, 2, 3},
    {1, 4, 3, 2},
    {4, 7, 1, 6},
  };

  int vector_input_test_case[3][2] = {
    {1, 4},
    {5, 6},
    {2, 3},
  };

  int vector_expected_test_case[3][2] = {
    {21, 14},
    {29, 27},
    {29, 20},
  };


  int i;
  for (i = 0; i < Total_test_cases; i++)
  {
    printf("Test #%d:\n", i + 1);
    multiply_vector_matrix(
      matrix_input_test_case[i],
      vector_input_test_case[i],
      N,
      vector_expected_test_case[i]
    );
    printf("\n");
  }

  return 0;
}
