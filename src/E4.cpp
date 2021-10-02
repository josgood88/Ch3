#include "../include/Exercises.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

enum Result {	// Positions within the tuple
	EQUL, // 0	bool	   whether lhs == rhs
	LARG, // 1	int		larger value
	SMAL, // 2	int		smaller value
	SUM,  // 3	int		sum
	DIFF, // 4	int		difference
	PROD, // 5	int		product
	RAT1, // 6	double	lhs/rhs
	RAT2  // 7	double	rhs/lhs
};

using Alias = std::tuple<bool,int,int,int,int,int,double,double>;

namespace {
	Alias E4UnderTest(std::tuple<int,int> t) {
		Alias result;
		int val1 = std::get<0>(t), val2 = std::get<1>(t);
		std::get<EQUL>(result) = val1 == val2;
		std::get<LARG>(result) = std::max(val1,val2);
		std::get<SMAL>(result) = std::min(val1,val2);
		std::get<SUM >(result) = val1+val2;
		std::get<DIFF>(result) = std::abs(val1-val2);
		std::get<PROD>(result) = val1*val2;
		std::get<RAT1>(result) = (double)val1 / val2;
		std::get<RAT2>(result) = (double)val2 / val1;
		return result;
	   }

   bool IsCorrect(std::tuple<int,int> test_item, Alias correct_answer) {
      auto test_result = E4UnderTest(test_item);
      auto is_correct = test_result == correct_answer;
      std::cout << "E4 "
                << (is_correct ? "Correct" : "Wrong") << " result for ("
                << std::get<0>(test_item) << ", "
                << std::get<1>(test_item) << ").\n";
      return is_correct;
   }
}

void Exercises::E4() {
   IsCorrect(std::make_tuple(1,2),std::make_tuple(false,2,1,3,1,2,0.5,2));
}


