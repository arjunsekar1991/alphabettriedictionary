#include "pch.h"
#include "Trie.h"
#include <iostream>
#include <fstream>


int main() {
	/*
	Trie trie;
	//insert is working
	trie.insert("a");
	trie.insert("a");
	//	trie.insert("b");
	trie.insert("an");
	trie.insert("ant");
	trie.insert("apple");
	trie.insert("arjun");
	trie.insert("antelope");
	trie.insert("antelopa");
	trie.insert("aero");
	//find is working
	bool k =trie.find("antelop");
int y=	trie.completeCount("a");
	vector<string> words = trie.complete("a");
	trie.count();
	trie.getSize();*/
	
	for (int j = 0; j < 10000; j++) {
		Trie trie;
		//insert is working
		trie.insert("a");
		trie.insert("an");
		trie.insert("ant");
		trie.insert("apple");
		trie.insert("arjun");
		trie.insert("antelope");
		//find is working
		trie.find("antelop");
		trie.completeCount("a");
	}
	//cout << "no memory leak";
	for (int j = 0; j < 100000; j++) {
		Trie trie;
		//insert is working
		trie.insert("a");
		trie.insert("an");
		trie.insert("ant");
		trie.insert("apple");
		trie.insert("arjun");
		trie.insert("antelope");
		//find is working
		trie.find("antelop");
		trie.completeCount("a");
			}
	//cout << "we have memory leak";
	/*Trie trie2;
	//insert is working
	trie2.insert("a");
	*/
	

		string wordToComplete;
		string userResponse;
		string wordToInsertInTrie;
		Trie alphabetTrie;




		ifstream inFile("wordlist.txt");
		// input file not able to open
		if (inFile.is_open() == false) {
			return 0;
		}


		while (inFile.eof() == false) {
			getline(inFile, wordToInsertInTrie, '\n');
	//there an empty sapce at the last line
			if (wordToInsertInTrie.length() != 0) {
				alphabetTrie.insert(wordToInsertInTrie);
			}

		}

		//Get user input
		while (true) {

			wordToComplete = "";
			userResponse = "";


			cout << "Please enter a word prefix (or press enter to exit): ";
			//Get prefix
			getline(cin, wordToComplete);
			//If user presses enter with no input
			if (wordToComplete.length()==0) {

				system("PAUSE");
				return 0;
			}
			//covert to lowercase
			for (int i = 0; i < wordToComplete.length(); i++) {
				wordToComplete[i] = tolower(wordToComplete[i]);
			}

			int completionCount = alphabetTrie.completeCount(wordToComplete);

			cout << "There are " << completionCount <<
				" completions for the prefix '" << wordToComplete <<
				"' .  Show completions? (enter Yes or No) ";


			getline(cin, userResponse);

				if (userResponse == "no") {

			}
			if (userResponse == "Yes")
			{

				vector<string> completeWords = alphabetTrie.complete(wordToComplete);
				cout << "Completions" << "-----------" << endl;

				for (size_t i = 0; i < completeWords.size(); i++)
				{
					cout << completeWords.at(i) << endl;
				}
			}
		

			cout << endl;
		}
	
	
}
	