/* Author : Girish Bathala, UCSD
 * Title : Transformation between strings 
 * 
 * Description : Transform one word into another with four operations :
 * 1] Add a letter
 * 2] Delete a letter
 * 3] Change a letter
 * 4] Anagram of existing word
 * 
 * Input : Associated cost with each of the above operations :
 * Say : n1 n2 n3 n4 or 1 3 4 5
 * The source and destination strings
 * 
 * Output : The cost of transforming one word to another or "-1" if it's not possible
 *
 *
 * Assumptions : ( According to the sample test cases given in the challenge )
 * 1] Minimum length of each interim word is 3
 * 2] Each word consists of only "CAPITAL" letter (26 in number), 
 *    if incorperating other ASCII characters the code can be changed accordingly
 * 3] The weight of each edge is positive ( no negative egde weights or cycles )
 */

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<boost/algorithm/string.hpp>
#include "Dictionary.h"
#include "Graph.h"

using namespace std;

// Function to retreive the input entered by the user
void getInput(unordered_map<string,int>& cost,string& srcWord, string& dstWord){
	int inputNumber;	// Variable inputNumber : retrive the numbers entered by the user
	string inputLine;	// Variable inputLine : retreive the entire line of numbers entered by the user
	vector<string> operations = {"add","delete","swap","anagram"};	// The allowed operations on each word

	cout<<"Enter the cost for : addition, deletion, replacement and anagram-check :"<<endl;	
	getline(cin, inputLine);
	istringstream stream(inputLine);
	int count = 0;
	while(stream>>inputNumber){
		cost.emplace(operations[count],inputNumber);
		count++;
	}
	
	cout<<"Enter the input string :"<<endl;
	cin>> srcWord;
	// As per assumption 2: converting the input to upper case string
	boost::to_upper(srcWord);
	cout<<"Enter the destination string :"<<endl;
	cin >> dstWord;
	boost::to_lower(dstWord);
}

int main(){
	unordered_map<string,int> cost;		// cost holds the cost for the 4 different operations
	string srcWord,dstWord;			// srcWord and dst Word are the start and ending word of the tranformation

	getInput(cost,srcWord,dstWord);		// Retrieve Input from the user	

	Dictionary rallyDict;			// Create a dictionary object

	rallyDict.insertToCollection("girish");			// Add words to dictionary
	vector<string> collection = rallyDict.getCollection();	// Get Collection of words from dictionary
	int collectionCount = rallyDict.getCollectionCount();	// Get count of collection of words from dictionary

	Graph g(collectionCount, collection, cost);		// Create a graph object

	//g.printGraph();				// Print Graph
	
	g.shortestPath(srcWord,dstWord);	// Print the cost of the shortest path from source word to destination word
	return 0;
}
