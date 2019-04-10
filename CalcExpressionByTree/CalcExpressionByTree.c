#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "CalcExpressionByTree.h"
#include "ReversePolishNotation.h"
#include "ExpressionTree.h"

//////////////////////////////////////////////////
double calcExpressionByTree(BTN_t *root) {
    if (root == NULL) return 0.0;
    
    // post-order traversal.
    double ansOfLeft = calcExpressionByTree(root->left);
    double ansOfRight = calcExpressionByTree(root->right);
    
    if (strcmp(root->element, OPERATOR_ADD) == 0) {
        return ansOfLeft + ansOfRight;
    }
    else if (strcmp(root->element, OPERATOR_SUBTRACT) == 0) {
        return ansOfLeft - ansOfRight;
    }
    else if (strcmp(root->element, OPERATOR_MULTIPLY) == 0) {
        return ansOfLeft * ansOfRight;
    }
    else if (strcmp(root->element, OPERATOR_DIVIDE) == 0) {
        return ansOfLeft / ansOfRight;
    }
    else if (strcmp(root->element, OPERATOR_MINUS) == 0) {
        return -1.0 * ansOfRight;
    }
    else if (strcmp(root->element, OPERATOR_POWER) == 0) {
        return pow(ansOfLeft, ansOfRight);
    }
    else if (strcmp(root->element, OPERATOR_EQUAL) == 0) {
        return ansOfRight;
    }
    else {
        return strtod(root->element, NULL);
    }
}
