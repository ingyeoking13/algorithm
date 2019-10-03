//Do NOT MODIFY THIS FILE.

#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include "LinkedBinaryTree.h"
#include "Symbol.h"
#include "PJT2.h"

using namespace std;

void printMenu() {
  cout << "Please select one of the following option:" << endl;
  cout << " a) Enter a new expression in postfix notation." << endl;
  cout << " b) Print the expression in infix notation." << endl;
  cout << " c) Print the expression in postfix notation." << endl;
  cout << " d) Print the expression in prefix notation." << endl;
  cout << " e) Find the size of the tree." << endl;
  cout << " f) Find the height of the tree." << endl;
  cout << " g) Find the minimum depth of a variable." << endl;
  cout << " h) Substitute a variable with a constant." << endl;
  cout << " i) Simplify tree by evaluating subtrees with constants only." << endl;
  cout << " j) Delete the tree and free the memory." << endl;
  cout << " z) Quit this program." << endl;
}


int main(int argc, char *argv[]) {

  bool isVerbose = true;

  // the -q option turns off some outputs to help grading

  if (argc==2) {
    if (strcmp(argv[1], "-q")==0) {
      isVerbose = false;
    }
  }

  try {

    LinkedBinaryTree<Symbol> tree;  // initially, it is an empty tree

    bool isExit = false;

    while (!isExit) {  // loop until the user choose to quit

      if (isVerbose) printMenu();

      if (isVerbose) cout << "Your choice: ";
      char choice;
      cin >> choice;
      if (isVerbose) cout << endl;

      switch(choice) {
        case 'a':  // enter the expression in postfix notation
          if (tree.empty()) {
            if (isVerbose) cout << "Please enter an expression terminated with '#': ";
            try {
              // read a sequence of tokens until the user enters '#'
              list<string> tokens;
              while(true) {
                string s;
                cin >> s;
                if (s == "#") break;
                tokens.push_back(s);
              }
              // parse the sequence of tokens into an expression tree
              tree = parsePostfixExpression(tokens);
            } catch (const runtime_error &e) {
              // The error message should be printed to cerr,
              // but for grading purpose, we print it to cout.
              cout << "Error: " << e.what() << endl;
            }
          } else {
            cout << "The tree is not empty. Delete it before creating a new one." << endl;
          }
          break;
        case 'b':  // print the expression in infix notation
          if (tree.empty()) {
            cout << "The tree is empty." << endl;
          } else {
            print_inorder(tree);
            cout << endl;
          }
          break;
        case 'c':  // print the expression in postfix notation
          if (tree.empty()) {
            cout << "The tree is empty." << endl;
          } else {
            print_postorder(tree);
            cout << endl;
          }
          break;
        case 'd':  // print the expression in prefix notation
          if (tree.empty()) {
            cout << "The tree is empty." << endl;
          } else {
            // tree.positions() orders nodes in prefix order.
            LinkedBinaryTree<Symbol>::PositionList pl = tree.positions();
            for(list<LinkedBinaryTree<Symbol>::Position>::const_iterator pos_iter = pl.begin();
                pos_iter != pl.end();
                ++pos_iter)
            {
              cout << **pos_iter << " ";
            }
            cout << endl;
          }
          break;
        case 'e':
          cout << "The size of the tree is " << tree.size() << "." << endl;
          break;
        case 'f':
          if (tree.empty()) {
            cout << "There is no height because the tree is empty." << endl;
          } else {
            cout << "The height of the tree is " << tree.height() << "." << endl;
          }
          break;
        case 'g': {
          if (tree.empty()) {
            cout << "The tree is empty." << endl;
          } else {
            if (isVerbose) cout << "Please enter a variable: ";
            string str;
            cin >> str;
            Symbol variable(str);
            if (variable.getSymbolType() == Symbol::variable) {

              int d = findMinimumDepth(tree, variable);  // if d < 0, it means the variable is not in the tree.

              if (d >= 0) {
                cout << "The minimum depth of " << variable << " is " << d << "." << endl;
              } else {
                cout << "Cannot find " << variable << "." << endl;
              }
            } else {
              cout << "Error: " << variable << " is not a variable." << endl;
            }
          }
          break;
        }
        case 'h':
          if (tree.empty()) {
            cout << "The tree is empty." << endl;
          } else {
            string str;
            if (isVerbose) cout << "Please enter a variable: ";
            cin >> str;
            Symbol variable(str);
            if (variable.getSymbolType() != Symbol::variable) {
              cout << "Error: " << variable << " is not a variable." << endl;
            } else {
              if (isVerbose) cout << "Please enter a constant: ";
              cin >> str;
              Symbol constant(str);
              if (constant.getSymbolType() != Symbol::constant) {
                cout << "Error: " << constant << " is not a constant." << endl;
              } else {
                substitute(tree, variable, constant);  // substitute variable for constant
              }
            }
          }
          break;
        case 'i':
          try {
            simplify_subtree(tree);   // this function may throw runtime_error("Divide by zero")
          } catch (const runtime_error &e) {
            // The error message should be printed to cerr,
            // but for grading purpose, we print it to cout.
            cout << "Error: " << e.what() << endl;
          }
          break;
        case 'j':
          if (tree.empty()) {
            cout << "The tree is already empty." << endl;
          } else {
            tree.removeSubtree(tree.root());
            cout << "The tree has been removed." << endl;
          }
          break;
        case 'z':  // Exit the program
          if (isVerbose) cout << "Bye!" << endl;
          isExit = true;
          break;
        default:
          cout << "Error: Unknown option." << endl;
      }
      if (isVerbose) cout << endl;
    }

    // clean up the space
    if (!tree.empty()) {
      tree.removeSubtree(tree.root());
    }

    return 0;

  } catch(const exception& e) {
    // The error message should be printed to cerr,
    // but for grading purpose, we print it to cout.
    cout << "Error: " << e.what() << endl;
  }
}

