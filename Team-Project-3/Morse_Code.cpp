#include "Morse_Code.h"

// Default Constructor
Morse_Code::Morse_Code() : binary_tree_root(new Node(' ')) { create_binary_tree(); }

// Destructor
Morse_Code::~Morse_Code() { clear(binary_tree_root); }

// Class-member functions

/*
Empties Tree_Node variable binary_tree_root
@param root: given root node
*/
void Morse_Code::clear(Node* root) {
	if (!root) { return; }
	clear(root->left);
	clear(root->right);
	delete root;
}

/*
Converts a string of letters into a string of codes
@param letters: address of a string of letters
@return string: string of codes
*/
std::string Morse_Code::encode(std::string& letters) {
	std::string codes = "";
	for (auto it = letters.begin(); it != letters.end(); ++it) {
		find_code_for_specific_letter(binary_tree_root, *it, "");
		if (codes == "") { 
			codes = temp_c; 
			temp_c = "";
		}
		else { 
			codes += " " + temp_c; 
			temp_c = "";
		}
	}
	return codes;
}

/*
Finds the code for a specific char in string letters
@param node: node pointer 
@param ltr: letter to find the code for
@param cde: string used to create the code recursively
*/
void Morse_Code::find_code_for_specific_letter(Node* node, char& ltr, std::string cde) {
	if (!node) { return; }
	else if (node->letter == ltr) { 
		temp_c = cde;
		return; 
	}
	else {
		cde += ".";
		find_code_for_specific_letter(node->left, ltr, cde);
		cde.replace(cde.size() - 1, 1, "-");
		find_code_for_specific_letter(node->right, ltr, cde);
	}
}

/*
Converts a string of codes into a string of letters
@param codes: address of a string of codes
@return string: string of letters
*/
std::string Morse_Code::decode(std::string& codes) {
	std::string str;
	// FIXME <----------------------------------------------------------------------------
	return str;
}

/*
Creates binary tree from text file
*/
void Morse_Code::create_binary_tree() {
	char letter;
	std::string code;
	std::string original_code;
	std::ifstream input_file;

	input_file.open("Morse_Code.txt");

	while (getline(input_file, original_code)) {
		letter = original_code.at(0);
		original_code.erase(0, 1);
		code = original_code;
		create_node(binary_tree_root, code, letter);
	}
}

/*
Attaches an individual node to be put into the binary tree
@param node: Pointer to node
@param cde: Address of string morse code (to be changed)
@param o_code: Address of string original code, which is the code without any changes
@param ltr: Address of string letter
*/
void Morse_Code::create_node(Node* node, std::string& cde, char& ltr) {
	if (cde == "") { 
		node->letter = ltr;
		return;
	}
	else if (cde.at(0) == '.') {
		if (!node->left) {
			Node* node_l = new Node(' ');
			node->left = node_l;
			create_node(node_l, cde.erase(0, 1), ltr);
		}
		else { create_node(node->left, cde.erase(0, 1), ltr); }
	}
	else {
		if (!node->right) {
			Node* node_r = new Node(' ');
			node->right = node_r;
			create_node(node_r, cde.erase(0, 1), ltr);
		}
		else { create_node(node->right, cde.erase(0, 1), ltr); }
	}
}