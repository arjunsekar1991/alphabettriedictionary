#pragma once
# include < string > 
#include < vector >
using namespace std;

class TrieNode {
public:
	//this flag marks last character in every word
	bool isLastChar = false;
	TrieNode* children[26] ;

};

class Trie {

public:	
	Trie();
	~Trie();

	bool insert(string);
	
	int count();
	int getSize();
	bool find(string);

	int completeCount(string);
	
	vector < string > complete(string);
	

private:
	TrieNode* root = nullptr;
	int numberOfNodes;
	int numberOfWordsinTrie;
	//is this allowed?
	vector < string > autoComplete(string, TrieNode*, vector < string >);
	void trieMemoryRelease(TrieNode*);
};