// Shayanna Gatchalian & John Paul Tran
// 4.16.2021

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // array of 5 integers
    int *snafu = (int *) malloc(sizeof(int) * 5);   
    snafu[0] = 0;
    snafu[1] = 1;
    snafu[2] = 2;
    snafu[3] = 3;
    snafu[4] = 4;
    // free allocated array
    free(snafu); 
    printf("snafu[2] = %d\n", snafu[2]);
    return 0;
}

// Does the program run?
// -> The program successfully compiles and runs without errors, but the output is "snafu[2] = 797720592", 
//    instead of the expected "snafu[2] = 2".

// What happens when you use valgrind on it?
// -> It is trying to do an invalid read because we deallocated the address space that was pointed by the array.
//    Therefore, the space is uninitialized and we are trying to read a freed address space.

/*    Report from valgrind: 
      ==3075== Memcheck, a memory error detector
      ==3075== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
      ==3075== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
      ==3075== Command: ./q6
      ==3075== 
      ==3075== Invalid read of size 4
      ==3075==    at 0x1091F9: main (in /home/shayanna/Desktop/ws12/q6)
      ==3075==  Address 0x4a52048 is 8 bytes inside a block of size 20 free'd
      ==3075==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
      ==3075==    by 0x1091F0: main (in /home/shayanna/Desktop/ws12/q6)
      ==3075==  Block was alloc'd at
      ==3075==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
      ==3075==    by 0x10919E: main (in /home/shayanna/Desktop/ws12/q6)
      ==3075== 
      snafu[2] = 2
      ==3075== 
      ==3075== HEAP SUMMARY:
      ==3075==     in use at exit: 0 bytes in 0 blocks
      ==3075==   total heap usage: 2 allocs, 2 frees, 1,044 bytes allocated
      ==3075== 
      ==3075== All heap blocks were freed -- no leaks are possible
      ==3075== 
      ==3075== For lists of detected and suppressed errors, rerun with: -s
      ==3075== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */