/*
 * Author : Tingting Zhou.
 * Assigmnet : A3-A Trie and Rule-of-Three
 * Course: CS3505 2023 Spring
 */
#include <iostream>
#include <vector>
#include<string.h>
#include"Trie.h"
using namespace std;

int main(){
    Trie t1;
    // cout << "\"a\" is a word: " << t1.isAWord("a") << endl;
    // cout << "\"an\"  is a word: " << t1.isAWord("an") << endl;
    // cout << "\"ant\"  is a word: " << t1.isAWord("ant") << endl;
    // cout << "\"antie\"  is a word: " << t1.isAWord("antie") << endl;



    t1.addAWord("ab");//Output : ab
    t1.addAWord("abc");//Output : abc
    t1.addAWord("abcze"); //Output : ze
    t1.addAWord("abcae");//Output : abcae
    t1.addAWord("abhtz");//Output : htz
    t1.addAWord("zhq");//Output : zhq




    
    cout << "==============================================="<< endl;
    // cout << "empty string is a word: " << t1.isAWord("") << endl;
    // cout << "\"a\" is a word: " << t1.isAWord("a") << endl;
    // cout << "\"ab\"  is a word: " << t1.isAWord("ab") << endl;
    // cout << "\"abcd\"  is a word: " << t1.isAWord("abcd") << endl;
    // cout << "\"abcdefg\"  is a word: " << t1.isAWord("abcdefg") << endl;
    // cout << "\"abce\"  is a word: " << t1.isAWord("abce") << endl;
    // cout << "\"abcdefghii\"  is a word: " << t1.isAWord("abcdefghii") << endl;
    // cout << "\"becd\"  is a word: " << t1.isAWord("becd") << endl;
    
    for(string word: t1.allWordsBeginningWithPrefix("")){
        cout<<word<<" | "<<endl;
    }

    // vector<string> list; 
    // string word; 
    // list = t1.getAllWords(&t1,list,word,0);
    // for (string word: list)
    // {
    //     cout << word << " | " << endl;
    // }
    return 0;
}