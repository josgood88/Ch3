#include "../include/Exercises.h"
#include <cmath>
#include <iostream>
#include <optional>
#include <regex>
#include <stdexcept>
#include <sstream>

// Exercise 10: Write a program that takes an operation followed by two operands and outputs the result. For example:
//    + 100 3.14
//    * 4 5 
// Read the operation into a string called operation and use an if-statement to figure out which operation 
// the user wants. For example, if (operation=="+"). Read the operands into variables of type double. 
// Implement this for operations called +, -, *, /, plus, minus, mul, and div with their obvious meanings. 

namespace {
   std::optional<double> E10UnderTest(std::string str) {
      // input is known to contain text of form "operator operand1 operand2".  No checks made for other formats.
      std::regex rgx("\\s+");
      std::sregex_token_iterator itr(str.begin(), str.end(), rgx, -1);
      std::sregex_token_iterator end;
      // Capture operation and operands
      // Extract string "operation" and stringstreams "istr1" and "istr2" from input string str.
      // Extract doubles "operand1" and "operand2" from those two stringstreams.
      std::string operation = *itr++;
      std::stringstream istr1, istr2;
      istr1 << *itr++; istr2 << *itr++;
      double operand1, operand2;

      if (!(istr1 >> operand1)) throw std::runtime_error(istr1.str() + " doesn't translate to a double.");
      if (!(istr2 >> operand2)) throw std::runtime_error(istr2.str() + " doesn't translate to a double.");

      std::optional<double> result;
      if (operation == "+") result = operand1 + operand2;
      else if (operation == "-") result = operand1 - operand2;
      else if (operation == "*") result = operand1 * operand2;
      else if (operation == "/") result = operand1 / operand2;
      else /* result already set to default {} */;
      return result;
   }

   bool IsCorrect(std::string str, std::optional<double> correct_answer) {
      std::optional<double> result = E10UnderTest(str);
      bool const both_have_value = result.has_value() && correct_answer.has_value();
      bool const neither_has_value = !(result.has_value()) && !(correct_answer.has_value());
      bool is_correct = both_have_value || neither_has_value;
      if (both_have_value) is_correct = fabs(*result - *correct_answer) < 0.00001; // If both have result, must be equal (tolerance due to doubles)
      std::cout << "E10 " << (is_correct ? "Correct" : "Wrong") << " result "
         << (correct_answer.has_value() ? std::to_string(*correct_answer) : "empty optional") << " for " << str << "\n";
      return is_correct;
   }
}

void Exercises::E10() {
   IsCorrect("+ 100 3.14", 103.14);
   IsCorrect("* 4 5", 20);
   IsCorrect("- 4 5", -1);
   IsCorrect("/ 4 5", 0.8);
   IsCorrect("& 4 5", {});
}