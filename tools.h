#ifndef TOOLS_H
#define TOOLS_H

inline int element_wise_product(const int * const a_buffer, const int pm * const b_buffer, int * const c_buffer, const int length)
{
    int i;
    for(i = 0 ; i < length ; i++)
    {
        c_buffer[i] = a_buffer[i] * b_buffer[i];
    }
    return 0;
}

#endif // TOOLS_H
