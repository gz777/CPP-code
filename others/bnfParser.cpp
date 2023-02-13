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

#include <iostream>
#include <cmath>

using std::string;

int expr(string);

int factor  (string s) {
     std::cout <<  "factor " << s << std::endl;
    if (s[0] == '(') {
        string ss = s.substr(1, s.size()-2);//last ele -1, ')' -1
        return expr(ss);
    } else { 
        int len = s.length(), digit = 0;
        for(int i=0;i<len;i++)
            digit += (s[len-i-1]-48) * pow(10,i);//ascii code
        return digit;
    }
}

int term (string s) {
    std::cout <<  "term " << s << std::endl;
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
    std::cout <<  "expr " << s << std::endl;
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
    
        
    return term(s);

}

int main() {

    //std::cout << factor("234");
    //std::cout << term("2*44");
    std::cout << expr("2*3+3") << "\n\n";
    std::cout << expr("(2*3+3)*(2+3)") << "\n\n";
    std::cout << expr("2*(3+(4+(1+2)))") << "\n\n";


    return 0;
}
