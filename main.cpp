#include <iostream>
using namespace std;

class StringManip
{
    public:
        ~StringManip()
        {
            cout << "Destructor Called!";
        }
        
};

int main()
{
    StringManip obj1;

    return 0;
}