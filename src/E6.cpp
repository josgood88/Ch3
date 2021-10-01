#include "../include/Exercises.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

namespace {
   std::tuple<int,int,int> E6UnderTest(std::tuple<int,int,int> t) {
      std::vector<int> v;
      v.push_back(std::get<0>(t));
      v.push_back(std::get<1>(t));
      v.push_back(std::get<2>(t));
      std::sort(v.begin(),v.end());
      auto itr = v.begin();
      auto result = std::make_tuple(*itr++,*itr++,*itr);
      return result;
   }

   bool IsCorrect(std::tuple<int,int,int> test_item, std::tuple<int,int,int> correct_answer) {
      auto test_result = E6UnderTest(test_item);
      auto is_correct = test_result == correct_answer;
      std::cout << "E6 "
                << (is_correct ? "Correct" : "Wrong") << " result for ("
                << std::get<0>(test_item) << ", "
                << std::get<1>(test_item) << ", "
                << std::get<2>(test_item) << ").\n";
      return is_correct;
   }
}

void Exercises::E6() { 
   IsCorrect(std::make_tuple(1,2,3),std::make_tuple(1,2,3));
   IsCorrect(std::make_tuple(3,2,1),std::make_tuple(1,2,3));
   IsCorrect(std::make_tuple(1,0,-1),std::make_tuple(-1,0,1));

}