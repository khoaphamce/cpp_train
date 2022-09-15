#include <iostream>
#include <string>
#include <stack>
#include <vector>

/**
 *  Check if the input is an operand
 */
int isArith(char inputChar) {
    if (inputChar == '+' || inputChar == '-')
        return 1;
    if (inputChar == '*' || inputChar == '/')
        return 2;
    if (inputChar == '(' || inputChar == ')')
        return -1;
    return 0;
}


std::vector <std::string> inToPost(std::string inFix) {
    std::vector <std::string> postFix;
    std::stack <std::string> arith;

    /**
     *  Loop to detect and process all expression
     *  Detail: This loop process expression
     */

    for (int i = 0; i < inFix.length(); i++) {
        /**
         *  Extract number
         */
        std::string extractNumber = "";
        int j = i;
        while ((inFix[j] >= '0') && (inFix[j] <= '9') && (j < inFix.length())) {
            extractNumber = extractNumber + inFix[j];
            j++;
        }
        ;
        /**
         *  add number to postFix
         */
        if (extractNumber.length() != 0) {
            postFix.push_back(extractNumber);

            if (extractNumber.length() > 1)
                i = j;

            continue;
        }

        else if (inFix[i] == '(')
            arith.push(std::string(1, inFix[i]));
        /**
         *  Check close parenthese
         */
        else if (inFix[i] == ')') {
            while (!arith.empty() && arith.top()[0] != '(') {
                postFix.push_back(arith.top());
                arith.pop();
            }
            if (!arith.empty())
                arith.pop();

        }

        /**
         *  Check arithmetic
         */
        else if (isArith(inFix[i]) > 0) {
            while (!arith.empty()
                && isArith(inFix[i]) <= isArith(arith.top()[0]))
            {
                postFix.push_back(arith.top());
                arith.pop();
            }

            arith.push(std::string(1, inFix[i]));
        }
    }

    while (!arith.empty()) {
        postFix.push_back(arith.top());
        arith.pop();
    }
    /**
     *  [END] of loop
     */

    return postFix;

}

float Calculate(std::vector<std::string> postFix) {
    std::stack<int> numStack;

    for (int i = 0; i < postFix.size(); i++) {
        /**
         *  Number check
         */
        std::string extractNumber = "";
        int j = 0;
        while ((postFix[i][j] >= '0') && (postFix[i][j] <= '9') && (j < postFix[i].length())) {
            extractNumber = extractNumber + postFix[i][j];
            j++;
        }
        /**
         *  add number to stack
         */
        if (extractNumber.length() != 0)
            numStack.push(std::stoi(extractNumber));
        /**
         *  Arith check
         */
        else if (isArith(postFix[i][0]) > 0) {
            if (numStack.size() >= 1) {
                int num1 = numStack.top();
                numStack.pop();

                int num2 = numStack.top();
                numStack.pop();

                if (postFix[i][0] == '+')
                    numStack.push(num1 + num2);
                else if (postFix[i][0] == '-')
                    numStack.push(num2 - num1);
                else if (postFix[i][0] == '*')
                    numStack.push(num1 * num2);
                else if (postFix[i][0] == '/')
                    numStack.push(float(num1) / float(num2));
            }
        }
        // std::cout << numStack.top() << std::endl;
    }
    if (numStack.empty())
        return 0;

    return numStack.top();
}

int main() {
    std::string exp = "1+2*3-9+5";

    std::cout << "Type in expression: ";
    std::cin >> exp;

    std::vector <std::string> postFix = inToPost(exp);

    for (int i = 0; i < postFix.size(); i++) {
        std::cout << postFix[i] << " ";
    }

    std::cout << std::endl;

    std::cout << Calculate(postFix) << std::endl;

    return 0;
}