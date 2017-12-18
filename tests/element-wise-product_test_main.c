#include <stdio.h>
#include <cycle_count.h>
#include "../tools/tools.h"

#define     LENGTH      4096

#define     OPTIMIZED

int a_buffer[LENGTH];
int c_buffer[LENGTH];

#ifdef OPTIMIZED
    int pm b_buffer[LENGTH];
#else
    int b_buffer[LENGTH];
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
    element_wise_product(a_buffer, (int pm *)b_buffer, c_buffer, LENGTH);    

    STOP_CYCLE_COUNT(final_count, start_count);
    PRINT_CYCLES("Number of cycles : ", final_count);
    
    // Check output
    printf("%d, %d, %d\n", c_buffer[10], c_buffer[1], c_buffer[2]);

    return 0;
}
