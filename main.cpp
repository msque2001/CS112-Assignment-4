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
            char *temp = new char[current_string_size];

            for (int i = 0; i < current_string_size; i++)
                temp[i] = theString[i];

            theString = new char[required_array_size];

            for (int i = 0; i < current_string_size; i++)
                theString[i] = temp[i];

            for (int i = current_string_size, j = 0; i < required_array_size && j < other_string_size; i++, j++)
                theString[i] = other_string.theString[j];

            array_size = required_array_size; // UPDATING array_size
            delete[] temp;
        }

        else
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

        for (int i = 0; i < array_size; i++)
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
        for (int i = 0; i < x;i++)
        {
            temp.theString[c] = theString[array_size - 1 - i];
            c++;
        }


        for (int i = 0; i < x; i++)
        {
            theString[array_size - 1 - i] = '\0';
        }


        array_size = array_size - x;
        return temp;
    }

    friend ostream& operator<<(ostream& output, const StringManip& the_string); // COUT
    friend istream& operator>> (istream& input, const StringManip& input_string);// CIN
};

ostream& operator<<(ostream& output, const StringManip& req_string)
{
    // return output << req_string.theString;
    for(int i = 0; req_string.theString[i] != '\0'; i++)
    {
        output << req_string.theString[i];
    }
    return output;
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
    /*
    // TEST HERE
    char temp[] = "ABCDEFG";
    StringManip string_two(temp), string_three;

    string_three = string_two >> 1;

    cout << "string_two: " << string_two << endl;
    cout << "string_three: " << string_three << endl;

    string_three = string_two >> 3;
    cout << "string_two: "<< string_two << endl;
    cout << "string_three: " << string_three << endl; */



    char array_one[] = "HELLO", array_two[] = "MAN123";
    StringManip string_one(array_one), string_two(20), string_three, string_four;

    // GET ARRAY_SIZE
    cout << "array_size of string_one: " << string_one.getsize_of_Array() << endl;
    cout << "array_size of string_two: " << string_two.getsize_of_Array() << endl;
    cout << "array_size of string_three: " << string_three.getsize_of_Array() << endl << endl;

    // CIN (>>)
    cout << "Enter string with >> for string_two: ";
    cin >> string_two, cout << endl;
    cout << "string_two: " << string_two << endl << endl;

    cout << "Enter string with >> for string_three: ";
    cin >> string_three, cout << endl;
    cout << "string_three: " << string_three << endl << endl;

    // COUT (<<) AND GET STRING_SIZE
    cout << "value output using << of string_one: " << string_one << '\t';
    cout << "string_size of string_one: " << string_one.getStringSize() << endl;

    cout << "value output using << of string_two: " << string_two << '\t';
    cout << "string_size of string_two: " << string_two.getStringSize() << endl;

    cout << "value output using << of string_three: " << string_three << '\t';
    cout << "string_size of string_three: " << string_three.getStringSize() << endl << endl;

    // OVERLOADED OPERATOR (+)
    cout << "string_one before string_four = string_one + string_three: " << string_one << endl;
    cout << "string_three before string_four = string_one + string_three: " << string_three << endl;
    cout << "string_four before string_four = string_one + string_three: " << string_four << endl;
    string_four = string_one + string_three;
    cout << "string_one after string_four = string_one + string_three: " << string_one << endl;
    cout << "string_three after string_four = string_one + string_three: " << string_three << endl;
    cout << "string_four before string_four = string_one + string_three: " << string_four << endl << endl;

    // OVERLOADED OPERATOR (+=)
    cout << "string_one before string_one += string_three: " << string_one << endl;
    cout << "string_three before string_one += string_three: " << string_three << endl;
    string_one+=string_three;
    cout << "string_one after string_one += string_three: " << string_one << endl;
    cout << "string_three after string_one += string_three: " << string_three << endl << endl;

    // OVERLOADED OPERATOR ([])
    char d = string_one[3];
    cout << "After d = string_one[4]";
    cout << "string_one = " << string_one << '\t' << "d = " << d << " after" << endl;
    string_one[0] = 'J';
    cout << "After string_one[0] = 'J'\n";
    cout << "string_one = " << string_one << endl << endl;

    // OVERLOADED OPERATOR (==)
    cout << "string_three: " << string_three << '\t';
    cout << "string_two: " << string_two << endl;
    if(string_one == string_two)
        cout << "string_one == string_two: '" << string_one << "' is equal to '" << string_two << "'\n" << endl;
    else
        cout << "string_one == string_two: '" << string_one << "' is not equal to '" << string_two << "'\n" << endl;
   
   // OVERLOADED OPERATOR (!=)
    cout << "string_one: " << string_one << '\t';
    cout << "string_two: " << string_two << endl;
    if(string_one != string_two)
        cout << "string_one != string_two: '" << string_one << "' is not equal to '" << string_two << "'\n" << endl;
    else
        cout << "string_one != string_two: '" << string_one << "' is equal to '" << string_two << "'\n" << endl;
    

    // OVERLOADED OPERATOR (>)
    cout << "string_two: " << string_two << '\t';
    cout << "string_three: " << string_three << endl;
    if(string_two > string_three)
        cout << "string_two > string_three: '" << string_two << "' is greater than '" << string_three << "'\n" << endl;
    else
        cout << "string_two > string_three: '" << string_two << "' is NOT greater than '" << string_three << "'\n" << endl;


    // OVERLOADED OPERATOR (<)
    cout << "string_two: " << string_two << '\t';
    cout << "string_three: " << string_three << endl;
    if(string_two < string_three)
        cout << "string_two < string_three: '" << string_two << "' is less than '" << string_three << "'\n" << endl;
    else
        cout << "string_two < string_three: '" << string_two << "' is NOT less than '" << string_three << "'\n" << endl;


    // OVERLOADED OPERATOR (())
    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl;
    string_three = string_one(0,4);
    cout << "After string_three = string_one(0,4): \n";
    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl << endl;

    // OVERLOADED OPERATOR (=)
    cout << "string_two: " << string_two << '\t';
    cout << "string_three: " << string_three << endl;
    string_two = string_three;
    cout << "After string_two = string_three: \n";
    cout << "string_two: " << string_two << '\t';
    cout << "string_three: " << string_three << endl << endl;

    // OVERLOADED OPERATOR (<<) LEFT SHIFT
    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl;
    string_three = string_one << 1;
    cout << "After string_three = string_one << 1: \n";
    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl << endl;

    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl;
    string_three = string_one << 3;
    cout << "After string_three = string_one << 3: \n";
    cout << "string_one: " << string_one << '\t';
    cout << "string_three: " << string_three << endl << endl;


    // OVERLOADED OPERATOR (>>) RIGHT SHIFT
    StringManip string_five(array_two);
    cout << "string_five: " << string_five << '\t';
    cout << "string_three: " << string_three << endl;
    string_three = string_five >> 1;
    cout << "After string_three = string_five >> 1: \n";
    cout << "string_five: " << string_five << '\t';
    cout << "string_three: " << string_three << endl << endl;

    cout << "string_five: " << string_five << '\t';
    cout << "string_three: " << string_three << endl;
    string_three = string_five >> 3;
    cout << "After string_three = string_five >> 3: \n";
    cout << "string_five: " << string_five << '\t';
    cout << "string_three: " << string_three << endl << endl;


    return 0;
}
