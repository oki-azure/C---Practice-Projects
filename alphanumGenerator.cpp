// This program populates an already existing vecotr with all the alphanumeric characters

#include <iostream>
#include <vector>

using namespace std;

void generate_alphaNum(reference_wrapper< vector<char> > characters) {
    // Generate digits '0' to '9'
    for (int i = 0; i < 10; ++i) characters.get().push_back('0' + i);

    // Generate uppercase letters 'A' to 'Z'
    for (int i = 0; i < 26; ++i) characters.get().push_back('A' + i);
    
    // Generate lowercase letters 'a' to 'z'
    for (int i = 0; i < 26; ++i) characters.get().push_back('a' + i);
}

int main() {
    vector<char> characters; 

    generate_alphaNum(characters);

    // Display the generated characters
    for (const auto& character : characters) cout << character << " ";
}

/***************************************************************************************************************************************  
This code uses ACII math to generate alphanumeric characters from 0-9, A-z to a-z
'0' + 0 = 48 + 0 = 48 (0 in ASCII)
'0' + 1 = 48 + 1 = 49 (1 in ASCII)
'0' + 2 = 48 + 2 = 50 (2 in ASCII)...in that order

'A' + 0 = 65 + 0 = 65 (A in ASCII)
'A' + 1 = 65 + 1 = 66 (B in ASCII)
'A' + 2 = 65 + 2 = 67 (C in ASCII)...in that order

'a' + 0 = 97 + 0 = 97 (a in ASCII)
'a' + 1 = 97 + 1 = 98 (b in ASCII)
'a' + 2 = 97 + 2 = 99 (c in ASCII)...in that order

when you print ASCII decimal values as chars, you get the characters they represent
***************************************************************************************************************************************/