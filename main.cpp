#include <iostream>
#include<string>
using namespace std;

class StringManip
{
  char *theString;
  int array_size = 0;
  public:
    StringManip()
      {
          theString = new char[50];
      }

      StringManip(char s1[])
      {
        while(s1[array_size] != '\0')
            array_size++;

        theString = new char[array_size];
        theString = s1;
      }

      StringManip(int string_size)
      {
          array_size = string_size;
          theString = new char[array_size];
      }

    ~StringManip()
    {
       delete this;
    }
};

int main()
{
    char myArr[] = "Saaim";
    StringManip obj(myArr);
    return 0;
}