#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include "ReversePolishNotation.h"
#include "ExpressionTree.h"
#include "CalcExpressionByTree.h"

//////////////////////////////////////////////////
void test(void);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    char *expression = "(1+2*3)/(~4+5*6)";
    printf("Expression              : %s\n", expression);
    
    // check Reverse Polish Notation.
    char *rpn = convertToRPN(expression, "");
    printf("Reverse Polish Notation : %s\n", rpn);
    free(rpn);
    
    BTN_t *root = createExpressionTree(expression);
    printf("Expression Tree         :\n");
    viewExpressionTree(root);
    
    double ans = calcExpressionByTree(root);
    printf("Answer                  : %-36.15lf\n", ans);
    
    destroyExpressionTree(root);
}
