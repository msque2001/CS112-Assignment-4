#include <iostream>
using namespace std;

class StringManip
{
  char *theString;
  int array_size = 0;

  int stringSize(char xString[])
  {
    int string_size = 0;
    while(xString[string_size] != '\0')
      string_size++;
    
    return string_size;
  }

  public:
    StringManip()
      {
        theString = new char[50];
      }

    StringManip(char s1[])
    {
      while(s1[array_size] != '\0')
        array_size++;

      theString = new char[array_size]; // CHANGE
      
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

    int getStringSize()
    {
      int string_size = stringSize(theString);
      return string_size;
    }

    void operator+=(const StringManip &other_string)
    {
      const int current_string_size = stringSize(theString);
      const int other_string_size = stringSize(other_string.theString);
      const int required_array_size = current_string_size + other_string_size;

      if(required_array_size > array_size)
      {
        char temp[current_string_size];
        
        for(int i = 0; i < current_string_size; i++)
          temp[i] = theString[i];

        theString = new char[required_array_size];

        for(int i = 0; i < current_string_size; i++)
          theString[i] = temp[i];

        for(int i = current_string_size, j = 0; i < required_array_size && j < other_string_size; i++, j++)
          theString[i] = other_string.theString[j];
      }

      else // TEST THIS LATER!!!!!!!!!!
      {
          for(int i = current_string_size, j = 0; i < array_size && j < other_string_size; i++, j++)
            theString[i] = other_string.theString[j];
      }
      
      
    }
};

int main()
{
  char myArr[] = "Saaim", other[] = " Qureshi";
  StringManip obj(myArr), x(other);

  return 0;
}