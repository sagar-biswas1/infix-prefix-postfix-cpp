

#include<bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;


int precedenceCalc(char c)
{
    if(c=='+'|| c=='-' )
    {
        return 1;
    }

    if(c=='/'|| c=='*' )
    {
        return 2;
    }

    if(c=='^' )
    {
        return 3;
    }
    return -1;
}



string infixToPrefix( string str)
{
    Stack <char> st;
    reverse(str.begin(), str.end());

    string result;
    for(int i= 0 ; i< str.length() ; i++  )
    {

        if(str[i]>='0' && str[i]<='9' )
        {
            result+= str[i];
        }
        else if(str[i]== ')' )
        {
            st.push(str[i]);
        }
        else if( str[i]== '(')
        {
            while(!st.empty() && st.Top()!= ')')
            {
                result+= st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }

        }
        else
        {
            while(!st.empty() && precedenceCalc(st.Top())>= precedenceCalc(str[i]) )
            {
                result+= str[i];
            }
            st.push(str[i]);


        }

    }

    while(!st.empty() )
    {
        result+= st.pop();
    }
      reverse(result.begin(), result.end());
      return result;
}



int prefixEvaluation(string str)
{

    Stack <int> s;

    for(int i=str.length()-1 ; i>=0 ; i--)
    {

        if(str[i]>='0' && str[i]<='9')// str[i] -> 0-9
        {
            s.push(str[i]-'0');

        }
        else  //str[i] ->operator
        {
            int a= s.pop();
            int b=s.pop();

            switch(str[i])
            {
            case '+':
                s.push(a+b);
                break;
            case '-':
                s.push(a-b);
                break;
            case '*':
                s.push(a*b);
                break;
            case '/':
                s.push(a/b);
                break;
            case '^':
                s.push(pow(a,b));
                break;

            default:
                break;

            }
        }

    }
return s.Top();
}

int main()
{

cout << prefixEvaluation(infixToPrefix("(7+(4*5))-(2+0)"));
    return 0;
}



/* steps;

1. reverse the string.
2. if 0-9 print.
3. if ) ,push to the stack.
4. if ( , pop until ")" is found.
5. suppose precedence value [-,+]->1 , [*,/]->2 ,[^]->3 , [others]->-1.
6. if we get any operator , it will start to pop form the stack until it finds any with less or equal precedence.
            ^               it will push in the stack if it finds any with less precedence.
7. pop till the end

8. reverse again

*/


