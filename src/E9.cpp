#include "../include/Exercises.h"
#include <iostream>
#include <map>
#include <optional>

// Exercise 9: Write a program that converts spelled out numbers such as "zero" and "two" into digits, 
// such as 0 and 2. When the user inputs a number print out the corresponding digit. Do it for the 
// values 0,1,2,3, and 4 and write out "not a number I know" if the user enters something that doesn't 
// correspond, such as ``stupid computer!'' 

namespace {
   enum string_value { zero, one, two, three, four};
   std::map<std::string,string_value> xlate_map = { 
      {"zero", zero}, {"one",one}, {"two",two}, {"three",three}, {"four",four} 
      };

   std::optional<int> E9UnderTest(std::string str) {   
       for (auto element : xlate_map) {
          if (str == element.first) return element.second;
       }
       return {};
   }
   bool IsCorrect(std::string str, std::optional<int> correct_answer) { 
      bool is_correct = false;
      auto rdigit = E9UnderTest(str);
      if (!rdigit && !correct_answer) { std::cout << "E9 " << "Correct: no answer for " << str  << "\n"; is_correct = true; }
      else if (rdigit && !correct_answer) std::cout << "E9 " << "Wrong: no answer for " << str  << "\n";
      else if (!rdigit && correct_answer) std::cout << "E9 " << "Wrong: have answer for " << str  << "\n";
      else {
         is_correct = *rdigit == *correct_answer;
         std::cout << "E9 " << (is_correct ? "Correct" : "Wrong") << " result " << *rdigit << " for " << str << "\n";
       }
      return is_correct;
   }
}

void Exercises::E9() { 
   IsCorrect("zero",0);
   IsCorrect("one",1);
   IsCorrect("two",2);
   IsCorrect("three",3);
   IsCorrect("four",4);
   IsCorrect("five",{});
}