#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>



class Graph{
private:
	std::unordered_map<std::string,std::unordered_set<std::string>> adjList;

public:
	Graph(){

	}

	bool addVertex(std::string str){
		if(adjList.count(str)!=0)
			return false;

		adjList[str];

		return true;
	}

	bool addEdge(std::string vert1, std::string vert2){

		if(adjList.count(vert1) == 0 ||
				adjList.count(vert2) == 0)
			return false;

		adjList[vert1].insert(vert2);
		adjList[vert2].insert(vert1);

		return true;
	}

	bool removeEdge(std::string vert1, std::string vert2){
		if(adjList.count(vert1) == 0 ||
				adjList.count(vert2) == 0)
			return false;

		adjList[vert1].erase(vert2);
		adjList[vert2].erase(vert1);

		return true;
	}

	bool removeVertex (std::string vert){
		if(adjList.count(vert) == 0)
			return false;

		for(auto &otherVertex: adjList[vert]){
			adjList[otherVertex].erase(vert);
		}

		adjList.erase(vert);

		return true;
	}

	void Print(){
		for(auto const &ver:adjList){
			std::cout<<ver.first<<": [";
			for(auto const &edge:ver.second){
				std::cout<<edge<<" ";
			}
			std::cout<<"]\n";
		}
	}

};


int main(){

	Graph newGraph;

	newGraph.addVertex("Renzo");
	newGraph.addVertex("Marcia");

	newGraph.addEdge("Renzo","Marcia");

	newGraph.Print();

	//newGraph.removeEdge("Marcia","Renzo");
	newGraph.removeVertex("Renzo");

	newGraph.Print();

	return 0;
}
