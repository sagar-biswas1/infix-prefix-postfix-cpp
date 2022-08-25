
#include<bits/stdc++.h>
#include "MYSTACK.h"



using namespace std;




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
cout<<prefixEvaluation("+*432");
    return 0;
}
