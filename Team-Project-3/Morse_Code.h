#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using std::ifstream;

class Morse_Code {
private:
    struct Node {
        char letter;
        Node* left, * right;
        Node(char letter, Node* left = NULL, Node* right = NULL) :
            letter(letter), left(left), right(right) {}
    };
    Node* binary_tree_root;
    char temp_l;
    std::string temp_c;
public:
    // Constructors
    Morse_Code();

    // Destructor
    ~Morse_Code();

    // Class-member functions
    void clear(Node*); // Empties binary tree located from root variable binary_tree_root
    std::string encode(std::string&); // Converts a message of letters into codes
    void find_code_for_specific_letter(Node*, char&, std::string); // Finds a code for a specific char letter
    std::string decode(std::string&); // Decodes a message of codes into letters
    void create_binary_tree(); // Initializes binary_tree_root with binary tree inside of Morse_Code.txt
    void create_node(Node*, std::string&, char&); // Creates an individual node to be put into the binary tree
};

#endif MORSE_CODE_H