//pointer arithmatic example

#include <iostream>
 
int main()
{
    const int arrayLength = 11;
    char name[] = "Holy Mollie";
    int numVowels(0);
    for (char *ptr = name; ptr < name + arrayLength; ++ptr)
    {
        switch (*ptr)
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                ++numVowels;
        }
    }
 
    std::cout << name << " has " << numVowels << " vowels.\n";
 
    return 0;
}
