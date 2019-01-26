/*这道题难度：Hard
  这道题主要是我对于如何使用栈去运行计算还不太熟悉。看了解析后，现在来分析一下。
  在正常情况没有括号的情况下，不需要使用栈，而一旦有了括号。就将之前的计算结果以及括号之前的运算符号放入栈中。本来我最开始也是这么想的，可是关于符号这一点，一直没想清楚该怎么解决，这个答案在这一步就非常的清晰，使用-1和1去替代，然后直接与数字相乘用于计算。有前括号就将之前的运算结果放置栈中，然后将res置0，计算括号中的计算内容。当遇到后括号时，把之前存储的结果取出来进行运算。做这类题时，我思路还是不太清晰，老纠结于前括号后括号以及加减符号，毫无必要。只要在有括号的时候才使用栈，然后将括号中的内容正常运算，括号外的放入栈中。*/

#include <iostream>
#include <stack>
class Solution {
public:
    int calculate(string s) {
        stack<int> ops,nums;
        int num=0, sign=1, res=0;
        for(auto c: s){
            if(isdigit(c)){
                num=num*10+c-'0';
            }
            else{
                res+=num*sign;
                num=0;
                if(c=='-') sign=-1;
                else if(c=='+') sign=1;
                else if(c=='('){
                    nums.push(res);
                    ops.push(sign);
                    res=0;
                    sign=1;
                }
                else if(c==')'){
                    res=res*ops.top()+nums.top();
                    nums.pop(); ops.pop();
                }
            }
        }
        res=res+num*sign;
        return res;
    }
};



