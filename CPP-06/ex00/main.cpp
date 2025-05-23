#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2 || av[1][0] == '\0')
    {
        std::cerr << "Error : Invalid Argument" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}

/* OUTPUT
Input | Expected Output (char, int, float, double)
a     | char: 'a', int: 97, float: 97.0f, double: 97.0
0     | char: Non displayable, int: 48, float: 48.0f, double: 48.0
42    | char: '*', int: 42, float: 42.0f, double: 42.0
-42   | char: non-displayable, int: -42, float: -42.0f, double: -42.0
4.2f  | char: Non displayable, int: 4, float: 4.2f, double: 4.2
4.2   | char: Non displayable, int: 4, float: 4.2f, double: 4.2
nan   | char: impossible, int: impossible, float: nanf, double: nan
nanf  | char: impossible, int: impossible, float: nanf, double: nan
+inf  | char: impossible, int: impossible, float: inff, double: inf
-inff | char: impossible, int: impossible, float: -inff, double: -inf
hello | all: impossible (invalid literal)
*/

/*
nan / nanf : Can't be cast to char or int because NaN isn't a number.
+inf, -inf / +inff, -inff :	Infinity can’t be represented as int or char.
hello : Not a number — parsing it fails.
float/double with decimals (e.g., 4.2f) → char : Not valid or meaningful for display as a character.
*/
