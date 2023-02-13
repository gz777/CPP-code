// Tail recursive C++ program to find minimum 
  
#include <iostream> 

//This version is close to the regular recursive verion, but it takes an extra round of function call to compare the last element to itself, because it starts with size of the array.
int findMin1(int list[], int size, int min) {//min should be the value of the last element in the array.
    if(size == 1) // it's the first element when size == 1
        return min;
    else {
        if(list[size-1] < min)
            min = list[size-1];
        return findMin1(list,size-1,min);
    }
}

//This version is better, because it starts with (size-1), therefore, the last element will only compare with the next element in the array and have saved one round of comparision to itself.
int findMin2(int list[], int size, int min) {//min should be the value of the last element in the array. Thereore the initial size could be size-1, since the first element is already set to the current min value
    if(size == 0) //we pass size-1 as the initial argument. So it's the first element when size==0
        return min;
    else {
        if(list[size-1] < min)
            min = list[size-1];
        return findMin2(list,size-1,min);
    }
}


int main()
{
    const int SIZE = 4;
    int list[SIZE] = {-2,6,4,-50};
    std::cout << findMin1(list,SIZE,-50);
    std::cout << findMin2(list,SIZE,-50);

    return 0;
}
