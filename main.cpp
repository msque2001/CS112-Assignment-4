#include <iostream>
#include<string>
using namespace std;

class StringManip
{
  char* array[50];
  int size = 0;
  string s = " ";
  public:
      StringManip()
      {
          size = 50;

      }
      StringManip(string s1)
      {
          s = s1;

      }
      StringManip(int a)
      {
          size = a;
          char* arr = new char[size];

      }
        ~StringManip()
        {
            cout << "Destructor Called!";
        }
};

int main()
{
    int a = 0;
    string  s1;
    StringManip obj1;


    cout << "\nEnter string:    ";
    getline(cin, s1);
    StringManip obj2(string s1);


    cout << "\nEnter array size:     ";
    cin.ignore();
    StringManip obj3(int a);

    return 0;
}