//binary search recursive gz 4-8-21
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> list, int size, int n) {
    if(size == 0)
        return false;
    int half = size/2;
    int temp = list.at(size/2);
    if(n == temp)
        return true;
    if(n < temp) {
        vector<int> split_lo(list.begin(), list.begin() + half);
        return binarySearch(split_lo,half,n);
    } else {
        vector<int> split_high(list.begin()+half, list.end());
        return binarySearch(split_high, size - half, n);
    }
}


int main()
{
    vector<int> list = {1,2,4,5,7,8,10,14,23,33,35,41};
    int n = 8;
    
    cout << "Hello: " << binarySearch(list,12,8) << endl;
    

    return 0;
}
