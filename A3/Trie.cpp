/*
 * Author : Tingting Zhou.
 * Assigmnet : A3-A Trie and Rule-of-Three
 * Course: CS3505 2023 Spring
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "Trie.h"
#include<tuple>
using namespace std;

// Default Constructor
Trie::Trie()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        branches[i] = nullptr;
    }
    completeWord = false;
}

// Copy Constructor
Trie::Trie(const Trie &other)
{
    completeWord = other.completeWord;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        branches[i] = nullptr;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (other.branches[i])
            branches[i] = new Trie(*other.branches[i]); // Allocates new storage on heap to get a deep copy.
    }
}

// Overlaoded Assignment Operator
Trie &Trie::operator=(Trie other)
{
    std::swap(completeWord, other.completeWord);
    std::swap(branches, other.branches);
    return *this;
}

// Destructor
Trie::~Trie()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        delete branches[i];
    }
}

bool Trie::contains(char letter)
{
    return branches[letter - 'a'];
}

// This method calls its helper method to add the word.
// Optimization: isAWord() is not called here, because it should add the letters as it checks if the tree has the letter.
// It is bad performance if it visits all the way down the tree to find out it's not a word. And go back to add the letter starting from beigining.
void Trie::addAWord(string newWord)
{
    if (newWord.size() > 0 && isLowerCase(newWord))
    {
        // Trie *root = this;
        // addAWordHelper(root, newWord);

        Trie *root = this;
        tuple<Trie *, unsigned> unMatchedInfo = getUnmathedIndex(root, newWord, 0);
        root = get<0>(unMatchedInfo);
        unsigned unMacthedIndex = get<1>(unMatchedInfo);

        if(unMacthedIndex==newWord.size()){
            root->completeWord=true;
            return;
        }

        addAWordHelper(root, newWord, unMacthedIndex);
    }
}


void Trie::addAWordHelper(Trie *root, string newWord, unsigned index)
// void Trie::addAWordHelper(Trie *root, string newWord)
{
    // // if the root doesn't contain the first letter of the string
    // if (!root->contains(newWord[0]))
    // {
    //     root->branches[newWord[0] - 'a'] = new Trie(); // create this branch
    // }

    // root = root->branches[newWord[0] - 'a']; // Move the root to the current letter's node

    // // Check if this letter is at the end of the newWord string.
    // if (newWord.size() == 1)
    // {
    //     root->completeWord = true; // Set this letter's node as a leaf.
    //     return;
    // }

    // // Letter is not the last element of the string, enter recursion.
    // addAWordHelper(root, newWord.erase(0, 1)); // erase method removes the fist letter of the string here.

    root->branches[newWord[index] - 'a'] = new Trie();
    root = root->branches[newWord[index] - 'a'];
    if (index == newWord.size() - 1)
    {
        root->completeWord = true;
        return;
    }
    addAWordHelper(root, newWord, ++index);
}

// This is a method calls its private helper method.
bool Trie::isAWord(string word)
{
    // empty string and special character, return false
    if (word.empty() || !isLowerCase(word))
        return false;

    // Trie *root = this;
    // return isAWordHelper(root, word);

    Trie *root = this;
    tuple<Trie *, unsigned> unMatchedInfo = getUnmathedIndex(root, word, 0);
    root = get<0>(unMatchedInfo); 
    cout<<endl<<"unmatch"<< get<1>(unMatchedInfo)<<endl;
    if(get<1>(unMatchedInfo) == word.size() && root->completeWord)
        return true; 
    
    return false; 
}

// Recursively checks if the first letter of string is a node of a root, until the whole string is checked.
// Optimization tradeoff: this method looks similar to addWordHelper(), becaseu author doesn't want to repeat node visting.
// The structure looks the same but they have different tasks entering each condition.
// bool Trie::isAWordHelper(Trie *root, string word)
// {
//     // If the root doesn't contain the first letter of the string.
//     if (!root->contains(word[0]))
//     {
//         return false;
//     }

//     root = root->branches[word[0] - 'a']; // If it does contain the letter, move the root to this letter's node.

//     // If this letter is the last letter of the string, check if the corresponding node is a leaf.
//     if (word.size() == 1)
//     {
//         return root->completeWord;
//     }

//     // Letter if not the last element of the string, enter recursion.
//     return isAWordHelper(root, word.erase(0, 1)); // erase method removes the fist letter of the string here.
// }

// If the prefix the an empty string returns all words on the tree.
// Otherwise, returns the words starting with the prefix.
vector<std::string> Trie::allWordsBeginningWithPrefix(string prefix)
{
    Trie *root = this;
    vector<string> wordList;
    string wordSpace;

    if (prefix.empty())
    {
        getAllWords(root, wordList, wordSpace);
        return wordList;
    }

    unsigned index = 0;
    unsigned *indexPtr = &index;
    getPrefixWords(root, wordList, prefix, indexPtr, wordSpace);
    return wordList;
}

// This is a private helper method for allWordsBeginningWithPrefix().
// It traverse the prefix by itertaion, but recursion on the tree.
// The index is the index of the current letter of the string. Pass pointer to keep the change of the index.
// wordSpace is pass by reference to keep the change as going down the tree.
void Trie::getPrefixWords(Trie *root, vector<string> &wordList, string prefix, unsigned *index, string &wordSpace)
{
    // If the root contains this letter
    if (root->contains(prefix[*index]))
    {
        wordSpace.push_back(prefix[*index]);         // Add this letter to the string
        root = root->branches[prefix[*index] - 'a']; // Move the root this this letter's node

        // If this letter is the last letter of the prefix
        if (*index == prefix.size() - 1)
        {
            // Checks is this prefix is a word on the tree, if it is add it to the list.
            if (root->completeWord)
            {
                wordList.push_back(wordSpace);
            }

            // Get the children word of prefix's last letter.
            vector<string> wordsOfPrefixLastLetter;
            string word;
            wordsOfPrefixLastLetter = getAllWords(root, wordsOfPrefixLastLetter, word);
            for (string s : wordsOfPrefixLastLetter)
            {
                wordList.push_back(prefix + s);
            }
        }
        // If the letter is not the last letter of the tree, move ti the next letter and enter recursion
        else
        {
            (*index)++;
            getPrefixWords(root, wordList, prefix, index, wordSpace);
        }
    }
}

// This method uses iteration to traverse on the same level of the tree, but recursion to traverse the next level of tree.
// Backtracking: 1. The parent root is saved before moving to the next level. root will be reset to parent before backtracking.
//               2. The wordSapce string is passed by reference, and will remove the last letter before backtracking.
// Optimization: The method handles when the root has no children situation. There is no helper method for checking if a root has any child,
//               because author didn't want to visit node twice.
vector<std::string> &Trie::getAllWords(Trie *root, vector<string> &wordList, string &wordSpace)
{
    Trie *parent = root;

    for (unsigned i = 0; i < ALPHABET_SIZE; i++) // Iterates through root's children
    {

        if (root->branches[i]) // If child exist.
        {
            wordSpace.push_back(i + 'a'); // Add letter to the string
            root = root->branches[i];     // Move the root to this letter
            if (root->completeWord)       // Check if this letter is a leaf
            {
                wordList.push_back(wordSpace); // add the string to the list
            }
            getAllWords(root, wordList, wordSpace); // check this letter's children
        }

        if (i == ALPHABET_SIZE - 1 && !wordSpace.empty())
        {
            wordSpace.erase(wordSpace.size() - 1); // erase the last letter for backtracking
        }
        root = parent; // backtracking the parent node
    }

    return wordList;
}

bool Trie::isLowerCase(string word)
{
    for (auto it = word.begin();
         it != word.end();
         it++)
    {
        if (!isalpha(*it) || isupper(*it))
            return false;
    }
    return true;
}

tuple<Trie*, unsigned> Trie::getUnmathedIndex(Trie* root, string word, unsigned index)
{
    tuple<Trie *, unsigned> result;

    if (!root->contains(word[index])) // if the parent doesn't contain this letter
    {
        result=make_tuple(root, index); // return the parent root and this letter's index
        return result;
    }
    
    root = root->branches[word[index] - 'a']; // move root this this letter.

    // if parent root has this letter, and this letter is not the last letter of the word
    if ((index) == word.size() - 1)
    {
        return make_tuple(root, ++index); // if the last letter is on the tree, index = word.size() will be returned.
    }

    return getUnmathedIndex(root, word, ++index);
}
