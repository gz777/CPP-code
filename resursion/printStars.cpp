/*
gz 10/31/21
sample sol to Bcs 370 lab
https://onlinegdb.com/2nfxLLmiD
*/
#include <iostream>


void printStar(int n, char c) {
    if(n>0) {
      printStar(n-1,c);
      //printf("%s\n",std::string(n,c).c_str());
      std::cout << std::string(n,c) << std::endl;
    }
}

std::string printStar2(int n, char c) {
    if(n>0) {
        std::string s = printStar2(n-1,c) + c;
        std::cout<< s << std::endl;
        return s;
    }
    else
    {
        return "";
    }
}

int main()
{
    printStar(4,'*');
    printStar2(4,'*');

    return 0;
}
