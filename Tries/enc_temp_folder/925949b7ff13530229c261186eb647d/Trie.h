#pragma once
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
	int numberOfWordsWithSamePrefix;
	bool isLastChar = false;
	TrieNode* children[26];

};
class Trie {

public:
	//stores words correctly in the trie, and correctly rejects duplicate words
	Trie();
	~Trie();
	bool insert(string);
	//correctly returns the number of words in the trie
	int count();
	// correctly determines if a word is present in the trie
	int getSize();
	bool find(string);
	//	correctly returns the number of words in the trie matching a given prefix
	int completeCount(string);
	vector<string> complete(string);
	vector<string> autoComplete(string, TrieNode*, vector<string>);

private:
	TrieNode* root = NULL;
	int numberOfNodes;
	int numberOfWordsinTrie;
};
