#include "../include/Exercises.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include <sstream>
#include <variant>

// Exercise 10: Write a program that takes an operation followed by two operands and outputs the result. For example:
//    + 100 3.14
//    * 4 5 
// Read the operation into a string called operation and use an if-statement to figure out which operation 
// the user wants. For example, if (operation=="+"). Read the operands into variables of type double. 
// Implement this for operations called +, -, *, /, plus, minus, mul, and div with their obvious meanings. 

namespace {
   double E10UnderTest(std::string str) {   
      // input is known to contain text of form "operator operand1 operand2".  No checks for other formats.
      std::regex rgx("\\s+");
      std::sregex_token_iterator itr(str.begin(),str.end(),rgx,-1);
      std::sregex_token_iterator end;
      // Capture operation and operands
      std::string operation = *itr++;
      std::stringstream istr1, istr2;
      istr1 << *itr++; istr2 << *itr++;
      double operand1, operand2, result;
      if (!(istr1 >> operand1)) throw std::runtime_error(istr1.str() + " doesn't translate to a double.");
      if (!(istr2 >> operand2)) throw std::runtime_error(istr2.str() + " doesn't translate to a double.");

      if      (operation == "+") result = operand1 + operand2;
      else if (operation == "-") result = operand1 - operand2;
      else if (operation == "*") result = operand1 * operand2;
      else if (operation == "/") result = operand1 / operand2;
      else throw new std::runtime_error("Unknown operator " + operation);
      return result;
   }

   bool IsCorrect(std::string str, double correct_answer) { 
      bool is_correct = E10UnderTest(str) == correct_answer;
      std::cout << "E10 " << (is_correct ? "Correct" : "Wrong") << " result " << correct_answer << " for " << str << "\n";
      return is_correct;
   }
}

void Exercises::E10() { 
   IsCorrect("+ 100 3.14",103.14);
   IsCorrect("* 4 5",20);
   IsCorrect("- 4 5",-1);
   IsCorrect("/ 4 5",0.8);
}