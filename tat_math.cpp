#include <iostream>
#include <cmath> 
#include "tat_math.h"
#include "tat_utils.h"

using namespace std;

float* reset_array(float *r, int size) {
    for (int i=0; i < size; ++i)
        r[i] = 0;
    return r;
}

float sum(float *a, int size){
    float retval = 0;
    for (int i=0; i < size; ++i)
        retval += a[i];
    return retval;
}

void print_array(float *a, int size) {
    for (int i=0; i < size; ++i)
        cout << a[i] << ", ";
    cout << "\n";
}

float *
soft_max_exp(float *r, float *a, int size)
{
    // TODO check if vector op exists
    for (int i=0; i < size; ++i)
        r[i] = exp(a[i]);
    float s=0;
    for (int i=0; i < size; ++i)
        s += r[i];
    if(s>0){
        for (int i=0; i < size; ++i)
            r[i] = r[i]/s;
    }
    else
        reset_array(r, size);
    return r;
}

float *
soft_max_pw(float *r, float *a, float pw, int size)
{
    // TODO check if vector op exists
    for (int i=0; i < size; ++i)
        r[i] = pow(a[i], 2);
    float s=0;
    for (int i=0; i < size; ++i)
        s += r[i];
    if(s>0){
        cout << "s: " << s << "\n";
        for (int i=0; i < size; ++i)
            r[i] = r[i]/s;
    }
    else
        reset_array(r, size);
    return r;
}

float **
sequentials(float **retval, float start, int x, int y)
{
    float ctr = start;
    for(int j=0; j<y; j++)
    {
    	for(int i=0; i<x; i++)
        {
            retval[j][i] = ctr;
            ctr += 1.f;
        }
    }
    return retval;
}

float **
transpose(float ** a_T, float ** a, int sizex, int sizey)
{
    for(int i=0; i<sizex; i++)
        for(int j=0; j<sizey; j++)
            a_T[j][i] = a[i][j];
    return a_T;
}

float** 
hstack(float **retval, 
            float **a, 
            int ax, 
            float **b, 
            int bx, 
            int rety)
{
    /**
     * @brief Horizontally stack matrices
     * 
     */
    for (int j = 0, rj=0, aj=0, bj=0; 
        j < rety; 
        j++, rj += ax + bx, aj += ax, bj += bx)
    {
      copy_array(retval[0]+rj, a[0]+aj, ax);
      copy_array(retval[0]+rj+ax, b[0]+bj, bx);   
    }
    return retval;
}

float**
vstack(float **retval, float **a, int ay, float **b, int by, int rx)
{
    /**
     * @brief Vertically stack matrices
     * 
     */
    for (int j = 0; j < ay; j++)
        copy_array(retval[j], a[j], rx);
    for (int j = 0; j < by; j++)
        copy_array(retval[j+ay], b[j], rx);
    return retval;
}
