/*
 * Author : Tingting Zhou.
 * Assigmnet : A3-A Trie and Rule-of-Three
 * Course: CS3505 2023 Spring
 */
#include <iostream>
#include <fstream>
#include "Trie.h"
using namespace std;

void printPrefixWordList(string prefix, Trie tree);

int main(int argc, char **argv)
{
    // Checks the number of argurments
    if (argc != 3)
    {
        cout << "You should only have two file name inputs." << endl;
        return -1;
    }

    char wordFname[256];
    char queriesFname[256];
    strcpy(wordFname, argv[1]);
    strcat(wordFname, ".txt");
    strcpy(queriesFname, argv[2]);
    strcat(queriesFname, ".txt");
    Trie t1;

    // Opens the first file to get the words to add to the Trie
    string line;
    ifstream myWordfile(wordFname);
    if (myWordfile.is_open())
    {
        while (getline(myWordfile, line))
        {
            t1.addAWord(line);
        }
        myWordfile.close();
    }
    else
    {
        cout << "Open the first file failed." << endl;
        return -1;
    }

    cout << endl; // Better formatting.

    // Opens the second file to search on the Tire
    ifstream myQueryfile(queriesFname);
    if (myQueryfile.is_open())
    {
        while (getline(myQueryfile, line))
        {
            string result;
            if (t1.isAWord(line))
                result = "Found";
            else
                result = "Not found";

            cout << "Testing \"" << line << "\": " << result << endl;
            printPrefixWordList(line, t1);
        }
        myQueryfile.close();
    }
    else
    {
        cout << "Open the second file failed." << endl;
        return -1;
    }

    // Test for Rule of Three
    cout << endl
         << "=======Testing for Rule of Three=======" << endl;
    Trie trie; // Defualt constructor
    trie.addAWord("a");
    Trie copyConstructorTrie = trie; // Copy construtor is invoked, deep copy
    Trie assignmentTrie;
    assignmentTrie.addAWord("ben");
    trie = assignmentTrie; // Assignment constructor is invoked
    cout << "copyConstructorTrie has \"ben\": " << copyConstructorTrie.isAWord("ben") << endl;
    cout << "trie has \"ben\": " << trie.isAWord("ben") << endl;

    return 0;
}

void printPrefixWordList(string prefix, Trie tree)
{
    cout << "Words starting with \"" << prefix << "\": ";
    for (string word : tree.allWordsBeginningWithPrefix(prefix))
    {
        cout << word << " ";
    }
    cout << endl
         << endl;
}