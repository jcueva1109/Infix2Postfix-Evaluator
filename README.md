# Infix to Postfix Evaluator
## Author: Jesus Cueva

This project was carried out in C ++ with the purpose of being presented in the Programming Languages class that I course.

It is a console program that takes as input an arithmetic expression in infix form and the algorithm converts this input to a postfix expression, for its evaluation. To carry out this conversion, several rules are taken into account, PEMDAS. Having our postfixed expression proceeds to evaluate. We go through the result obtained and when an operator such as ('+', '-', '*', '/', '%', '^') is found, the two digits before this operator are taken and the operation dictated by the current operator. This result is stored in the same position as the operator and the evaluation continues until the entire postfix expression has been passed. Finally, this result is displayed on the screen.

The program uses the TDD methodology, Test Driven Development, when using test cases for its validation.

Finally, features from C ++ 11, C ++ 14, C ++ 17 were used, with a total of 4 features per version with a total of 12 features among all.
