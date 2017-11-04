#include<climits>
#include<string>
#include<unordered_map>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

// Graph Class : stores all the vertices and the costs of all edges in the form of an adjacency list
// Pass a list of string node names and costs for diff operations : add, delete, replace and anagram
class Graph{
        private:
                int numOfNodes;						// to store the number of nodes in the graph
                vector<string> nodeNames;				// vector of strings to store the names of the nodes in the graph
		unordered_map<string,int> cost;				// map to store the weight for each operation : add, delete, replace, anagram
                unordered_map< string, list< pair<string,int> > > adjList;	// Adjacency list representation of the graph
                list< pair<string,int> > *ptr;				// Pointer to store each linked list of each node
		void addEdge(string src, string dst, int cst);		// Method to add edge between source node and dst node with a cost of cst
		void createGraph();					// Create a graph with the vector of nodeNames by using appropriate operations and their cost
		bool checkIfEqualExceptOne(string str1, string str2);	// Checks if a single char can be added to str1 to form str2
		bool checkIfAnagram(string str1, string str2);		// Checks if str1 and str2 strings are anagrams
		bool checkIfOneDifferent(string str1, string str2);	// Checks if str1 and str2 differ by only one character
		int NUM_OF_CHARS = 26;

        public:
                Graph(int numOfNodes, vector<string> nodes, unordered_map<string,int> cost);    // Constructor
		~Graph();						                        // Destructor
                void printGraph();								// Print the contents of the graph along with their edges
                void shortestPath(string src, string dst);					// Print the cost of the shortest path from src to dst
};

