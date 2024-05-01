#include <iostream>
#include "Morse_Code.h"

using namespace std;

int main() {
	Morse_Code first;
	string set_of_letters;
	string encoded_message;
	string whitespace; // used for formatting

	cout << "Enter a series of letters to be encoded: " << endl;
	cin >> set_of_letters;

	encoded_message = first.encode(set_of_letters);
	whitespace = std::string(encoded_message.size() - set_of_letters.size(), ' ');

	cout << "\n`" << set_of_letters << "` " << whitespace << "Encoded: `" << encoded_message << "`" << endl;
	cout << "`" << encoded_message << "` Decoded: `" << first.decode(encoded_message) << "`" << endl;

	system("pause");
	return 0;
}