/*BCS230 11/6/18 static member*/

#include <iostream>
#include <string>
using namespace std;

class Runner {
    private:
       string name;
       static int counter;//how many runners
    public:
        Runner(string name){this->name = name; counter++;}
        string getName(){return name;}
        static int getCounter(){return counter;}
};
//static variable should be initialized outside class
int Runner::counter = 0;

int main()
{
   Runner runner1("Ben Jonson");
   Runner runner2("Mary Berry");
   
   Runner runners[3] = {Runner("Name1"), Runner("Name2"),Runner("Name3")};
   
   cout << runner1.getName() << " " << runner1.getCounter() << endl;
   cout << runner2.getName() << " " << runner2.getCounter() << endl;
   cout << runners[0].getName() << " " << runners[0].getCounter() << endl;
   
   cout << Runner::getCounter() << endl;
   

    return 0;
}