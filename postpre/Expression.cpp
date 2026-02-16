#include <string>
#include <cctype> // for isalpha
#include <stdexcept>

#include "Expression.hpp"

/* Default constructor */
Expression::Expression() 
{}

/* Public member functions */
void Expression::setFromPrefix(const std::string &pre)
{
  // TODO: check format
  if(!isPre(pre)){
    return;
  }

  // TODO: store prefix and postfix forms
  prefixForm = pre;
  prefixToPostfix(pre, postfixForm);
}

void Expression::setFromPostfix(const std::string &post)
{
  // TODO: check format
  if(!isPost(post)){
    return;
  }
  // TODO: store prefix and postfix forms
  postfixForm = post;
  postfixToPrefix(post,prefixForm);
}

std::string Expression::getPrefix() const
{
    return prefixForm;
}

std::string Expression::getPostfix() const
{
    return postfixForm;
}

/* Private member functions */
void Expression::prefixToPostfix(const std::string &prefix, std::string &postfix) const {
  // from textbook section 6.3.3
  int end1, end2;
  char first_char = prefix[0];
  if(isOperator(first_char)) {
    // recursively parse expression
    end1 = endPre(prefix,1);
    end2 = endPre(prefix,end1+1);
    // operand/subexpression
    prefixToPostfix(prefix.substr(1,end1), postfix);
    // operand/subexpression
    prefixToPostfix(prefix.substr(end1+1,end2-end1), postfix);
    // operator
    postfix += first_char;
  } else {
    // operand
    postfix += first_char;
  }
}

void Expression::postfixToPrefix(const std::string &postfix, std::string &prefix) const {

  // TODO: recursive function
  int start1, start2;
  char last_char = postfix[postfix.length()-1];
  if(isOperator(last_char)){
    start1 = endPost(postfix, postfix.length()-2);
    start2 = endPost(postfix, start1-1);

    postfixToPrefix(postfix.substr(postfix.length()-1+start1,start1),prefix);
    postfixToPrefix(postfix.substr(start1-1,start2-start1),prefix);

    prefix += last_char;
  } else {
    prefix += last_char;
  }
}
