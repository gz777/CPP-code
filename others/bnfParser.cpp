//Reference: https://www.youtube.com/watch?v=dDtZLm7HIJs
//3/18/22 gz mini parser. All rights reserved.
//updated: 3/25/22 gz
/*BNF
<expr> -> <term> + <expr> | <term>
<term> -> <factor> * <term> | <factor>
<factor> -> (<expr>) | int
*/
/*
Test case patterns(no space inbetween): a+b*c, a*b+c, a*(b+c), (a+b)*c, , a*b+c*d, (a+b)*(c+d). Mixed case samples: (2*(4+2))*3,(2*3+3)*2, (2*3+3)*(2+3)...
I put some print statements in the code so that you can see the parsing trail.
Note: The code only handles binary operations (can be nested), such as a+b*(c+d) , but not ternary or n-ary, such as a+b+c, a*b*c*d. 
      The code handles nested bracket case, such as (a+(a+(a+b))+c, or two single bracket pairs eg,(a+b)*(c+d), but not a mixer of the two, such as (a+b) * (a * (a+b)).   
*/
/*
The code is a prototype that it computes the value to verify the correctness of the grammer recursive flow.
Ideally, for each nontermal function, there should be SUCCESS and FAILED cases to simulate a parser.
 if()...
    return SUCCESS;
 else
    return FAILED;
*/

#include <iostream>
#include <cmath>
#include <cassert>

using std::string;
using std::cout;
using std::endl;


int expr(string);

int factor  (string s) {
    cout <<  "factor " << s << endl;
    if (s[0] == '(') {
        string ss = s.substr(1, s.size()-2);//last ele -1, ')' -1
        return expr(ss);
    } else { 
        int len = s.length(), digit = 0;
        for(int i=0;i<len;i++) {
            int v = s[len-i-1]-48;//ascii code
            assert(v >= 0 && v <= 9); // not a number. FAILED
            digit += (v * pow(10,i));
        }
        return digit; //SUCCESS
    }
}

int term (string s) {
    cout <<  "term " << s << std::endl;
    size_t found = s.find('*');
    if (found!=string::npos) {
        string x = s.substr(0,found), y = s.substr(found+1);
        int ix = factor(x), iy = term(y);
        return ix * iy;
    }
    return factor(s);
}

int expr(string s) {
    size_t foundp = s.find('+'), foundm = s.find('*'), foundb = s.find('(');
    cout <<  "expr " << s << endl;
    if (foundb != string::npos) {
        int last_close_bracket = (s.rfind('(') > s.find(')')) ?s.find(')')  : s.rfind(')');//nested (()) or single set of ()
            
        string s1 = s.substr(foundb, last_close_bracket+1); //(<expr>) 
        

        int z = factor(s1);

        size_t found = s.find(s1);
        string s2 = ( s.substr(0,found) == "")? std::to_string(z) + s.substr(last_close_bracket+1) : s.substr(0,found) + std::to_string(z);//left or right associative
 
        std::cout << "expr2: " << s2 << std::endl;
        return expr(s2);
       
    } else if (foundp != string::npos) {
        string x = s.substr(0,foundp), y = s.substr(foundp+1,s.size());
        int ix = term(x), iy = expr(y);
        return ix + iy;
    } 
    else
        return term(s);

}

int main() {

    //success cases
    //cout << factor("234");
    //cout << term("2*44");
    cout << expr("2*3+3") << "\n\n"
         << expr("(2*3+3)*(2+3)") << "\n\n"
         << expr("2*(3+(4+(1+2)))") << "\n\n"
         << expr("2*3*(4+1+2)") << "\n\n";
    
    //failed case
    cout << expr("2*3^(4+1+2)") << "\n\n"; // the grammar doesn't have knowledge how to handle '/'. FAILED case.


    return 0;
}


