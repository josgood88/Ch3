#include "../include/Exercises.h"
#include <algorithm>
#include <iostream>
#include <sstream>

std::string Ratio(int,int);
std::string Ratio2(int,int);

void Exercises::E4() {
   int val1, val2;
   std::cout << "Please enter two integers, separated by a space...";
   std::cin >> val1 >> val2;
   std::cout << "The values are: " << val1 << " and " << val2 << ". ";
   if (val1 == val2) std::cout << "The two values are equal. \n";
   else {
      std::cout << std::max(val1,val2) << " is the larger. " << std::min(val1,val2) << " is the smaller.\n";   
   }
   std::cout << "Their sum is " << val1+val2 << 
                ", difference is " << std::abs(val1-val2) << 
                ", product is " << val1*val2 << ".\n";
   std::cout << (val1 == val2 ? "1" : Ratio(val1,val2)) << ".\n";
}

std::string Ratio(int lhs, int rhs) {
   std::stringstream ss;
   ss << "Their ratio is " << Ratio2(lhs,rhs) << " or " << Ratio2(rhs,lhs) << " depending on how you look at them";
   return ss.str();
}

std::string Ratio2(int lhs, int rhs) {
   std::stringstream ss;
   ss << lhs << "/" << rhs << " ("  << (rhs == 0 ? 0 : (double)lhs/rhs) << ").";
   return ss.str();
}