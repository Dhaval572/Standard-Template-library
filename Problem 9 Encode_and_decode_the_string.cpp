// Encode and decode the string
#include <iostream>
#include <vector>
using namespace std;

// Function to encode a vector of strings into a single string
string encode(const vector<string> &strs)
{
    string encoded_str = "";
    for (const string &str : strs)
    {
        encoded_str += str + "\x1F"; // Using a non-printable separator
    }
    return encoded_str;
}

// Function to decode the encoded string back into a vector of strings
vector<string> decode(const string &s)
{
    vector<string> decoded_strs;
    string temp = "";

    for (char c : s)
    {
        if (c == '\x1F')
        { 
            decoded_strs.push_back(temp);
            temp = "";
        }
        else
        {
            temp += c;
        }
    }

    return decoded_strs;
}

int main()
{
    vector<string> v = {"Hello", "World", "C++", "Encode/Decode"};
    string encoded = encode(v);
    cout << "Encoded string: " << encoded << endl;

    // Decode the encoded string back into a vector of strings
    vector<string> decoded = decode(encoded);

    // Print the decoded vector of strings
    cout << "\nDecoded strings:" << endl;
    for (const string &str : decoded)
    {
        cout << str << endl;
    }

    return 0;
}
