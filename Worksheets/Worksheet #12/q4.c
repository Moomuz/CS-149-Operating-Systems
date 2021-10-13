// Shayanna Gatchalian & John Paul Tran
// 4.16.2021

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // allocate memory using malloc()
    char *snafu = (char *) malloc(sizeof(char) * 16);   // allocate space for a string of length 15 + NULL char (total size: 16)
    printf("Enter a string:\n");
    scanf("%s", snafu);
    printf("Entered string: %s\n", snafu);
    // do not free allocated memory with malloc()
    return 0;
}


// What happens when this program runs?
//  -> When this program runs, memory is allocated for the inputted string (of size 16, as shown earlier). 
//     The program then prompts the user to input a string, the data gets saved, then the string is, at last, printed. 
//     Then, the program exits without freeing the allocated space, ending in a memory leak.

 
// Can you use gdb to find any problems with it?
//  -> gdb cannot be used in this case, as it will not report any errors.

// How about valgrind (with the --leak-check=yes flag)?
//  -> Valgrind can determine if there is a memory leak within the program. 
//     Memory leak is prsent since we did not free the allocated space before exiting.
/*     Report from valgrind:

       ==2664== Memcheck, a memory error detector
       ==2664== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
       ==2664== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
       ==2664== Command: ./q4
       ==2664== 
       Enter a string:
       snafu
       Entered string: snafu
       ==2664== 
       ==2664== HEAP SUMMARY:
       ==2664==     in use at exit: 16 bytes in 1 blocks
       ==2664==   total heap usage: 3 allocs, 2 frees, 2,064 bytes allocated
       ==2664== 
       ==2664== 16 bytes in 1 blocks are definitely lost in loss record 1 of 1
       ==2664==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
       ==2664==    by 0x1091BE: main (in /home/shayanna/Desktop/ws12/q4)
       ==2664== 
       ==2664== LEAK SUMMARY:
       ==2664==    definitely lost: 16 bytes in 1 blocks
       ==2664==    indirectly lost: 0 bytes in 0 blocks
       ==2664==      possibly lost: 0 bytes in 0 blocks
       ==2664==    still reachable: 0 bytes in 0 blocks
       ==2664==         suppressed: 0 bytes in 0 blocks
       ==2664== 
       ==2664== For lists of detected and suppressed errors, rerun with: -s
       ==2664== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */