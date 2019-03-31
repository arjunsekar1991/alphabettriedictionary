#pragma once
# include < string > 
#include < vector >
using namespace std;

class TrieNode {
public:
	bool isLastChar = false;
	TrieNode * children[26];
};

class Trie {

public:	
	Trie();
	~Trie();
	//stores words correctly in the trie, and correctly rejects duplicate words
	bool insert(string);
	//correctly returns the number of words in the trie
	int count();
	int getSize();
	bool find(string);
	//correctly returns the number of words in the trie matching a given prefix
	int completeCount(string);
	//autocomplete feature
	vector < string > complete(string);
	

private:
	TrieNode * root = NULL;
	int numberOfNodes;
	int numberOfWordsinTrie;
	//is this allowed?
	vector < string > autoComplete(string, TrieNode *, vector < string >);
};