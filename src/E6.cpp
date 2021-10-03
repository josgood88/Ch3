#include "../include/Exercises.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

// Exercise 6:
// Write a program that prompts the user to enter 3 integer values, and then outputs the values 
// in numerical sequence separated by commas. So: if the user enters the values 10 4 6, the output 
// should be 4, 6, 10. If two values are the same, they should just be ordered together. So, the 
//input 4 5 4 should give 4, 4, 5.

namespace {
   std::tuple<int,int,int> E6UnderTest(std::tuple<int,int,int> t) {
      std::vector<int> v;
      v.push_back(std::get<0>(t));
      v.push_back(std::get<1>(t));
      v.push_back(std::get<2>(t));
      std::sort(v.begin(),v.end());
      return std::make_tuple(v[0],v[1],v[2]);
   }

   bool IsCorrect(std::tuple<int,int,int> test_item, std::tuple<int,int,int> correct_answer) {
      auto test_result = E6UnderTest(test_item);
      auto is_correct = test_result == correct_answer;
      std::cout << "E6 "
                << (is_correct ? "Correct" : "Wrong") << " result for ("
                << std::get<0>(test_item) << ", "
                << std::get<1>(test_item) << ", "
                << std::get<2>(test_item) << ") -- ";
auto [ a1, a2, a3 ] = test_result;
auto [ b1, b2, b3 ] = correct_answer;
std::cout << a1    << "," << a2    << "," << a3 << " | " << b1 << "," << b2 << "," << b3 << "\n";

      return is_correct;
   }
}

void Exercises::E6() { 
   IsCorrect(std::make_tuple(1,2,3),std::make_tuple(1,2,3));
   IsCorrect(std::make_tuple(3,2,1),std::make_tuple(1,2,3));
   IsCorrect(std::make_tuple(1,0,-1),std::make_tuple(-1,0,1));

}