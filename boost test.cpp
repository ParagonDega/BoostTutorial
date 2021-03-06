// boost test.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/undirected_graph.hpp>

using namespace std;
using namespace boost;

int main()
{

	//typedef boost::adjacency_list<listS, vecS, undirectedS> mygraph; //undirected
	//typedef boost::adjacency_list<listS, vecS, directedS> mygraph;  //directed
	typedef boost::adjacency_list<listS, vecS, bidirectionalS> mygraph; //bidirectional

	mygraph g;
	add_edge(0, 1, g);
	add_edge(0, 3, g);
	add_edge(1, 2, g);
	add_edge(2, 3, g);
	mygraph::vertex_iterator vertexIt, vertexEnd;
	mygraph::in_edge_iterator inedgeIt, inedgeEnd;
	mygraph::in_edge_iterator outedgeIt, outedgeEnd; 
	tie(vertexIt, vertexEnd) = vertices(g);
	for (; vertexIt != vertexEnd; ++vertexIt)
	{
		cout << "incoming edges for " << *vertexIt << ": ";
	tie(inedgeIt, inedgeEnd) = in_edges(*vertexIt, g);
		for (; inedgeIt != inedgeEnd; ++inedgeIt)
		{
			cout << *inedgeIt << " ";
		}
		cout << "\n";
	}
	for (; vertexIt != vertexEnd; ++vertexIt)
	{
		std::cout << "out-edges for " << *vertexIt << ": ";
		tie(outedgeIt, outedgeEnd) = out_edges(*vertexIt, g); //  Similar to incoming edges 
	}
}

//int main()
//{
//	//typedef boost::adjacency_list<listS, vecS, undirectedS> mygraph; //undirected
//	//typedef boost::adjacency_list<listS, vecS, directedS> mygraph;  //directed
//	typedef boost::adjacency_list<listS, vecS, bidirectionalS> mygraph; //undirected
//	
//	mygraph g;
//	add_edge(0, 1, 8, g);
//	add_edge(0, 3, 18, g);
//	add_edge(1, 2, 20, g);
//	add_edge(2, 3, 2, g);
//	add_edge(3, 1, 1, g);
//	add_edge(1, 3, 7, g);
//	cout << "Number of edges: " << num_edges(g) << "\n";
//	cout << "Number of vertices: " << num_vertices(g) << "\n";
//	mygraph::vertex_iterator vertexIt, vertexEnd; tie(vertexIt, vertexEnd) = vertices(g);
//	for (; vertexIt != vertexEnd; ++vertexIt)
//	{
//		std::cout << "in-degree for " << *vertexIt << ": "
//			<< in_degree(*vertexIt, g) << "\n";
//		std::cout << "out-degree for " << *vertexIt << ": "
//			<< out_degree(*vertexIt, g) << "\n";
//	}
//	mygraph::edge_iterator edgeIt,
//		edgeEnd; tie(edgeIt, edgeEnd) = edges(g);
//	for (; edgeIt != edgeEnd; ++edgeIt)
//	{
//		std::cout << "edge " << source(*edgeIt, g) << "-->"
//			<< target(*edgeIt, g) << "\n";
//	}
//} 