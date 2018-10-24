/*** Don't change any text below */
// Important announcement on Significance of Academic Honor Policy
// The  Academic Honor Policy is an important aspect of keeping the integrity
// and quality of the computer science courses in general. Please don't share
// your project source with any other students on any occasion. I would like
// to let you know that, for the summer 2018 COP3014 course, we found several
// students violated the Academic Honor Policy by sharing their programming
// assignment source in an intentional and inadvertent manners. Please note that
// we will run MOSS" (plagiarism detection software tool) on future COP3014 student
// project submissions together with your summer 2018 project" submissions.
// In case your project source code happens to be >%75" similar to future student
// project source (which is statistically" almost impossible), your grade will
// be invalidated and your academic honor code violation will be reported to Dean's
// office. The following is the quick reference for Academic Honor Policy:"
// https://fda.fsu.edu/sites/g/files/upcbnu636/files/Media/Files/Academic%20Honor%20Policy/AHP%20Quick%20Reference%20Guide%20Nov%202017.pdf
//

/*
 * Perform the following double precision floating point scientific math calculations
 * on request of a user.
 *  ’~’ for  sin (i.e. sin(x))
 *  ’`’ for  cos (i.e. cos(x))
 *  ’ˆ’ for  exp (i.e. exp(x)
 *  ’#’ for myPower of 2 (i.e. 2**x)
 *  ’@’ for myPower of x to y (i.e. x**y)
 *  'x' for exit
 */

#include <iostream>
/* You are *NOT* allowed to use any function from <cstdlib> or <cmath> */


/*
 * Utility function prototypes that you need to implement
 */
bool getCode(char &opcode, bool &unary);
double getValue(void);
double calculate(char op, double leftOperand, double rightOperand);
void printValue(double result);


double myFmod(double operand1, double operand2); // already implemented
double mySin(double operand);                    // already implemented
/*
 * Double precision unary and binary scientific math functions
 * that you need to implement
 */
double myCos(double operand);
double myExp(double operand);
double myPower(double base, double exponent);

using namespace std;

/**
 * \brief main
 * @return return 0 for normal exit
 */
int main() {

   char opcode;       // operation character - '~','`','^','#','@', or 'x'
   bool unary;        // unary is true for '~','`','^', and '#'
                      //       is false for'@'
   do {

      double left;    // left operand
      double right;   // right operand
      double result;  // return value in the calculator

      // getCode function to implement:
      //    (1) Prompt the user to obtain the operation code and
      //            set the boolean variable unary that indicates
      //            whether the operation code is unary or binary.
      //    (2) Return true if operation code is valid, otherwise return false
      if (getCode(opcode, unary)) {

         if (opcode == 'x')
            break;   // if user enters 'x', then terminate loop execution

         // Prompt for the left operand.
         left = getValue();  // get an input double value for left operand from the keyboard
         if (!unary)
            right = getValue(); // get an input double value for right operand from the keyboard

         // perform the scientific math operation according to
         // the opcode, and set result of the operation
         result = calculate(opcode, left, right);

         // Print the value in the calculator.
         printValue(result);
      }
      else {
         cout << "Invalid operation code..." << endl;
         exit(EXIT_FAILURE);
      }
   }
   while (!cin.eof());

   return 0;
}

 /**
  * \brief getValue
  * @return double value read from keyboard
  *
  * Get a double precision floating-point value:
  *    (1) Prompt "Enter a value: " to the console
  *    (2) Get one double value from the keyboard and return the value
  *
  */
double getValue(void) {
     cout << "You need to implement getValue that reads one double value by prompting \"Enter a value: \"!\n";
     return 0.0;
}


/**
 * \brief printValue
 * @param x  double precision floating point value
 *
 *    Display the value x with 7 fractional digits and zero padding
 */
void printValue(double x) {
    cout << "you need to implement printValue that prints the x with 7 fractional digits and zero padding!\n";
    return;
}


/**
 * \brief getCode
 * @param opcode
 * @param unary
 * @return bool value (true/false)
 *
 *   (1)Prompt the user to obtain the operation code, and
 *        set the boolean variable unary that indicates whether
 *        the operation code is unary or binary.
 *   (2) Return true if operation code is valid, otherwise return false
 */
bool getCode(char &opcode, bool &unary) {
    cout << "You need to implement getCode!\n";
    return false;
}


/**
 * \brief calculate
 * @param opcode a single letter opcode - '~','`','^','#',or '@'
 * @param x double precision left operand floating point value
 * @param y double precision right operand floating point value if any
 * @return dobule precision floating point result
 *
 * calculate: perform a double precision scientific math function that
 *            corresponds to the first function parameter opcode, and
 *            return the result
 */
double calculate(char opcode, double x, double y) {
    cout << "You need to implement calculate!\n";
    return 0.0;
}

/**
 * \brief myFmod  double version of modulo operation
 * @param operand1 double data type
 * @param operand2 double data type
 * @return modulo value of operand1 by operand2
 */
double myFmod(double operand1, double operand2) {

   double quotient=operand1/operand2;
   double floor = (double)((int)quotient - (quotient < 0.0f));

   return operand1-(operand2*floor);
}


/**
 * \brief mySin
 * @param opreand double value in terms of radian [-2*PI .. 2*PI]
 *                where PI = 3.14159265358979323846
 * @return double value in [-1.0 .. 1.0]
 *
 *    Using Taylor expansion
 *    sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 *
 *    Note:  sin(pi/6) = sin(0.523598775598299...) = 1/2
 *           We use identity sin(x) = sin(x + 2*PI) to pre-process
 *           x to be between -2*PI and 2*PI.
 */
double mySin(double operand) {

   const double PI = 3.14159265358979323846;
   double x = myFmod(operand, 2*PI); // modulo operation on double value

   // implement Talyor expansion for the sin function above
   double term = 1.0;  // ith term = x^i / i!
   double sum = 0.0;   // sum of first i terms in taylor series

   for (int i = 1; term != 0.0; i++) {
      term = term * (x / i);
      if (i % 4 == 1)
         sum += term;
      else if (i % 4 == 3)
         sum -= term;
   }
   return sum;
}

/**
 * \brief myCos
 * @param opreand double value in terms of radian [-2*PI .. 2*PI]
 *                where PI = 3.14159265358979323846
 * @return double value in [-1.0 .. 1.0]
 *
 *    Using Taylor expansion
 *    cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
 *
 *    Note:  cos(pi/4) = sin(0.523598775598299...) = 1/2
 *           We use identity cos(x) = cos(x + 2*PI) to pre-process
 *           x to be between -2*PI and 2*PI.
 */
double myCos(double operand) {
    cout << "You need to implement myCos!\n";
    return 0.0;
}

/**
 * \brief myExp
 * @param operand double value
 * @return double value, which computes e^operand
 *
 * e^x using Taylor expansion.
 *
 *     e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! ...
 *
 *  e^0  = 1
 *  e^1  = 2.7182...
 *  e^10 = 22026.4657...
 *  e^-10 = 0.000045399...
 */
double myExp(double operand) {
    cout << "You need to implement myExp!\n";
    return 0.0;
}


// Calculate the power of a value raised to another value.
/**
 * \brief myPower
 * @param base  double floating point value
 * @param exponent double floating point value
 * @return double precision floating point value
 *
 *      convert double data type exponent to an integer
 *      raise the base to the converted integer
 *         if the converted integer is negative, then get the absolute value,
 *                              raise the base to the absolute integer value, and
 *                              return the reciprocal
 */
double myPower(double base, double exponent) {
    cout << "You need to implement myPower!\n";
    return 0.0;
}
