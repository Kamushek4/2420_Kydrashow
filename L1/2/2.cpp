#include <iostream>
using namespace std;

int main()
{
    int A = 1, B = 0, C = 1;
    cout << "A or !(A and B) or C = " << (A or !(A and B) or C) << endl;
    cout << "A or C and !(A or C) = " << (A or C and !(A or C)) << endl;
    cout << "(A or B !and! C) or A = " << ((A or B and !!C) or A) << endl;
}
