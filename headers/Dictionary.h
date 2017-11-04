#include<string>
#include<vector>

using namespace std;

// Class Disctionary to instantiate different dictionary objects with different collection of words
class Dictionary{
        private:
		// Default or initial collection of words in the dictionary
		vector<string> collection = {"HEALTH","HEATH","HEATS","HENTS","HENDS","HANDS","TEAM","MATE"};
        public:
                vector<string> getCollection();			// retrieve the collection of words in the dictionary
		int getCollectionCount();			// get number of items in the dictionary collection
                void insertToCollection(string newWord);        // insert a word to the dictionary collection
};

