#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>

class Graph {

public:
	Graph::Graph(int vertices)
	{
		adjacents = new std::vector<int>[vertices];
		this->vertices = vertices;
	
	}

	Graph::~Graph()
	{
		delete[] adjacents;

	}


	void Graph::addEdge(int x, int y)
	{

		adjacents[x].push_back(y);
	}

	bool Graph::hasRoute(int x, int y);


private:
	std::vector<int> *adjacents;
	int vertices;


};


bool Graph::hasRoute(int x, int y)
{
	std::queue<int> q;
	q.push(x);
	std::vector<int> visited(vertices);

	while (!q.empty())
	{
		int current = q.front();
		if (current == y) {
			return true;
		}

		visited[current] = 1;

		q.pop();

		for (uint32_t i = 0; i < adjacents[current].size(); i++) {
			if (!visited[adjacents[current][i]]) {
				q.push(adjacents[current][i]);
			}

		}
	}
	return false;
}

int testhasRoute()
{
	Graph g(7);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(1,6);
	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(3,4);
	g.addEdge(2,1);
	bool result = g.hasRoute(5, 1);
	bool result2 = g.hasRoute(1, 2);
	std::cout << "result: " << result << "\n";
	std::cout << "result2: " << result2 << "\n";
	return 0;
}