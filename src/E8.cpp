#include "../include/Exercises.h"
#include <iostream>

// Exercise 8: Write a program to test an integer value to determine if it is odd or even. 
// As always, make sure your output is clear and complete. In other words, don't just output "yes" or "no". 
// Your output should stand alone, like "The value 4 is an even number."" 
//Hint: see the Remainder (modulo) operator in 2.4.

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