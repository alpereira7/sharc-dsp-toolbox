#include <stdio.h>
#include <cycle_count.h>

#define     LENGTH      4096
#define     OPTIMIZED

#ifdef OPTIMIZED
    section ("seg_dmda") int a_buffer[LENGTH];
    section ("seg_pmda") int pm b_buffer[LENGTH];
    section ("seg_dmda") int c_buffer[LENGTH];
#else
    int a_buffer[LENGTH];
    int b_buffer[LENGTH];
    int c_buffer[LENGTH];
#endif

cycle_t start_count, final_count, temp_cycle_count ;

int i;

int main(void)
{
    // Initialize buffers
    for(i = 0 ; i < LENGTH ; i++)
    {
        a_buffer[i] = i;
        b_buffer[i] = i;
    }

    START_CYCLE_COUNT(start_count);

    // Element-wise product loop
    for(i = 0 ; i < LENGTH ; i++)
    {
        c_buffer[i] = a_buffer[i] * b_buffer[i];
    }

    STOP_CYCLE_COUNT(final_count, start_count);
    PRINT_CYCLES("Number of cycles : ", final_count);

    return 0;
}
