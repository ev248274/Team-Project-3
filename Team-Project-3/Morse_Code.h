#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <fstream>
#include <string>
#include <sstream>

class Morse_Code {
private:
    struct Node {
        std::string letter;
        std::string code; // May not be considered a binary tree
        Node* left, * right;
        Node(std::string letter, std::string code, Node* left = NULL, Node* right = NULL) :
            letter(letter), code(code), left(left), right(right) {}
    };
    Node* binary_tree_root;
public:
    // Constructors
    Morse_Code();

    // Destructor
    ~Morse_Code();

    // Class-member functions
    void clear(Node*); // Empties binary tree located from root variable binary_tree_root
    std::string encode(std::string&); // Converts a message of letters into codes
    std::string decode(std::string&); // Decodes a message of codes into letters
    void create_binary_tree(); // Initializes binary_tree_root with binary tree inside of Morse_Code.txt
};

#endif MORSE_CODE_H