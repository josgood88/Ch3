#include "../include/Exercises.h"
#include <iostream>

namespace {
   bool E8UnderTest(int value) {  return value % 2 == 0; }
   bool IsCorrect(int value, bool correct_answer) { 
      auto result = E8UnderTest(value) == correct_answer;
      std::cout << "E8 " << (result ? "Correct" : "Wrong") << " result for " << value << "\n";
      return result;
   }
}

void Exercises::E8() { 
   IsCorrect(1,false);
   IsCorrect(2,true);
   IsCorrect(0,true);

}