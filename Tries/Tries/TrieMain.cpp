#include "pch.h"
#include "Trie.h"
#include <iostream>


int main() {
	Trie trie;
	//insert is working
	trie.insert("a");
	trie.insert("a");
//	trie.insert("b");
	trie.insert("an");
	/*trie.insert("ant");
	trie.insert("apple");
	trie.insert("arjun");
	trie.insert("antelope");
	trie.insert("antelopa");
	trie.insert("aero");*/
	//find is working
	trie.find("antelop");
	trie.completeCount("a");
	vector<string> words=trie.complete("a");
	trie.count();
	trie.getSize();
	/*
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
	cout << "no memory leak";
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
	cout << "we have memory leak";
	*/
}

