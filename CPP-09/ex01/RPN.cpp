#include "RPN.hpp"

////CONSTRUCTORS & DESTRUCTORS
RPN::RPN() : _stack(){}
RPN::~RPN(){}

////MEMBER FUNCS
//checkers -> identify/ handle +-*/
bool    RPN::isOperator(const std::string& token) const
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

//check valid int
//std::strtol: converts the string to a long. It also sets end to the first non-numeric character
//errno = 0;: clears any old error state before conversion
//ERANGE: indicates that the result is out of range for the type long
bool RPN::isValidINT(const std::string& token, int& value) const
{
    char* end = NULL;
    errno = 0;
    long result = std::strtol(token.c_str(), &end, 10);

    if (*end != '\0' || errno == ERANGE || result > INT_MAX || result < INT_MIN)
        return false;

    value = static_cast<int>(result);
    return true;
    // for (size_t i = 0; i < token.length(); i++)
    // {
    //     if (!isdigit(token[i]))
    //         return false;        
    // }
    // return true;
}

//apply operator
int    RPN::applyOperator(int front, int latter, const std::string& op) const
{
    if (op == "+")
        return front + latter;
    else if (op == "-")
        return front - latter;
    else if (op == "*")
        return front * latter;
    else if (op == "/")
    {
        if (latter == 0)
        {
            std::cerr << "Error: division by zero." << std::endl;
            exit(1);
        }
        return front / latter;
    }
        std::cerr << "Error" << std::endl;
        return 1;//error return 1? 

}

void    RPN::applyPrintStack(const std::stack<int>& stack)
{
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl; //add to the stack top
}

//execRPN
//std::atoi(token.c_str()); -> add c_str() -> valid in C++98
//token.c_str() converts the std::string to a const char* for atoi
//atoi() doesn't check for overflow
void    RPN::execRPN(const std::string& args)
{
    std::istringstream iss(args);
    std::string token;
    int intMAX = std::numeric_limits<int>::max();
    int intMIN = std::numeric_limits<int>::min();
    int result = 0;

    while (iss >> token)
    {
        //check if nb
        int nb = 0;
        if (isValidINT(token, nb))
            _stack.push(nb); //add to stack
        //check if valid operator
        else if (isOperator(token))
        {
            //check operator pos -> should be 2 nb in stack first
            if (_stack.size() < 2)
            {
                std::cerr << "Error: respect RPN rule, plz." << std::endl;
                return;
            }
            //push 2 nbs
            int latter = _stack.top();
            _stack.pop();// pop the first nb (later)

            int front = _stack.top();
            _stack.pop();// pop the second nb (front)

            //pop 2 nbs, then apply operator, then push back the result to stack
            result = applyOperator(front, latter, token);
            _stack.push(result); //push back the result

            //check if result is valid
            if (result > intMAX || result < intMIN)
            {
                std::cerr << "Error: Number out of range." << std::endl;
                return;
            } 
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;

        }
    }
    applyPrintStack(_stack);
}


/* stack example

"3 4 +" => (3 + 4)

read 3 -> push 3 => stack = [3] (TOP)
read 4 -> push 4 => stack = [4] (TOP)
                            [3]
read +  
-> pop 4, pop 3 
-> apply + => (3 + 4 = 7)
--------> push 7 => stack = [7] (TOP)



*/