#include <iostream>

using namespace std;

void clear()
{
    cout << "\033[2J\033[1;1H";
}

bool is_digit_only(string input)
{
    bool return_value = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        { // if not digit
            return_value = false;
        }
    }
    return return_value;
}
