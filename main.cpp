#include <iostream>
using namespace std;

class StringManip
{
    char* theString;
    int array_size = 0;

    int stringSize(char xString[])
    {
        int string_size = 0;
        while (xString[string_size] != '\0')
            string_size++;

        return string_size;
    }

public:
    StringManip()
    {
        array_size = 50;
        theString = new char[array_size];
    }


    StringManip(char s1[])
    {
        while (s1[array_size] != '\0')
            array_size++;

        theString = new char[array_size]; // CHANGE

        for (int i = 0; i < array_size; i++)
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

    void operator+=(const StringManip& other_string)
    {
        const int current_string_size = stringSize(theString);
        const int other_string_size = stringSize(other_string.theString);
        const int required_array_size = current_string_size + other_string_size;

        if (required_array_size > array_size)
        {
            char temp[current_string_size];

            for (int i = 0; i < current_string_size; i++)
                temp[i] = theString[i];

            theString = new char[required_array_size];

            for (int i = 0; i < current_string_size; i++)
                theString[i] = temp[i];

            for (int i = current_string_size, j = 0; i < required_array_size && j < other_string_size; i++, j++)
                theString[i] = other_string.theString[j];

            array_size = required_array_size; // UPDATING array_size
        }

        else // TEST THIS LATER!!!!!!!!!!
        {
            for (int i = current_string_size, j = 0; i < array_size && j < other_string_size; i++, j++)
                theString[i] = other_string.theString[j];
        }


    }

    bool operator!=(const StringManip& other_string)
    {
        int index = 0;

        while ((theString[index] == other_string.theString[index]) && (theString[index] != '\0' || other_string.theString[index] != '\0'))
        {
            index++;

            if (theString[index] == '\0' && other_string.theString[index] == '\0')
                return false;
        }

        return true;
    }

    bool operator<(const StringManip& other_string)
    {
        string this_temp = theString, other_string_temp = other_string.theString;
        if (this_temp < other_string_temp)
            return true;
        return false;
    }

    StringManip operator()(int start, int end)
    {
        int string_size = stringSize(theString);
        StringManip temp(string_size);

        for (int i = start, j = 0; i <= end && j < string_size; i++, j++)
        {
            temp.theString[j] = theString[i];
        }

        return temp;
    }

    StringManip operator<<(int numOfShifts) // LEFT SHIFT
    {
        StringManip temp(numOfShifts);

        for (int i = 0; i < numOfShifts; i++)
        {
            temp.theString[i] = theString[i];
        }

        int counter = 1;
        while (counter <= numOfShifts)
        {
            for (int i = 0; theString[i] != '\0'; i++)
            {
                if (theString[i + 1] == '\0')
                    theString[i] = '\0';

                else
                    theString[i] = theString[i + 1];
            }
            counter++;
        }

        return temp;
    }
    void printArray()
    {
        cout << endl;
        for (int i = 0;i < array_size;i++)
        {

            cout << theString[i];

        }

    }
    int getsize_of_Array()
    {


        return array_size;

    }

    StringManip operator+(StringManip& S)
    {
        StringManip temp(array_size + S.array_size);

        for (int i = 0;i < array_size;i++)
        {

            temp.theString[i] = theString[i];

        }
        for (int j = array_size, i = 0;j < array_size + S.array_size;j++, i++)
        {

            temp.theString[j] = S.theString[i];

        }


        return temp;
    }


    char &operator[](int position)
    {
        return theString[position];
    }

    bool operator== (StringManip& S)
    {



        if (array_size == S.array_size)
        {
            int equality_found = 0;
            for (int i = 0; i < array_size; i++)
            {
                if (theString[i] == S.theString[i])
                {
                    equality_found++;
                    if (equality_found == array_size)
                    {
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }

        }


        else
        {
            return false;
        }
    }

    bool operator>(const StringManip& other_string)
    {
        string this_temp = theString, other_string_temp = other_string.theString;

        if (this_temp > other_string_temp)
        {
            return true;
        }

        return false;
    }



    StringManip operator>>(int x) // RIGHT SHIFT
    {
        StringManip temp(x);
        int c = 0;
        for (int i = 0;i < x;i++)
        {
            temp.theString[c] = theString[array_size - 1 - i];
            c++;
        }

        array_size = array_size - x;
        return temp;
    }

    friend ostream& operator<<(ostream& output, const StringManip& the_string); // COUT
    friend istream& operator>> (istream& input, const StringManip& input_string);// CIN
};

ostream& operator<<(ostream& output, const StringManip& req_string)
{
    return output << req_string.theString;
}
istream& operator>>(istream& input, const StringManip& input_string)
{

/*
    for (int i = 0;i < input_string.array_size;i++)
    {
        input >> input_string.theString[i];
    } */

    input >> input_string.theString;

    return input;

}
int main()
{
    char myArr[] = "ABCDEFG", other[] = "I am";
    string z = "msq", y = "Saaim";
    StringManip obj(myArr), x(other), another;

    another = obj >> 1;

    cout << "obj: " << obj << endl;
    cout << "another: " << another << endl;

    another = obj >> 3;
    cout << "obj: " << obj << endl;
    cout << "another: " << another << endl;


    return 0;
}
