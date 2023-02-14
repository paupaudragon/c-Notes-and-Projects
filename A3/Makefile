CC = g++
CFLAGS = -Wall  -fsanitize=undefined -fsanitize=address -g -std=c++11

# Directory for external library harulib
LOCALFOLDER = .

TrieTest: TrieTest.o Trie.o 
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp Trie.o
	$(CC) $(CFLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp 

test: TrieTest
	./TrieTest "word" "queries"
clean: 
	rm *.o TrieTest