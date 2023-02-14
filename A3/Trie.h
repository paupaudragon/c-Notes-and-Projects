/*
 * Author : Tingting Zhou.
 * Assigmnet : A3-A Trie and Rule-of-Three
 * Course: CS3505 2023 Spring
 */
#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include<tuple>
#include <string.h>

using namespace std;

// The size of English alphabet letters
const int ALPHABET_SIZE = 26;

/**
 * A Trie class that can store 26 English letters at each tree level.
 * It has a flag to mark if a Trie on the tree is an end of a word.
 */
class Trie
{
    Trie *branches[ALPHABET_SIZE]; // Array of pointer of Trie objects.
    bool completeWord;             // Mark if this Trie is a leaf.

    /// @brief Checks if a string contains only lower-case letters.
    /// @param word the string to be checked
    /// @return true if the string only contains lower-case letter; otherwise false.
    bool isLowerCase(string word);

    /// @brief Checks if a Trie has a letter as its child.
    /// @param letter The letter to be checked with.
    /// @return True if the Trie has the child of this letter; otherwise false.
    bool contains(char letter);

    
    // void addAWordHelper(Trie *root, string newWord);
     void addAWordHelper(Trie *root, string newWord, unsigned index);

    // /// @brief Checks if a non-empty all-lower-case string word exist on the Trie tree.
    // /// @param root The root Trie tree's pointer
    // /// @param word The word will be searched.
    // /// @return True, if the word exists; otherwise false.
    // bool isAWordHelper(Trie *root, string word);

    /// @brief Gets a collection of all words from a Trie tree.
    /// @param root The Tire tree's pointer
    /// @param wordList The word list to return
    /// @param wordSpace A string's reference to store a word.
    /// @return A refrence of a string vector representing all words on the tree.
    vector<std::string> &getAllWords(Trie *root, vector<string> &wordList, string &wordSpace);

    /// @brief Gets all the words from the tree starting with the prefix
    /// @param root The Tire tree's pointer
    /// @param wordList A reference of a string vector
    /// @param prefix The prefix to search with
    /// @param index The pointer of the index of the letter from the prefix
    /// @param wordSpace The reference of string representing the word.
    void getPrefixWords(Trie *root, vector<string> &wordList, string prefix, unsigned *index, string &wordSpace);

    tuple<Trie*, unsigned> getUnmathedIndex(Trie* root, string word, unsigned index);

public:
    /// @brief Default constructor
    Trie();

    /// @brief Copy constructor
    /// @param other the Trie object to be copied from.
    Trie(const Trie &other);

    /// @brief Overloaded assignment operator
    /// @param other the Trie object on the left side of the assignment operator
    /// @return A reference to a Trie.
    Trie &operator=(Trie other);

    /// @brief Destructor
    ~Trie();

    /// @brief Adds a string(only lower-case letter allowed) to the Trie tree. If the string is empty, do nothing.
    /// @param newWord The word to be added.
    void addAWord(string newWord);

    /// @brief Checks if a word exists on the tree. Empty string or string (not all lower cased letter) will return false.
    /// @param word The word to be checked
    /// @return True, if the tree contains this word(only lower-case letters); otherwise, false.
    bool isAWord(string word);

    /// @brief Gets the list of all words that begins with a given prefix from the tree.
    /// @param prefix The prefix to be checked.
    /// @return A vector a strings representing the word list.
    vector<std::string> allWordsBeginningWithPrefix(string prefix);
};
#endif