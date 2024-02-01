/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : range-based iteration over a class
 ****
 ****************************************************************/

// name:          Alana Gaughan

#include <iostream>
using std::boolalpha;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::any_of;

// NOTE: this may work for school computer
//#include <range/v3/all.hpp>
#include<ranges>

bool is_perfect(int num) 
{
    int factor_sum = 0;        // This variable stores the sum of the divisors

    // std::ranges::for_each(std::ranges::views::iota(1, floor(sqrt(num) + 1)), [num](int div) {if (num % div == 0) { cout << div << "\n"; }; });
    std::ranges::for_each(std::ranges::views::iota(1, floor(sqrt(num) + 1)),  // the divisors iterate through this range bc it includes the square root of a number 
        [num, &factor_sum](int div) 
        {
            if (num % div == 0)                                               // checks if a divisor is a factor
            {
                if (num / div != sqrt(num))
                {
                    factor_sum += (div + (int)(num / div));                  // adds the divisors and the dividends to the factor sum
                }
                else
                {
                    factor_sum += div;                                       // in case the number is a perfect square, it only adds the square root once
                };
            }
        });
    factor_sum -= num;                                                      // this line is needed because the number itself does not count as a factor
    
    return factor_sum == num;                                               // check if sum_factors is equal to the integer
}

int main() 
{
    int upper_bound = 15000;                                                          // This number can be changed to find the perfect numbers below any upper limit
    cout << "The perfect numbers below " << upper_bound << " are: ";

    
    // for each positive integer, run a function to find the sum of the divisors = the integer
    std::ranges::for_each(std::ranges::views::iota(2, upper_bound), [](int i) { if (is_perfect(i)) { cout << i << ", "; }; }); // NOTE: 0 and 1 are NOT perfect numbers bc 1 only has 1 divisor so it doesn't count, and 0 is not a positive integer. Therefore, my loop begins at 2.
    

    return 0;
}
