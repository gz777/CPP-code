//pass by reference

#include <iostream>
using namespace std;

int getAvg(int&, int&);


int main(){
        int average, score1 = 90, score2 = 95;
        cout << "Before Score 1: " << score1 << ". Score 2: " << score2 << endl;
        cout << "score1 mem address: " << &score1 << ". Score2 mem address: " << &score2 << endl;
        average = getAvg( score1, score2  );
        cout << " Average is: " << average << endl;
        cout << "After Score 1: " << score1 << ". Score 2: " << score2 << endl;
        return 0;
}

int getAvg(int &s1, int &s2) {
        cout << "s1 mem address: " << &s1 << ". S2 mem address: " << &s2 << endl;
        s1 *= (1+0.05); //s1 = s1 + s1 * 0.05;
		s2 *= (1 + 0.05);
        cout << " s1 is: " << s1 << ". s2 is: " << s2 << endl;
		return (s1+s2)/2;
}

