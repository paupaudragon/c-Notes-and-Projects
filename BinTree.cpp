#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Make a binary tree class
class BT {
    BT* left;
    BT* right;
    string word;

public:
    BT(string text) {
    	left = right = nullptr; // A node starts with empty branches.
      // Data member prims do not get auto zeroed. Objects get their default
      // constructor called if not otherwise set.
	    word = text;
    }

    ~BT() {
        cout << "deleting node with word " << word << endl;
        delete left;
        delete right;
    }

    BT( const BT& other) {
        word = other.word;

        // These need to be set to something. Preset to null, then give real value
        left = right = nullptr;
        if (other.left)
            left = new BT(*(other.left));
        if (other.right)
            right = new BT(*(other.right));
    }

    // Follow the copy-then-swap idiom.
    BT& operator=(BT other) {
        std::swap(word, other.word);
        std::swap(left, other.left);
        std::swap(right, other.right);

        return *this;
    }

    void addWord(string addWord) {
      // Should probably collapse these two to an insertNode method.
      if (addWord < word) {
        if (left)
          left->addWord(addWord);
        else {
          BT* newNode = new BT(addWord);
          left = newNode;
        }
      }
      else {
        if (right)
          right->addWord(addWord);
        else {
          BT* newNode = new BT(addWord);
          right = newNode;
        }
      }
    }

    // Note that spacing is a copy. It grows on descent
    // in the tree and reverts back to the old version
    // when done with a branch.
    void printTree(string spacing) {
	     if(left)
	       left->printTree(spacing + "  ");
	     cout << spacing << word << endl;
	     if(right)
	       right->printTree(spacing + "  ");
    }

    // Here, allWords is a reference. All branches of the
    // tree add to the same vector.
    void getAll(vector<string>& allWords) {
      if (left)
        left->getAll(allWords);
      allWords.push_back(word);
      if (right)
        right->getAll(allWords);
    }
};

int main() {
    BT root("m");
    root.addWord("d");
    root.addWord("t");
    root.addWord("a");
    root.addWord("b");

    cout << "Print tree. Look at it sideways to see tree." << endl;
    root.printTree("");
    vector<string> allWords;
    root.getAll(allWords);
    cout << "Words found by getAll" << endl;
    for (string word : allWords)
      cout << word << endl;
}
