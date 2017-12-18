#include <stdio.h>
#include <cycle_count.h>
#include "../tools/tools.h"

cycle_t start_count ;
cycle_t final_count ;
cycle_t temp_cycle_count ;

#define LENGTH 1024

float x[LENGTH];
float pm y[LENGTH];
    
int main(void)
{
    float c;
    int i;
    
    for(i = 0; i < LENGTH; i++)
    {
        x[i] = 2.;
        y[i] = 5.;
    }

    float z = 0;
    START_CYCLE_COUNT(start_count);
    dot_product(x, y, &z, LENGTH);
    STOP_CYCLE_COUNT(final_count,start_count);
    PRINT_CYCLES("Number of cycles in C : ",final_count);
    
    printf("Check result in C, c = %f\n", z);
        
	return 0;
}
