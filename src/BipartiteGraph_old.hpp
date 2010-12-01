#ifndef _BIPARTITEGRAPH_H
#define _BIPARTITEGRAPH_H
#include<iostream>
#include<conio.h>
#include<vector>
#include<map>
#include<algorithm>
#include"graph_traits_BG_old.hpp"

using namespace std;
namespace bipartite_old
{

template<class TypeOne, class TypeTwo>
class BipartiteGraph
{
//private:
	//typedef pair<TypeOne, vector<int>> type_one_vertex;
	//typedef pair<TypeTwo, vector<int>> type_two_vertex;
public:
	//vector<type_one_vertex> type_one_vertices;
	//vector<type_two_vertex> type_two_vertices;

	//vertex one descriptoe is simply the type of vertex one
	//vertex two descriptor is simply the type of vertex two
	typedef TypeOne vertex_type_one_descriptor;
	typedef TypeTwo vertex_type_two_descriptor;

	//Edges are differentiated based on source and destination
	//A type one edge is defined when source is of type one and destination is of type two
	//A type two edge is defined when source is of type two and destination is of type one
	typedef pair<TypeOne, TypeTwo> EdgeTypeOne; //type of Type one edge
	typedef pair<TypeTwo, TypeOne> EdgeTypeTwo; //type of Type two edge

	//Each edge descriptor is a pair type with source as its first type and destination as its second type
	typedef EdgeTypeOne edge_type_one_descriptor;
	typedef EdgeTypeTwo edge_type_two_descriptor;


	typedef map<TypeOne, vector<TypeTwo>> map_vertices_type_one;
	typedef map<TypeTwo, vector<TypeOne>> map_vertices_type_two;
	map_vertices_type_one vertices_type_one;
	map_vertices_type_two vertices_type_two;
};

//Adds a vertex of type one to bipartite graph.
template <class BpGraph>
bool
add_vertex_type_one(BpGraph &bpGraph, typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor key)
{
		typedef typename BpGraph::map_vertices_type_one     map_vertices_type_one;

		typedef vector<graph_traits_BG<BpGraph>::vertex_type_two_descriptor>     vec_two_type;
		
		typedef pair<typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor, vec_two_type> pair_to_insert;

		vec_two_type emptyVec;
		
		pair<map_vertices_type_one::iterator, bool> is_not_exist = 
									bpGraph.vertices_type_one.insert(pair_to_insert(key, emptyVec));
		return is_not_exist.second;
}

//Adds a vertex of type one to bipartite graph.
template <class BpGraph>
bool
add_vertex_type_two(BpGraph &bpGraph, typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor key)
{
		typedef typename BpGraph::map_vertices_type_two      map_vertices_type_two;

		typedef vector<graph_traits_BG<BpGraph>::vertex_type_one_descriptor>     vec_one_type;
		
		typedef pair<typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor, vec_one_type> pair_to_insert;

		vec_one_type emptyVec;
		
		pair<map_vertices_type_two::iterator, bool> is_not_exist = 
									bpGraph.vertices_type_two.insert(pair_to_insert(key, emptyVec));
		return is_not_exist.second;
}

template <class BpGraph>
bool
add_edge_type_one(BpGraph& bpGraph, 
				  typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor sourceVertex,
				  typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor destinationVertex)
{
	bool edge_doesnt_exists = false;
	typedef typename BpGraph::map_vertices_type_one map_vertices_type_one; //map type of vertices type one
	typedef typename BpGraph::map_vertices_type_two map_vertices_type_two; //map type of verices type two

	typedef graph_traits_BG<BpGraph>::vertex_type_one_descriptor sourceVertexType;
	typedef graph_traits_BG<BpGraph>::vertex_type_two_descriptor destinationVertexType;

	typedef vector<destinationVertexType> destinationVectorType;
	destinationVectorType destVector;
	destVector.push_back(destinationVertex);
	//check whether source exist or not in Vertex map of source type
	pair<map_vertices_type_one::iterator, bool> is_not_exist
			= bpGraph.vertices_type_one.insert(pair<sourceVertexType, destinationVectorType>(sourceVertex, destVector));
	if(!is_not_exist.second)
	{				
		//We are here means source exists, now we should check whether destination exists in adjacency list of source.
		destinationVectorType::iterator iter = find(bpGraph.vertices_type_one[sourceVertex].begin(),
													bpGraph.vertices_type_one[sourceVertex].end(),
													destinationVertex);
		//if condition below is true, means destination is not there in adjacency list of source. hence pushback destination
		if(iter == bpGraph.vertices_type_one[sourceVertex].end())
		{
			bpGraph.vertices_type_one[sourceVertex].push_back(destinationVertex);
			edge_doesnt_exists = true;
		}
	}
	else
		edge_doesnt_exists = true;

	//try to find destination vertex in type two vertices
	typedef vector<sourceVertexType> sourceVectorType;
	sourceVectorType srcvector;
	pair<map_vertices_type_two::iterator, bool> is_two_not_exist
			= bpGraph.vertices_type_two.insert(pair<destinationVertexType, sourceVectorType>(destinationVertex, srcvector));

	return edge_doesnt_exists;
}

template <class BpGraph>
bool
add_edge_type_two(BpGraph& bpGraph, 
				  typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor sourceVertex,
				  typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor destinationVertex)
{
	bool edge_doesnt_exists = false;
	typedef typename BpGraph::map_vertices_type_one map_vertices_type_one; //map type of vertices type one
	typedef typename BpGraph::map_vertices_type_two map_vertices_type_two; //map type of verices type two

	typedef graph_traits_BG<BpGraph>::vertex_type_two_descriptor sourceVertexType;
	typedef graph_traits_BG<BpGraph>::vertex_type_one_descriptor destinationVertexType;

	typedef vector<destinationVertexType> destinationVectorType;
	destinationVectorType destVector;
	destVector.push_back(destinationVertex);
	//check whether source exists or not in Vertex map of source type
	pair<map_vertices_type_two::iterator, bool> is_not_exist
			= bpGraph.vertices_type_two.insert(pair<sourceVertexType, destinationVectorType>(sourceVertex, destVector));
	if(!is_not_exist.second)
	{				
		//We are here means source exists, now we should check whether destination exists in adjacency list of source.
		destinationVectorType::iterator iter = find(bpGraph.vertices_type_two[sourceVertex].begin(),
													bpGraph.vertices_type_two[sourceVertex].end(),
													destinationVertex);
		//if condition below is true, means destination is not there in adjacency list of source. hence pushback destination
		if(iter == bpGraph.vertices_type_two[sourceVertex].end())
		{
			bpGraph.vertices_type_two[sourceVertex].push_back(destinationVertex);
			edge_doesnt_exists = true;
		}
	}
	else
		edge_doesnt_exists = true;

	//try to find destination vertex in type one vertices
	typedef vector<sourceVertexType> sourceVectorType;
	sourceVectorType srcvector;
	pair<map_vertices_type_one::iterator, bool> is_one_not_exist
			= bpGraph.vertices_type_one.insert(pair<destinationVertexType, sourceVectorType>(destinationVertex, srcvector));

	return edge_doesnt_exists;
}

}
 

#endif