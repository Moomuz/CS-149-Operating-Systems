// Shayanna Gatchalian & John Paul Tran
// 4.16.2021

#include <stdlib.h>

int main() 
{
    // array of 100 integers 
    int *data = (int *) malloc(sizeof(int) * 100); 
    // set to zero
    data[100] = 0;
    // free the allocated space to prevent memory leak.
    free(data);
    return 0;
}

// What happens when you run this program?
//  -> There are no errors present. However, we are trying to access an unallocated index. 
//     When we set the array to 0 it causes an error when we call valgrind. 
//     Allocated memory is freed in the end.

// What happens when you run this program using valgrind?
//  -> When the program runs using valgrind, it attempts to write 0 to an out-of-bounds index (index 100 in this case). 
//     This causes an error because the program is trying to access an unallocated memory slot.

/*     Report from valgrind:
// Shayanna Gatchalian & John Paul Tran
// 4.16.2021

#include <stdlib.h>

int main() 
{
    // array of 100 integers 
    int *data = (int *) malloc(sizeof(int) * 100); 
    // set to zero
    data[100] = 0;
    // free the allocated space to prevent memory leak.
    free(data);
    return 0;
}

// What happens when you run this program?
//  -> There are no errors present. However, we are trying to access an unallocated index. 
//     When we set the array to 0 it causes an error when we call valgrind. 
//     Allocated memory is freed in the end.

// What happens when you run this program using valgrind?
//  -> When the program runs using valgrind, it attempts to write 0 to an out-of-bounds index (index 100 in this case). 
//     This causes an error because the program is trying to access an unallocated memory slot.

/*     Report from valgrind:
       ==3120== Memcheck, a memory error detector
       ==3120== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
       ==3120== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
       ==3120== Command: ./q5
       ==3120== 
       ==3120== Invalid write of size 4
       ==3120==    at 0x10918D: main (in /home/shayanna/Desktop/ws12/q5)
       ==3120==  Address 0x4a521d0 is 0 bytes after a block of size 400 alloc'd
       ==3120==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
       ==3120==    by 0x10917E: main (in /home/shayanna/Desktop/ws12/q5)
       ==3120== 
       ==3120== 
       ==3120== HEAP SUMMARY:
       ==3120==     in use at exit: 0 bytes in 0 blocks
       ==3120==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
       ==3120== 
       ==3120== All heap blocks were freed -- no leaks are possible
       ==3120== 
       ==3120== For lists of detected and suppressed errors, rerun with: -s
       ==3120== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/

// Is the program correct?
// -> No, since we have to allocate space before setting array to zero or else we are accessing the wrong space.