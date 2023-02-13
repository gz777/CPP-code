#include <iostream>

using namespace std;

int main()
{

    int i=0;
    int array[3][2];
    for ( auto &a : array )
    {
        for ( int &x : a ) {
            x = i++;
            cout << x << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++)
            cout << array[i][j] << " ";
        cout << endl;
    }

    return 0;
}
