/*
Zachary Laug
CIS 2107
Lab 5
2D Arrays and Pointers to Functions
*/

#include <stdio.h>
#include <stdlib.h>

int max(size_t row, size_t col, int array[row][col]);
int rowSum(size_t row, size_t col, int array[row][col], size_t a);
int columnSum(size_t row, size_t col, int array[row][col], size_t b);
void isSquare(size_t row, size_t col, int array[row][col]);
void printOut(size_t row, size_t col, int array[row][col]);

int main(void) {
  int rows, cols;
  
  puts("Let's create a 2Dim array!");
    printf("%-6s", "\tHow many rows? ");
    scanf("%d", &rows);
    printf("%-6s", "\tHow many columns? ");
    scanf("%d", &cols);

    //add one to make output nicer
    rows++;
    cols++;
    puts("");

    int arr[rows][cols];

    for(int r = 1; r < rows; r++) {
      for(int c = 1; c < cols; c++) {
        int input;
        printf("\tenter [%d][%d]: ", r, c);
        scanf("%d", &input);
        arr[r][c] = input;
      }
    }

  // sum
  for(int r = 1; r < rows; r++) {
    int rSum = rowSum(rows, cols, arr, r);
    printf("\nSum of row %d = %d", r, rSum);
  }

  puts(""); 

  for(int c = 1; c < cols; c++) {
    int cSum = columnSum(rows, cols, arr, c);
    printf("\nSum of column %d = %d", c, cSum);
  }

  puts(""); 

  isSquare(rows, cols, arr);
  puts("Here is your 2Dim array:");
  printOut(rows, cols, arr);

  exit(0);
}

// returns the maximum value in the 2d array
int max(size_t row, size_t col, int array[row][col]) {
  int retval = 0;

  for(int r = 1; r < row; r++) {
    for(int c = 1; c < col-1; c++) {
      retval += array[r][c];
    }
  }
  return retval;
}

// returns the sum of the elements in Row x of the 2d array
int rowSum(size_t row, size_t col, int array[row][col], size_t a) {
  int retval = 0;

  for(int c = 1; c < col; c++) {
    retval += array[a][c];
  }
  return retval;
}

// returns the sum of the elements in Column x of the array
int columnSum(size_t row, size_t col, int array[row][col], size_t b) {
  int retval = 0;

  for(int r = 1; r < row; r++) {
    retval += array[r][b];
  }
  return retval;
}

// see if square
void isSquare(size_t row, size_t col, int array[row][col]) {
  if(row == col)
    puts("\nThis is a square array.\n");
  else
    puts("\nThis is not a square array.\n");
}

// print array
void printOut(size_t row, size_t col, int array[row][col]) {
  for(int r = 1; r < row; r++) {
    printf("%s", "[");
    for(int c = 1; c < col-1; c++) {
      printf("%d, ", array[r][c]);
    }
    printf("%d]\n", array[r][col - 1]);
  }

}
