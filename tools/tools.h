#ifndef TOOLS_H
#define TOOLS_H

inline int element_wise_product(const int * const a, const int pm * const b, int * const c, const int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        c[i] = a[i] * b[i];
    }
    return 0;
}

inline float dot_product(const float * const x, const float pm * const y, float * z, const int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        *z += x[i]*y[i];
    }
    return 0;
}

#endif // TOOLS_H
