//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA3
//Due:			April 20, 2013
//Account		gp034
//----------------------------------------------------------------

using namespace std;

#include <vector>
#include <queue>
#include <hash_map>

struct Vertice{
public:
	int id;
	int distance;
	int predecessorId;
};

struct Edge{
public:
	int vertice;
	int weight;
	Edge(int vertice, int weight){
		this->vertice = vertice;
		this->weight = weight;
	}
};

struct EdgeComparer{
	bool operator() (const Edge &a, const Edge &b) {
		return a.weight > b.weight;
	}
};

struct SpanComparer{
	bool operator()(const int &a, const int &b){
		return a > b;
	}
};

class Graph{
public:
	static const int MAX_VERTICE = 15;
	
	int numberOfVertices;
	priority_queue<Edge, vector<Edge>, EdgeComparer> discoveryQueue;
	vector<Edge> vertices[MAX_VERTICE];
	int pathDistances[MAX_VERTICE];
	int verticePredecessor[MAX_VERTICE];
	bool pathDiscovered[MAX_VERTICE];

	void setNumberVertices(int numberOfVertices);
	int getNumberOfVertices();
	void addEdge(int verticeOne, int verticeTwo, int weight);
	void initializeSingleSource(int source);
	void analyzeShortestPathsWithDijkstra(int source);
	void analyzeMinimumSpanningTreeWithPrims(int source);
};