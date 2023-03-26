#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

/**
 * Prints vector in groups of 4 integers
*/
void printOutput(std::vector<int> input)
{
    for (int i = 0; i < input.size(); i++) 
    {
        if (input[i] < 1000)
        {
            std::cout << "0" << input[i] << " ";
        }
        else
        {
            std::cout << input[i] << " ";
        }
    }
}

/**
 * Filters digits out of string and puts in a vector
*/
std::vector<int> stringToVector(std::string short_text)
{
    std::vector<int> daily_time;
    std::string hour_text;

    /**
     * Creates a vector of 4-digit integers
    */
    for (int i = 0; i < short_text.size(); i++)
    {
        if (isdigit(short_text[i]) == true) // if element is digit
        {
            hour_text.push_back(short_text[i]);
            if (hour_text.size() == 4)
            {
                int hour = std::stoi(hour_text);
                daily_time.push_back(hour);
                hour_text.clear();
            }
        }
    }

    return daily_time;
}

/**
 * Apply Maxiflex rules to hours
*/
bool maxiflex(std::vector<int> int_vector_hours)
{
    bool rule_breaker = false;
    if (int_vector_hours[0] < 600)
        rule_breaker = true;
    if (int_vector_hours[3] > 2000)
        rule_breaker = true;
    
    return rule_breaker;
}

int main()
{
    std::vector<int> int_vector_hours;
    std::string short_text = "0800-1200 : 1230 -1630";
    int_vector_hours = stringToVector(short_text);
    // maxiflex(short_text);
    
    
    printOutput(int_vector_hours);


    return 0;
}
