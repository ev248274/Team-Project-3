#include <iostream>
#include "Morse_Code.h"

using namespace std;

int main() {
	Morse_Code first;
	string set_of_letters;
	string encoded_message;

	cout << "Enter a series of letters to be encoded: " << endl;
	cin >> set_of_letters;

	encoded_message = first.encode(set_of_letters);

	cout << "\n`" << set_of_letters << "` Encoded: `" << encoded_message << "`" << endl;
	cout << "`" << encoded_message << "` Decoded: `" << first.decode(encoded_message) << "`" << endl;

	system("pause");
	return 0;
}