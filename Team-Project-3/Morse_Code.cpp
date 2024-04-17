#include "Morse_Code.h"

// Default Constructor
Morse_Code::Morse_Code() : binary_tree_root({}) {}

// Destructor
Morse_Code::~Morse_Code() { clear(binary_tree_root); }

// Class-member functions

/*
Empties Tree_Node variable binary_tree_root
*/
void Morse_Code::clear(Node* root) {
	if (!root) { return; }
	clear(root->left);
	clear(root->right);
	delete root;
}

/*
Converts a string of letters into a string of codes
@param: address of a string of letters
@return: string of codes
*/
std::string Morse_Code::encode(std::string& letters) {
	// FIXME <-----------------------------------------------------
}

/*
Converts a string of codes into a string of letters
@param: address of a string of codes
@return: string of letters
*/
std::string Morse_Code::decode(std::string& codes) {
	// FIXME <-----------------------------------------------------
}

/*
Creates binary tree from text file
*/
void Morse_Code::create_binary_tree() {
	std::string letter;
	std::string code;
	std::ifstream input_file;
}