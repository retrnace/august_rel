#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6000
#define BYTE_SIZE 8

unsigned long int seq_sum ( const void * );

int main (void){

   int * iptr;
   char * cptr = (char *) malloc (sizeof (char)*MAX_SIZE);
   char * ccptr = cptr;
   unsigned long int sum = 0;
   int num_cycles;
   int i ;

   printf("Please specify number of cycles less than %d : ", MAX_SIZE/6);
   scanf("%d", &num_cycles);

   if (num_cycles >= MAX_SIZE/6)  {
        printf("error: input out of range\n");
        return 1;
   }

   /*
    Create Input vector
    */
   for  (i = 0; i < num_cycles ; i++ ){
        *cptr++ = 0x11;
        *cptr++ = 0x12;
        *cptr++ = 0x13;
        *cptr++ = 0x14;
        *cptr++ = 0x15;
        *cptr++ = 0x16;
        *cptr++ = 0x17;
        *cptr++ = 0x18;
        *cptr++ = 0x19;
        sum += 0x111213 + 0x141516 + 0x171819;
   }

   *cptr++ = 0x00;
   *cptr++ = 0x00;
   *cptr++ = 0x00;

   printf ( "Calculated sum = %lu\n", seq_sum (ccptr));

   seq_sum (ccptr) == sum ? printf("Calculated sequence sum is correct!\n" ): printf("error in calculated sum\n");

    return 0;


}


/*
 * Calculate the sum of an array of 3 byte integers.
 *
 * Assumes integers are unsigned and in big endian format.
 * Array terminated by 3 consecutive 0 bytes.
 */

unsigned long int seq_sum ( const void * ptr){

    unsigned long int sum = 0;
    unsigned int temp = 0;
    const char * p = ptr;

    if (p == NULL){
        return -1;
    }


    for (temp = 0 ; temp = (*p++ << BYTE_SIZE | *p++) << BYTE_SIZE | *p++; sum += temp, temp = 0 );

    return sum;

}
