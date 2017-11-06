#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


int in_stack(DynArr * s,char tofind){
  /*
     Returns 1 if the element `tofind` is present in DynArr `s`, 0
     otherwise.  Upon returning `s` should have its elements in the
     same order as when the function is called. In other words, you
     may modify `s` but must return it to its original state

     You may only call the following funcitons

        DynArr *createDynArr(int cap);
        int isEmptyDynArr(DynArr *v);
        void pushDynArr(DynArr *v, TYPE val);
        TYPE topDynArr(DynArr *v);
        void popDynArr(DynArr *v);

     Hint: use another stack to hold elements while you search
     and then restore the initial state of `s`
  */
  	int i;
	int n=10;
	DynArr* new_stack = createDynArr(n);
	TYPE top = topDynArr(s);
	
	for(i=1;i<n;i++){
		if (top == tofind){
			pushDynArr(new_stack, top);
			return 1;
		} else { 
			return 0;
			popDynArr(s);
			isEmptyDynArr(s);
			
		}
	}	

}

int valid_bracket(char * str){
  /*
    str contains only bracking characters - parenthesis ( '(' and ')'
    ), square brackets ('[' and ']') and squiggly brackets ('{' and
    '}')

    This function returns 1 if str contains a set of balanced
    bracketing characters and zero otherwise.  A string is said to
    have balanced bracketing characters if each opening bracket ( '(',
    '{' and '[') contains a correspodning closing bracket
    (')','}',']') of the same type and brackets are closed in the
    reverse order that they are opened.

    For example

    valid_bracket("{}[]()") returns 1
    valid_bracket("{][}(]") returns 0, the brackets do not match
    valid_bracket("(([]))") returns 1
    valid_bracket("(([)])") returns 0,
          because the '(' at index 1 is closed by the ')' at index 3
	  before the '[' at index 2 is closed

    valid_bracket("}") returns 0 because there is no opening bracket for '{'

    valid_bracket("({}[])") returns 1
    valid_bracket("({}([]))") returns 1
    valid_bracket("({}([]){([])})") returns 1
    valid_bracket("({([]))") returns 0

  */
  
  	int i=0;
  	int n=100;
  	DynArr * new_bracket=createDynArr(n);
  
  	
  	while (str[i])
  	{
  		/*Check if str[i] is a starting parenthesis then push it*/
  		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
  		pushDynArr(new_bracket, str[i]);
  		
  		/*Check if the next string is the ending of parahthesis and match it before pop it*/
  		if (str[i+1] == '}' || str[i+1] == ')' || str[i+1] == ']')
  		{
  			/*Check if nothing left on the stack or the paranthesis doesn't have any ending*/
  			if (str[i+1] == NULL){
  				return 0;
  				
  			/*Return 1 if the paranthesis have an ending and match each other*/
  				
  			} else if (str[i] == '(' && str[i+1] == ')') {
  				return 1;
  			} else if (str[i] == '[' && str[i+1] == ']') {
  				return 1;
  			} else if (str[i] == '{' && str[i+1] == '}'){
  				return 1;
  			} else {
  				return 0; 
  			}
  			//topDynArr(new_bracket);
  			//popDynArr(new_bracket);
  	
  		}
  		i++;
  	}	
  	
  	
  	if (new_bracket == NULL)
  		return 1;
  	else
  		return 0;
	
}
