
#include <iostream>
#include "Trie.h"




Trie::~Trie()
{
	//TODO memory leak caution here
	delete root;
}


Trie::Trie()
{
	root = new TrieNode();
	root->isLastChar = false;
	root->numberOfWordsWithSamePrefix = 0;
	//root is also node
	int numberOfNodes = 1;
	int numberOfWordsinTrie = 0;
}

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
				current->children[word[i] - 'a']->numberOfWordsWithSamePrefix++;
				current = current->children[word[i] - 'a'];
				numberOfNodes++;
			}
		}
	
	current->isLastChar = true;
	numberOfWordsinTrie++;
	return true;
	}
}

int Trie::completeCount(string word)
{
	TrieNode* current = root;
	for (size_t i = 0; i < word.length(); i++) {
		if (current->children[word[i] - 'a'] == NULL)
		{
			//returns 0 of no matching words are found.
			return 0;
		}
		else
		{
			current = current->children[word[i] - 'a'];
		}
	}
	return current->numberOfWordsWithSamePrefix;
}
/*
vector<string> Trie::complete(string word)
{
	
	TrieNode* depth = root;
	TrieNode* level = root;

	vector<string> foundwords = vector<string>();
	vector<string> prefixword = vector<string>();
	if (completeCount(word) == 0) {
		return foundwords;
	}else{
		for (int i = 0; i < word.length(); i++) {
		//	depth = depth->children[word[i] - 'a'];
			level = level->children[word[i] - 'a'];;
			prefixword.push_back(level->data);
		}
		int z = completeCount(word);
		//decrease z for each found word below
		vector<TrieNode*> columns;
		for (int j = 25; j >= 0; j--) {
			if (level->children[j] != nullptr) {
				columns.push_back(level->children[j]);
			}
		}
		
		while (z != 0)
		{
			if(columns.size()>0){
			depth = columns[columns.size() - 1];
			for(int k=0;k<prefixword.size();k++){
			foundwords.push_back(prefixword[k]);
			}
			foundwords.push_back(depth->data);
			columns.pop_back();
			}
			for (int i = 0; i < 26; i++) {
				//column sweep will collect all childrens

				//below is depth control
				if (depth->children[i] != nullptr) {
					//if (depth->children[i]->isLastChar) {
					//	z--;
					//}
					//foundwords.push_back(current->data);
					depth = depth->children[i];
					foundwords.push_back(depth->data);
					i = 0;
				}
				//break;
			}

			//if (depth->isLastChar)
			//	z = 0;

			
			


			if (columns.size() > 0) {
				depth = columns[columns.size() - 1];
				columns.pop_back();
			}
		}
	}
	
	//foundwords.push_back(word);
	return foundwords;
	
	
}//end function
*/
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
vector<string> Trie::autoComplete(string word, TrieNode* current, vector<string> autocompletedwords) {
	//Declare variables
	char currentLetter;
	string discoveredWord;
	TrieNode* nextNode;

	//Check for end of word pointer
	if (current->isLastChar) {
		//If end of word pointer exists, then add word to vector
		autocompletedwords.push_back(word);

	}

	//Loop through pointers array
	for (int z = 0; z < 26; z++) {
	
		nextNode = current->children[z];
		if (nextNode != nullptr) {
		
			currentLetter = (z + 'a');
			discoveredWord = word + currentLetter;
			//Recurse to the pointer of the given letter, given the new word
			autocompletedwords = autoComplete(discoveredWord, nextNode, autocompletedwords);
		}
	}

	return autocompletedwords;
}

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

int Trie::count() {
	return numberOfWordsinTrie;
}

int Trie::getSize() {
	return numberOfNodes;
}