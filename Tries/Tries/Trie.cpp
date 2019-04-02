
#include <iostream>
#include "Trie.h"


//space complexity : n*m m is the length of longest word and n is number of such words
// Time complexity : Theta(n) number of nodes
Trie::~Trie()
{
	//delete root;
	trieMemoryRelease(root);

	
}

// Time complexity : Theta(1)
Trie::Trie()
{
	root = new TrieNode();
	root->isLastChar = false;
	
	//root is also node
	numberOfNodes = 1;
	numberOfWordsinTrie = 0;
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
				//each node added is recorded here
				numberOfNodes++;
			}
			else
			{
				
				current = current->children[word[i] - 'a'];
			}
		}
	
	current->isLastChar = true;
	numberOfWordsinTrie++;
	return true;
	}
}
// Theta(n) where n is the number of words with same prefix
int Trie::completeCount(string word)
{
	vector<string> foundwords = complete(word);
	return foundwords.size();
}
//Time complexity if suppose n words are there for the given prefix then 
//Theta (n)
vector<string> Trie::complete(string word) {
	

	TrieNode* current = root;

	vector<string> autocompletedwords;

	//bool isPrefixPresent = find(word);
	/*if (!isPrefixPresent){
		autocompletedwords = autoComplete(word, current, autocompletedwords);
		return autocompletedwords;
	}
	else{*/

		for (size_t i = 0; i < word.length(); i++) {
			if (current->children[word[i] - 'a'] != nullptr)
				current = current->children[word[i] - 'a'];
			else
				return autocompletedwords;
		}
		autocompletedwords = autoComplete(word, current, autocompletedwords);

	return autocompletedwords;
	//}
}

/*recursing to find all the possible completion 
parameter 1 is the word that is newly discovered in every step
current is the node that contains the most recently discovered word
autocompletedwords is the final output of words this will be updated based on the 
discovered words with is last char boolean flag

*/
vector<string> Trie::autoComplete(string word, TrieNode* current, vector<string> autocompletedwords) {

	string currentLetter;
	string discoveredWord;
	TrieNode* nextNode;

	//add the work if the boolean flag isLastChar is true
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
		if (current->children[word[i] - 'a'] == nullptr)
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
//Theta(n) where n is the number of nodes

void Trie::trieMemoryRelease(TrieNode* current) {
	TrieNode* nextNode;
	for (size_t i = 0; i < 26; i++) {
		nextNode = current->children[i];
		if (nextNode != nullptr)
		{
			trieMemoryRelease(nextNode);
			//delete[] nextNode->children;
			//delete nextNode;
			
		}
		
	}
	// current->children=NULL;
	//if(current!=root)
	//root requires special treatment here
	if (current == root) {
		*root->children = nullptr;
		root = nullptr;
		delete root;
	}
	 *current->children=nullptr;
	 delete current;

	return;
}