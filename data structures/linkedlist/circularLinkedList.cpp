// Circular linked list demo code
// 10-5-21 gz
// All rights reserved
//https://onlinegdb.com/bQaNCz3JI

#include <iostream>
#include <stdlib.h>
#include<time.h>

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
    if (wheel != nullptr) {
        for(int i=0;i<size;i++) {
        std::cout << temp->fortune <<"->";
        temp = temp->next;
        }
        std::cout << "BACK to BEGINNING\n";
    }
    return temp;
    
}

void spin(Fortune * &wheel, int size)  {
    int aNum = rand()%10;
    std::cout <<"Spin: " <<aNum <<" Turning "<<aNum/size<<" rounds; " << aNum%size << " position\n";
    wheel = displayFortunes(wheel,aNum);//aNum%size for efficiency
}

int main()
{
    srand(time(0));
    int SIZE = 4;
    Fortune * wheel = nullptr;
    std::string fortunes[SIZE] = {"1 good luck","2 getting richer","3 high marks","4 a nice day"};
    constructFortuneWheel(wheel, fortunes, SIZE);
    //displayFortunes(wheel,SIZE);
    spin(wheel,SIZE);
    displayFortunes(wheel,SIZE);
    deallocateFortunes(wheel,SIZE);
    return 0;
}
