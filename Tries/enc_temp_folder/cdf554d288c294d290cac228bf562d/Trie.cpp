
#include <iostream>
#include "Trie.h"


//space complexity : n*m m is the length of longest word and n is number of such words
// Time complexity : Theta(n) number of nodes
Trie::~Trie()
{
	
	delete root;
}

// Time complexity : Theta(1)
Trie::Trie()
{
	root = new TrieNode();
	root->isLastChar = false;
	
	//root is also node
	int numberOfNodes = 1;
	int numberOfWordsinTrie = 0;
}
// Time complexity : Theta(m) m -> number of letters in word
bool Trie::insert(string word)
{
	TrieNode* current = root;
	// this will reject duplicate
	if (find(word)) {
		return false;
	}
	else{
		for (size_t i = 0; i < word.length(); i++) {
			if (current->children[word[i] - 'a'] == nullptr)
			{
			
				current->children[word[i] - 'a'] = new TrieNode();
				current = current->children[word[i] - 'a'];
				numberOfNodes++;
			}
			else
			{
				
				current = current->children[word[i] - 'a'];
				numberOfNodes++;
			}
		}
	
	current->isLastChar = true;
	numberOfWordsinTrie++;
	return true;
	}
}
// Theta(n) where l is the length of prefix word
int Trie::completeCount(string word)
{
	vector<string> foundwords = complete(word);
	return foundwords.size();
}

vector<string> Trie::complete(string word) {
	

	TrieNode* current = root;

	vector<string> autocompletedwords;

	bool isPrefixPresent = find(word);
	if (!isPrefixPresent){
		return autocompletedwords;
	}
	else{

		for (size_t i = 0; i < word.length(); i++) {
			
			current = current->children[word[i] - 'a'];
		}
		autocompletedwords = autoComplete(word, current, autocompletedwords);

	return autocompletedwords;
	}
}

//recursive all to 
vector<string> Trie::autoComplete(string word, TrieNode* current, vector<string> autocompletedwords) {

	string currentLetter;
	string discoveredWord;
	TrieNode* nextNode;


	if (current->isLastChar) {

		autocompletedwords.push_back(word);
	}


	for (int z = 0; z < 26; z++) {
	
		nextNode = current->children[z];
		//every non null pointer will start a new recursion and find new words
		if (nextNode != nullptr) {
			currentLetter = (z + 'a');
			discoveredWord = word + currentLetter;
			autocompletedwords = autoComplete(discoveredWord, nextNode, autocompletedwords);
		}
	}

	return autocompletedwords;
}
//theta(m) where m is the length of the word
//is last work flag shows us whether the word is present in trie or not
bool Trie::find(string word)
{
	TrieNode* current = root;

	for (size_t i = 0; i < word.length(); i++) {
		if (current->children[word[i] - 'a'] == NULL)
			return false;
		current = current->children[word[i] - 'a'];
	}
	return current->isLastChar;
}
//Theta(1) we already calculate during insert itself 
int Trie::count() {
	return numberOfWordsinTrie;
}
//Theta(1) we already calculate during insert itself 
int Trie::getSize() {
	return numberOfNodes;
}