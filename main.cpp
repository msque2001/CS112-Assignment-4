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
      theString = NULL;
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

        array_size = required_array_size; // UPDATING array_size
      }

      else // TEST THIS LATER!!!!!!!!!!
      {
          for(int i = current_string_size, j = 0; i < array_size && j < other_string_size; i++, j++)
            theString[i] = other_string.theString[j];
      }
      
      
    }

    bool operator!=(const StringManip &other_string)
    {
      int index = 0;

      while((theString[index] == other_string.theString[index]) && (theString[index] != '\0' || other_string.theString[index] != '\0'))
      {
        index++;

        if(theString[index] == '\0' && other_string.theString[index] == '\0')
          return false;
      }

      return true;
    }

    bool operator<(const StringManip &other_string)
    {
      string this_temp = theString, other_string_temp = other_string.theString;
      if(this_temp < other_string_temp)
        return true;
      return false;
    }

    StringManip operator()(int start, int end)
    {
      int string_size = stringSize(theString);
      StringManip temp(string_size);
      
      for(int i = start, j = 0; i <= end && j < string_size; i++, j++)
      {
        temp.theString[j] = theString[i]; 
      }

      return temp;
    }

    StringManip operator<<(int numOfShifts) // LEFT SHIFT
    {
      StringManip temp(numOfShifts);
      
      for(int i = 0; i < numOfShifts; i++)
      {
        temp.theString[i] = theString[i];
      }
      
      int counter = 1;
      while(counter <= numOfShifts)
      {
        for(int i = 0; theString[i] != '\0'; i++)
        {
            if(theString[i + 1] == '\0')
              theString[i] = '\0';

            else
              theString[i] = theString[i + 1];
        }
        counter++;
      }

      return temp;
    }

    friend ostream &operator<<(ostream &output, const StringManip &the_string); // COUT

};

ostream &operator<<(ostream &output, const StringManip &req_string)
{
  return output << req_string.theString;
}

int main()
{
  char myArr[] = "ABCDEFG", other[] = "I am";
  string z = "msq", y = "Saaim";
  StringManip obj(myArr), x(other), another;

  return 0;
}