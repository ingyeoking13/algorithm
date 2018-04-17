//Do NOT MODIFY THIS FILE.


#ifndef PJT2_PJT2_H
#define PJT2_PJT2_H

#include <iostream>
#include <list>
#include "LinkedBinaryTree.h"
#include "Symbol.h"

/*
 * Take an expression in postfix notation and paste it into an expression tree.
 *
 * tokens - the list of symbols in the expression
 * return an expression tree
 */
LinkedBinaryTree<Symbol> parsePostfixExpression(list<string> tokens);

/*
 * Print the expression in infix notation
 *
 * tree - an expression tree
 */
void print_inorder(const LinkedBinaryTree<Symbol>& tree);

/*
 * Print all symbols on an expression tree by postorder traversal.
 *
 * tree - an expression tree
 */
void print_postorder(const LinkedBinaryTree<Symbol>& tree);

/*
 * Among all nodes that contains the symbol of a given variable in an expression tree,
 * return the minimum depth of these nodes.
 *
 * tree - an expression tree
 * sym - the symbol of a variable
 * return the minimum depth of a variable; -1 if the variable does not appear in the expression tree.
 */
int findMinimumDepth(const LinkedBinaryTree<Symbol>& tree, const Symbol& sym);

/*
 * Replace all symbols of a given variable in an expression tree with a given constant.
 *
 * tree - an expression tree
 * variable - the symbol of a variable
 * constant - the symbol of a constant
 */
void substitute(const LinkedBinaryTree<Symbol>& tree, const Symbol& variable, const Symbol& constant);

/*
 * Find all subtrees whose external nodes are all constants (i.e., no variables).
 * Evaluate the subtrees and replace the subtrees with the result of the evaluation.
 * Notice that you need to free the memory of the deleted subtrees.
 *
 * tree - an expression tree
 */
void simplify_subtree(LinkedBinaryTree<Symbol>& tree);


#endif //PJT2_PJT2_H
