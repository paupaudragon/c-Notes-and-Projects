#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BT
{
    BT *left; // primitives not initialized to valid value;
    BT *right;
    string word;

public:
    BT(string text) // node is not a class.
    {
        left = right = nullptr;
        word = text;
    }

    ~BT()
    {
        delete left;
        delete right;
    }

    // copy constructor
    BT(const BT &other)
    {
        word = other.word;
        left = right = nullptr; // need to assign values to all fields
        if (other.left) //ptr not null
        {
            left = new BT(*(other.left)); // covernt ptr to an obj
        }
        if (other.right)
        {
            right = new BT(*(other.left)); // covernt ptr to an obj

            // right = other.right bad just copying address
            //  *right = *(other.right )// bad
        }
    }

    // assignment
    BT &operator=(BT other)
    {
        swap(word, other.word);
        swap(left, other.left);
        swap(right, other.right);
        return *this;
    }

    void addWord(string wordToAdd)
    {
        if (wordToAdd < word)
        {
            if (left)
            { // 0 is false, non-zero is ture.
                left->addWord(wordToAdd);
            }
            else
            {
                BT *newNode = new BT(wordToAdd);
                left = newNode;
            }
        }
        else
        {
            if (right)
            { // 0 is false, non-zero is ture.
                right->addWord(wordToAdd);
            }
            else
            {
                BT *newNode = new BT(wordToAdd);
                right = newNode;
            }
        }
    }

    void printTree(string spacing)
    {
        if (left)
        {
            left->printTree(spacing + "     ");
        }
        cout << word << endl; // no need to check nullity
        if (right)
        {
            right->printTree(spacing + "     ");
        }
    }

    void getAll()(vector<string> &allWords)
    {
        if (left)
        {
            left->getAlL(allWords);
            allWords.push_back(word);
        }
        if (right)
        {
            right->getAll(allWords);
            allWords.push_back(word);
        }
    }
};

int main()
{
    BT tree("apple");
    tree.addWord("bear");
    tree.addWord("zebra");
    tree.printTree("");
    vector<string> all;
    tree.getAll(all);
    for (string word : tree.getAll(all))
    {
        cout << all << endl;
    }
}

// a node is an array nullptr, left , right

//