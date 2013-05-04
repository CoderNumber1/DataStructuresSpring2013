//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA3
//Due:			April 20, 2013
//Account		gp034
//----------------------------------------------------------------

#include "Graph.h"

using namespace std;

void Graph::addEdge(int verticeOne, int verticeTwo, int weight){
	this->vertices[verticeOne].push_back(Edge(verticeTwo, weight));
	this->vertices[verticeTwo].push_back(Edge(verticeOne, weight));
}

void Graph::setNumberVertices(int numberOfVertices){
	this->numberOfVertices = numberOfVertices;
}

int Graph::getNumberOfVertices(){
	return this->numberOfVertices;
}

void Graph::initializeSingleSource(int source){
	for(int i = 1; i <= this->numberOfVertices; i++){
		this->pathDistances[i] = -1;
		this->pathDiscovered[i] = false;
		this->verticePredecessor[i] = -1;
	}
	
	while(!this->discoveryQueue.empty()){
		this->discoveryQueue.pop();
	}

	this->pathDistances[source] = 0;
	this->verticePredecessor[source] = -1;
	this->discoveryQueue.push(Edge(source, 0));
}

void Graph::analyzeShortestPathsWithDijkstra(int source){
	this->initializeSingleSource(source);
	while(!this->discoveryQueue.empty()){
		int discoveryVertice = this->discoveryQueue.top().vertice;
		this->discoveryQueue.pop();

		if(this->pathDiscovered[discoveryVertice]) continue;
		int numberOfAdjacentVertices = this->vertices[discoveryVertice].size();

		for(int i=0; i < numberOfAdjacentVertices; i++) {
			int adjacentVertice = this->vertices[discoveryVertice][i].vertice;
			int weight = this->vertices[discoveryVertice][i].weight;
			if(!this->pathDiscovered[adjacentVertice] 
				&& (this->pathDistances[adjacentVertice] == -1
					|| this->pathDistances[discoveryVertice] + weight < this->pathDistances[adjacentVertice])) {
				this->pathDistances[adjacentVertice] = this->pathDistances[discoveryVertice] + weight;
				this->verticePredecessor[adjacentVertice] = discoveryVertice;
				this->discoveryQueue.push(Edge(adjacentVertice, this->pathDistances[adjacentVertice]));
			}
		}
		this->pathDiscovered[discoveryVertice] = true;
	}
}

void Graph::analyzeMinimumSpanningTreeWithPrims(int source){
	this->initializeSingleSource(source);
	while(!this->discoveryQueue.empty()){
		int discoveryVertice = this->discoveryQueue.top().vertice;
		this->discoveryQueue.pop();
		if(this->pathDiscovered[discoveryVertice]) continue;
		int numberOfAdjacentVertices = this->vertices[discoveryVertice].size();

		for(int i=0; i < numberOfAdjacentVertices; i++) {
			int adjacentVertice = this->vertices[discoveryVertice][i].vertice;
			int weight = this->vertices[discoveryVertice][i].weight;
			if(!this->pathDiscovered[adjacentVertice] 
				&& (this->pathDistances[adjacentVertice] == -1
					|| weight < this->pathDistances[adjacentVertice])) {
				this->pathDistances[adjacentVertice] = weight;
				this->verticePredecessor[adjacentVertice] = discoveryVertice;
				this->discoveryQueue.push(Edge(adjacentVertice, this->pathDistances[adjacentVertice]));
			}
		}
		this->pathDiscovered[discoveryVertice] = true;
	}
}