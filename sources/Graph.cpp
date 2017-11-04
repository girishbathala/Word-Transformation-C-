#include "Graph.h"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<set>
#include<boost/algorithm/string.hpp>

using namespace std;

// Constructor : Initialize the number of nodes and node names attributes
// Call the createGraph function to create a graph with the nodeNames as vertices 
// and the edge weights as per the cost of the four operations : add, delete, replace and anagram
Graph::Graph(int numOfNodes, vector<string> nodeNames, unordered_map<string,int> cost){
	numOfNodes = numOfNodes;
	this->nodeNames = nodeNames;
	this->cost = cost;
	ptr = new list< pair< string,int > >[numOfNodes];
	// Create the adjacency list with node names as keys
	for(int i = 0; i < nodeNames.size(); i++){
		adjList[nodeNames[i]] = ptr[i];
	}
	// Create a graph with the vector of strings using the cost of each operation
	createGraph();
}

//Desctructor : Delete dynamically allocated memory
Graph::~Graph(){
	delete [] ptr;
}


// Create a graph with the list of node names and edges are formed
// based on one of the four operations : add, delete, replace, anagram
void Graph::createGraph(){	
	// For each word: check if a edge can be formed with every other word
	for(auto srcNode: nodeNames){
		for(auto adjNode: nodeNames){
			
			if(srcNode != adjNode){
				if(checkIfEqualExceptOne(srcNode, adjNode)){
					addEdge(srcNode,adjNode,cost["add"]);
					addEdge(adjNode,srcNode,cost["delete"]);
				}
				else if(checkIfAnagram(srcNode,adjNode)){
					addEdge(srcNode,adjNode,cost["anagram"]);
				}
				else if(checkIfOneDifferent(srcNode,adjNode)){
					addEdge(srcNode,adjNode,cost["swap"]);
				}
			}
		}
	}
}

// Method to check if only a single "character" is different between 
// the two strings str1 and str2 
bool Graph::checkIfOneDifferent(string str1, string str2){
	bool incorrect = false;
	if(str1.length() != str2.length()){
		return false;
	}

	for(int i = 0; i<str1.length(); i++)
		if(str1[i]  != str2[i]){
			if(incorrect){
				return false;
			}
			else{
				incorrect = true;
			}
		}
	return true;
}

//Method to check if two strings str1 and str2 have 
//the same characters in different OR are anagrams
bool Graph::checkIfAnagram(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}

	vector<int> count(NUM_OF_CHARS,0);

	for(int i = 0; i<str1.length(); i++){
		count[str1[i] - 'A'] ++;
		count[str2[i] - 'A'] --;
	}

	for(auto charCount:count){
		if(charCount != 0){
			return false;
		}
	}	
	return true;
}

//Method to check if string str1 can be transformed into
//string str2 by addition of a single character 
bool Graph::checkIfEqualExceptOne(string str1, string str2){
	if((str2.length() - str1.length()) != 1){
		return false;
	}
	int incorrect = 1;
	int indStr1 = 0;
	for(int indStr2 = 0; indStr2 < str2.length();indStr2++){
		if(str1[indStr1] != str2[indStr2]){
			if(incorrect == 2){
				return false;
			}
			else{
				indStr1--;
				incorrect++;
			}
		}
		indStr1++;
	}
	return true;
}



// Method to add edge between source node src and destination node dst with a cost of cst
void Graph::addEdge(string src, string dst, int cst){
	adjList[src].push_back(make_pair(dst,cst));
}

// Method to print out the graph which is stored in the adjacency list "adjList"
void Graph::printGraph(){
	for(auto node:adjList){
		cout<<"------------------"<<endl;
		cout<<"src: "<<node.first<<" "<<endl;;
		for(auto el:node.second){
			cout<<"dst : "<<el.first<<" cost :"<<el.second<<endl;
		}
	}
}


// Method to find out the shortest distance between source and destination word
// Algorithm : Dijkstra's algorithm, since the weights are postitive according to
// assumption 3].
// Output : Shortest cost path from source to destination and -1 if there is no path
void Graph::shortestPath(string src, string dst){
	boost::to_upper(dst);
	boost::to_upper(src);
	cout<<"Source :"<<src<<endl;
	cout<<"Dst :"<<dst<<endl;

	// If the length of the source and destination words are less than 3, then output '-1'
	// since they are invalid inputs
	if( (src.length() < 3) or (dst.length() <3) ){
		cout<<"Cost : "<<(-1)<<endl;
		return;
	}

	// SET to store all the vertices which are accessible from src, along with their shortest path dist
	// Int first so that it is sorted as min_heap according to first element
	// (cost, node)
	set<pair<int,string> > reachableSet;
	// dist map to hold the final distances to each vertex from src
	// Init all of them to INT_MAX
	unordered_map< string,int > dist;
	// Visited Array
	unordered_map<string,int> visited;
	
	for(auto node:nodeNames){
		dist[node] = INT_MAX;
		visited.insert(make_pair(node,0));
	}


	//Check if either of the two strings are in the graph or not
	if( (dist.find(src) == dist.end()) or (dist.find(dst) == dist.end())){
		cout<<"Cost : "<<(-1)<<endl;
		return;
	}

	// Set the dist[src] = 0 and add it to the Reachable set as well
	reachableSet.emplace(0,src);
	dist[src] = 0;


	pair<int,string> temp;				// temp pair variable to store the node with shortest cost path and it's shortest cost
	string u,v;					// 'u' represents the node with the shortest cost path, v represents the neighbours of u
	int costUV;					//  costUV is the weight of the edge between vertex u and vertex v
	set<pair<int,string>>::iterator itrBegin;	// Iterator to retreive the position of the pair with the shortest cost path in the tree
	set<pair<int,string>>::iterator itrFind;	// Iterator to find the neighbour 'v' in the reachableSet before deleting it
	
	
	//Loop over till set is empty
	while(!reachableSet.empty()){
		itrBegin = reachableSet.begin();	// Access first or top element with least dist
		temp = (*itrBegin);			
		reachableSet.erase(itrBegin);		// Delete this node ' u ' reachable with shortest cost from SET

		u = temp.second;
		dist[u] = temp.first;			// Store the shortest cost path in dist[u]

		// If we have reached our target node, we can print the shortest path and terminate the function 
		if(u == dst){
			cout<<"Cost : "<<dist[u]<<endl;
			return;
		}		
		//Loop over all neighbours of ' u '
		for(auto neighbours:adjList[u]){
			v = neighbours.first;
			// If the shortest cost path of the vector is already computed/processed
			// We move on to the next neighbour
			if(!(visited[v])){

				costUV = neighbours.second;
				// Check if there is a better path to 'v' than the previous computed path
				if( dist[v] > (dist[u] + costUV)){
				
					//Delete the node in the Reachable set if it exists
					if(dist[v] != INT_MAX)
					{
						itrFind = reachableSet.find(make_pair(dist[v],v));
						if(itrFind != reachableSet.end()){
							reachableSet.erase( make_pair( dist[v],v ));
						}
					}
					//Update the shortest cost path to v in dist map
					dist[v] = dist[u] + costUV;
					//Insert the node back into the SET with it's updated destance
					reachableSet.emplace(dist[v],v);
				}
			}
		}
		// Marking the visited[u] or visited flag of the node with the shortest cost path (u)  as true
		visited[u] = true;
	}

	// If the destination 'dst' is not reachable, it is still INT_MAX in the dist unordered map
	// So, output -1 if this is the case. Otherwise output the shortest cost path
	if(dist[dst] == INT_MAX){
		cout<<"Cost : "<<(-1)<<endl;
	}
	else{
		cout<<"Cost : "<<dist[dst]<<endl;
	}
	return;
}
