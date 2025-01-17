// Roman to integer number conversion
#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> romanMap;

    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    int result = 0; // Stores the final int values for romans

    for(int i = 0; i < s.size(); ++i)
    {
        // If the current Roman numeral is smaller than the next one, subtract it
        if(i + 1 < s.size() && romanMap[s[i]] < romanMap[s[i + 1]])
            result -= romanMap[s[i]]; // Subtract current value from result
        else
            result += romanMap[s[i]]; // Add current value to the result
    }

    return result;
        
}

int main()
{
    int romanDigits[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    string s;
    cout << "Enter the numbers in roman: ";
    cin >> s;
    
    return 0;
}
/*

Description:

    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

        Symbol       Value
          I            1
          V            5
          X            10
          L            50
          C            100
          D            500
          M            1000

    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

    ( This description is provided by the leetcode website )

Code Explaination:

    We used roman map to store roman as a key and int as a value in unordered map.

    Than after we checks for each character of string using for loop. ( line no. 20 to 27 )

    In this loop we used condition that checks that If the current Roman numeral is smaller than the next one.

    If this condition is true then subtract current value from result. ( line no. 24 )

    For example assume that given roman number( string ) is: ix ( i = 1, x = 10)

    I is smaller than X, so instead of adding I (which is 1) to the result, we subtract it from the value of X (which is 10).

    This gives us: 10 - 1 = 9.

    else add the number to the result. ( Line no. 26 )


    So, this was code explaination in my word. 

    I hope you understand!

*/
