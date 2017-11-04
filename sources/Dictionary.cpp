#include "Dictionary.h"
#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>

using namespace std;

// Method to retrieve the vector of strings/words which are there in the dictionay's collection
vector<string> Dictionary::getCollection(){
        if(collection.size() == 0){
		cout<<"Dictionary collection empty"<<endl;
        }
        else{
		return collection;
	}
}

// Method to get the count of the number of words in the Dictionay's collection
int Dictionary::getCollectionCount(){
	return collection.size();
}

// Method to add a new word/string into the Dictionary's collection
void Dictionary::insertToCollection(string newWord){
	boost::to_upper(newWord);
        collection.push_back(newWord);
}



