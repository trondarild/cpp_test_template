/******************************************************************************


*******************************************************************************/

#include <iostream>
#include "tat_math.h"

int main()
{
    //cout<<"Hello World";
    float *r = new float[4];
    float a[] = {11, 29, 41, 90};
    soft_max_pw(r, a, 2, 4);
    
    print_array(r, 4);
    //cout << exp(90);
    float sumval = sum(r, 4);
    std::cout << "sum: " << sumval << "\n";
    
    
    return 0;
}
