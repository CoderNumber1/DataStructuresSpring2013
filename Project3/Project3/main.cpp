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
#include "RandomGen.h"
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void initializeGraph(istream& inputFile, Graph& graph){
	int numberOfVertices = 0;
	inputFile >> numberOfVertices;
	graph.setNumberVertices(numberOfVertices);

	for(;;){
		int one, two, weight;
		for(int i = 1; i <= 3; i++){
			if(i == 1)
				inputFile >> one;
			else if(i == 2)
				inputFile >> two;
			else if(i == 3)
				inputFile >> weight;
		}

		graph.addEdge(one, two, weight);
		one = two = weight = 0;

		if(inputFile.eof())
			break;
	}
}

void writeOutput(ostream& outputFile, Graph& graph, int source, string title, bool writeEachDistance, bool writeTotalDistance){
	outputFile << title << source << endl;

	for(int i = 1; i <= graph.getNumberOfVertices(); i++){
		if(i != source){
			stack<int> path;
			queue<int> from;
			from.push(i);
			while(!from.empty()){
				int step = from.front();
				from.pop();
				path.push(step);

				if(step != source)
					from.push(graph.verticePredecessor[step]);
			}

			while(!path.empty()){
				int step = path.top();
				path.pop();
				outputFile << step << " ";
			}

			if(writeEachDistance)
				outputFile << "Distance: " << graph.pathDistances[i];

			outputFile << endl;
		}
	}

	if(writeTotalDistance){
		int sum = 0;
		for(int i = 1; i <= graph.getNumberOfVertices(); i++){
			sum += graph.pathDistances[i];
		}

		outputFile << "Total Distance: " << sum << endl;
	}
}

int main(int argc, char* argv[]){
	Graph graph;
	ifstream inputFile("nsf.txt");
	ofstream outputFile("output.txt");

	if(!inputFile)
		int t = -1;

	initializeGraph(inputFile, graph);

	for(int i = 1; i <= graph.getNumberOfVertices(); i++){
		graph.analyzeShortestPathsWithDijkstra(i);
		writeOutput(outputFile, graph, i, "Writing shortest paths from ", true, false);
	}

	int randomTreeStart = RandomGen::GetInstance().GetRandom(2, graph.getNumberOfVertices() - 1);
	graph.analyzeMinimumSpanningTreeWithPrims(randomTreeStart);
	writeOutput(outputFile, graph, randomTreeStart, "Writing minimum spanning tree from ", false, true);

	graph.analyzeMinimumSpanningTreeWithPrims(1);
	writeOutput(outputFile, graph, 1, "Writing minimum spanning tree from ", false, true);

	graph.analyzeMinimumSpanningTreeWithPrims(graph.getNumberOfVertices());
	writeOutput(outputFile, graph, graph.getNumberOfVertices(), "Writing minimum spanning tree from ", false, true);

	inputFile.close();
	outputFile.close();
}