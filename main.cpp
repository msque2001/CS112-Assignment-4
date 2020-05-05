#include <iostream>
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
      
      for(int i = 0; i < array_size; i++)
        theString[i] = s1[i];
    }

    StringManip(int string_size)
    {
      array_size = string_size;
      theString = new char[array_size];
    }

    ~StringManip()
    {
      delete[] theString;
    }
};

int main()
{
  char myArr[] = "Saaim Qureshi";
  StringManip obj(myArr);
  return 0;
}