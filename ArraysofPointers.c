/*
Zachary Laug
CIS 2107
Lab 5
2D Arrays and Pointers to Functions
*/

#include <stdio.h>
#include <stdlib.h>
#define exams 4
#define students 3

// prototypes for functions
void maximum(const int grades[][exams], size_t studen, size_t tests);
void minimum(const int grades[][exams], size_t studen, size_t tests);
void average(const int grades[][exams], size_t studen, size_t tests);
void printArray(const int grades[][exams], size_t studen, size_t tests);

// main function
int main(void) {
   // get grades for three students
   int grades[students][exams] =
      { { 56, 23, 76, 78 },
        { 93, 67, 92, 96 },
        { 82, 71, 93, 87 } };

   // array of pointers to functions
   void(*processGrades[4])(const int[][exams], size_t, size_t) = { printArray, minimum, maximum, average };

   puts("\nEnter a choice:");
      puts("\t0  Print the array of grades");
      puts("\t1  Find the minimum grade");
      puts("\t2  Find the maximum grade");
      puts("\t3  Print the average on all tests for each student");
      puts("\t4  End Program"); 
   size_t input;
   scanf("%zu", &input);

   while(input < 4)
   {
     (*processGrades[input])(grades, students, exams);

     puts("\nEnter a choice:");
        puts("\t0  Print the array of grades");
        puts("\t1  Find the minimum grade");
        puts("\t2  Find the maximum grade");
        puts("\t3  Print the average on all tests for each student");
        puts("\t4  End Program"); 
     scanf("%zu", &input);
   }
   exit(0);
}

// This function finds the lowest grade
void minimum(const int grades[][exams], size_t studen, size_t tests)
{
   int min = 100; // start with maximum

   // cycle through grades
   for (size_t i = 0; i < studen; ++i) {
      for (size_t j = 0; j < tests; ++j) {
         if (grades[i][j] < min) {
            min = grades[i][j];
         }
      }
   }

   printf("\nLowest grade is: %d\n", min);
}

// Find the maximum grade
void maximum(const int grades[][exams], size_t studen, size_t tests) {
   int max = 0; // start with minimum

   // cycle through grades
   for (size_t i = 0; i < studen; ++i) {
      for (size_t j = 0; j < tests; ++j) {
         if (grades[i][j] > max) {
            max = grades[i][j];
         }
      }
   }

   printf("\nHighest grade is: %d\n", max);
}

// Finds the avg grade for a certain student
void average(const int grades[][exams], size_t studen, size_t tests) {
   for (int student = 0; student < studen; ++student) {
       int tot = 0;

       for (size_t i = 0; i < tests; ++i) {
          tot += grades[student][i];
       }
       double studentAvg = (double) tot / tests;

       printf("The average grade for student %u is %.2f\n", student, studentAvg);
     }
}

// Function for output the array
void printArray(const int grades[][exams], size_t studen, size_t tests)
{
   puts("\nThe array is:");
   printf("%s", "                 [0]  [1]  [2]  [3]");

   for (int i = 0; i < studen; ++i) {
      printf("\ngrades[%u] ", i);
      
      for (size_t j = 0; j < tests; ++j) {
         printf("%-5d", grades[i][j]);
      }
   }
   puts("");
}
