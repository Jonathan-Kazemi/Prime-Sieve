/*
                           Project 8 - Chapter 4
                     Implementation of Sieve of Eratosthenes

Project Function:    To Find all prime Numbers between 1 and 100,000 and
                     Displaying the last five primes in the Array

Project Description:	To design, develop and test a C program that will use an
                     ARRAY to place all possible numbers from 0-100,000
                     inclusively and seek all PRIME Numbers
*******************************************************************************
Prologue:
    Instructor:         Mr. William Foote
    Author:             Kazemi, Jalal
    Course:             CS 50 - Section 1159 - C Programming
    Created:            Jan. 19, 2018
    Function:           Refer to the description and function above
    Function Name:      is_prime
    Function Variables: upper_range (an integer and in this instance 100,000
    Version Of C Comp:  99
    Included Libraries: STDLIB, STDBOOL, STDIO, STDMATH, STDINT
    Version:            1.0.0

*******************************************************************************
Epilogue:
    Modification by:    Kazemi, Jalal (original author)
    Change Requester:   Kazemi, Jalal
    Change Function:    N/A
    Change Date:        N/A
    Change Version:     N/A
    Change Severity:    N/A

*******************************************************************************
                        Change History

Modification by:        Kazemi, Jalal (original author)
Change Requester:       Kazemi, Jalal
Change Function:        N/A
Change Date:            N/A
Change Version:         N/A
Change Severity:        N/A
*******************************************************************************

*******************************************************************************
 Include necessary Libraries to compile and to use through out the process
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* ****************************************************************************
        Global Initialization Environment
*******************************************************************************/
int upper_range = 100000;
int upper_limit=0;

/* ****************************************************************************
        Function Signature
*******************************************************************************/
void is_prime(int upper_range);

int main(void){

   printf("\n\n\t\t Project 8 - Implementation of The Sieve of Eratosthenes");
   printf(" - Chapter 4\n");
   printf("\n\t\t\t Finding All Prime Numbers Within A Range Of Numbers\n");
	printf("\t\t\t For This Exercise All NATURAL Numbers 2-100,000 Range,\n");
   printf("\t\t\t At End, Display The Last 5 Primes Numbers By Retrieving\n");
   printf("\t\t\t Such Numbers From The Array.\n\n");


/* ****************************************************************************
    Call is_prime Function To Start its Process Finding All Prime Numbers
    Given In A Range (0-100,000 in this instance) and At End Display The Last
            5 Prime Numbers From the Array via An Index or Pointer

******************************************************************************/
    is_prime(upper_range);

/* ****************************************************************************
        EXIT main PGM If everything is OK with Success
******************************************************************************/
exit(EXIT_SUCCESS);
}

/* ****************************************************************************
    Function is_prime:
        Is To Find All Prime Numbers From 0-100,000. At End, Display The Last
        5 Prime Numbers Facilitated By Means Of An Index And Decremented By One
        Seeking Such PRIME Numbers In The Array.

      A[i] is true, for i = 2, 3, 4, ..., not exceeding Square Root of
            upper_range, and
      A[j] is false, for j = i squared + (k*i) for k=0 and not exceeding
            upper_range:

******************************************************************************/
void is_prime(int upper_range){

    upper_limit = sqrt(upper_range);

/* ****************************************************************************
    Due to slow speed of memory allocation and other related performance issues
    Allocate enough memory ahead of time through the use of CALLOC which
    initializes allocated memory to zeros.

    If any error in allocation process occurs then STOP, issue meaningful MSG
    to the end user and exit gracefully with a return code of -1 indicating
    what happened.

******************************************************************************/
    int *array_of_numbers = calloc(3*upper_range, sizeof(int_fast32_t));
    if(array_of_numbers == NULL) {
        printf("\n\n\n\tError!!!  Insufficient Space. Memory Can Not Be ");
        printf("Allocated.");
        printf("\n\tClose all unnecessary Applications To Free Memory and ");
        printf("Try Again.\n");
        printf("\n\tAlternatively, You May Reduce The SIZE OF ARRAY and Try ");
        printf("gain.\n");
    exit(-1); }

/* ****************************************************************************
    Since there are no memory issues, assign the first two CELLs with "0".
    Numbers 0 and 1 are not PRIME Numbers.
******************************************************************************/
    array_of_numbers[0] = false;
    array_of_numbers[1] = false;

/* ****************************************************************************
    Fill the Array with all possible Numbers from 2 to the upper range and
    presume all are PRIME numbers.
******************************************************************************/
    for (int i=2;i<=upper_range;i++) {
        array_of_numbers[i] = true;}

/* ****************************************************************************
      Set up Major iteration process for finding PRIMES
      Seek and Remove all NON-PRIMES Numbers by setting a False Flag for them
******************************************************************************/
   for (int i=2; i<=upper_limit;i++){
      if (array_of_numbers[i]){
         int j=0;
            for (int k=0; k<=upper_range;k++){
               j = (i*i)+(k*i);
               array_of_numbers[j] = false;
               if (j>upper_range) k = j;}
      }
   }

/* ****************************************************************************
    Issue MSGS to the End User as what would be next in the process.
    What'd be next is just displaying the last 5 PRIME Numbers via pointing
    to the elements of the array and check the true or false flags set by the
    process earlier
******************************************************************************/
    printf("\n\t\t\tLast 5 PRIME Numbers in The");
    printf(" Upper Range 0f %d Are:\n", upper_range);
    printf("\t\t\t______________________________________________________\n\n");

    int j = 1;
    int i = upper_range;
    bool found = true;

    while (found){
        if(array_of_numbers[i] == 1){
            printf("\t\t\t\t\t\t%d\n", i--);
            j++;
            if (j>5) found=false;}
        else --i;}
free(array_of_numbers);
}