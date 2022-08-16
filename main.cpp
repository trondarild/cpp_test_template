/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <string>
#include "tat_math.h"
#include "tat_utils.h"

int main()
{
    //cout<<"Hello World";
    float **a = zeros(3,1);
    sequentials(a, 0, 3,1);
    float **b = zeros(3,1);
    float **c = zeros(6,1);
    hstack(c, a, 3, b, 3, 1);
    
    print_matrix("a", a, 3,1);
    print_matrix("b", b, 3,1);
    print_matrix("c", c, 6,1);
    
    destroy_matrix(a);
    destroy_matrix(b);
    destroy_matrix(c);
    return 0;
}


int _main(int argc, char** argv)
{
    std::string lineInput;
    while (std::cin >> lineInput) {
        std::cout << "from pipe: " << lineInput << "\n";
    }

    std::cout << "You have entered " << argc
         << " arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << "\n";
  
    
    return 0;
}
