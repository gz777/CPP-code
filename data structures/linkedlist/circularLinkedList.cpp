// Circular linked list demo code
// 10-5-21 gz
// All rights reserved
// https://onlinegdb.com/1i4DWPKrd

/*
Fortune of Wheel Project description:
You can use either Procedural or OOP approach. However, you will need to design and defined your node structure object. You will have to use C++ to implement your design for this assignment.
You will design and implement a game application using Circular Linked List.
1. The fortunes can be monetary (numbers) or some good luck phrases, or any other
sequences as you see fit.
2. You will have to implement the program using CIRCULAR LINKED LIST (CLL).
3. Interface design can be primitive or creative.
Basic operations:
The wheel pointer (head pointer) starts at a default position (node) of the Circular
Linked List.
spin(): Depending on how many slots you have in your wheel of fortune, the spin should
not exceed three turns of the wheel.
For example, if you have 6 slots in the Wheel, allow the random number generator
method to generate any integer number between 1 ~ 6×3, [1,18] in this case.
When the wheel stops, the Wheel arrow should point at the (rand()%6)th slot. For
example, if the random number is 10, it means the wheel is turned 1 circle (6 slots) plus
4 slots positions, in other word, the wheel arrow points at the 4th slot position from the slot the arrow initially points at. Your next spin() should start from this 4th slot position
or rather, the head pointer of CLL should point at this 4th node upon the spin completes.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


struct Fortune {
    std::string fortune = "";
    Fortune * next = nullptr;
    Fortune(std::string f):fortune(f){}
};

void constructFortuneWheel(Fortune * &wheel, std::string fortunes[], int size) {
    wheel = new Fortune(fortunes[0]);
    Fortune * temp = wheel;
    for(int i=1;i<size;i++){
        temp->next = new Fortune(fortunes[i]);
        temp = temp->next;
    }
    temp->next = wheel;//circular
}

void deallocateFortunes(Fortune *& wheel, int size) {
    Fortune * temp = wheel;
    for(int i=0;i<size;i++) {
        wheel = wheel->next;
        delete temp;
        temp = wheel;
    }
    wheel = nullptr;
}



Fortune* displayFortunes(Fortune * wheel, int size) {
    Fortune * temp = wheel;
    if (temp != nullptr) {
        for(int i=0;i<size-1;i++) { //note size-1, otherwise head points to the next item
            std::cout << temp->fortune <<"->";
            std::cout.flush();
            sleep(1);
            temp = temp->next;
        }
        std::cout << "BACK to BEGINNING\n";
    }
    return temp;

}

void spin(Fortune * &wheel, int size, int aNum)  {
    //std::cout <<"Spin#: " <<aNum <<". Turning "<<aNum/size<<" rounds; " << aNum%size << " position\n";
    wheel = displayFortunes(wheel,aNum);
    std::cout <<"\033[32mYour fortune is: \033[31;44m***" << wheel->fortune << "***\033[0m\n";//linux OS color, red on blue
}

int main()
{
    srand(time(0));
    const int SIZE = 7; //a wheel is devided by SIZE.
    Fortune * wheel = nullptr;
    std::string fortunes[SIZE] = {"1 good luck","2 getting richer","3 high marks","4 a nice day","5 abandence", "6 happiness", "7 wisdom"};
    constructFortuneWheel(wheel, fortunes, SIZE);

    char again = 'y';
    while(again == 'y') {
        int randombase = SIZE + rand()%12; //simulate spin#
        spin(wheel,SIZE,randombase);
        printf("spin again,y|n? "); std::cin >> again; //scanf doesn't do char type properly
    }

    printf ( "Thank you for playing!\n");
    deallocateFortunes(wheel,SIZE);
    return 0;
}
