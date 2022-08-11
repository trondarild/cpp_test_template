/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <cmath> 
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
        cout << "s: " << s << "\n";
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


int main()
{
    //cout<<"Hello World";
    float *r = new float[4];
    float a[] = {11, 29, 41, 90};
    soft_max(r, a, 4);
    
    print_array(r, 4);
    //cout << exp(90);
    float sumval = sum(r, 4);
    cout << "sum: " << sumval << "\n";
    
    
    return 0;
}
