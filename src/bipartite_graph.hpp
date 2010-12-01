#ifndef _BIPARTITE_GRAPH_H
#define _BIPARTITE_GRAPH_H

#include<iostream>
#include<conio.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include <boost/pending/integer_range.hpp>
#include"bpgraph_traits.hpp"

using namespace std;
namespace bipartite_graph_space
{
	template <class Derived, class Config>
	class bipartite_impl
	{
		typedef typename Config::StoredVertexListOne   StoredVertexListOne;
		typedef typename Config::StoredVertexListTwo   StoredVertexListTwo;

		typedef typename Config::out_edge_list_type_one   out_edge_list_type_one;
		typedef typename Config::out_edge_list_type_two   out_edge_list_type_two;

		typedef typename Config::in_edge_list_type_one   in_edge_list_type_one;
		typedef typename Config::in_edge_list_type_two   in_edge_list_type_two;
	public:
		typedef typename Config::vertex_type_one_descriptor  vertex_type_one_descriptor;
		typedef typename Config::vertex_type_two_descriptor  vertex_type_two_descriptor;

		typedef typename Config::vertices_type_one_size   vertices_type_one_size;
		typedef typename Config::vertices_type_two_size   vertices_type_two_size;

		typedef typename Config::stored_vertex_type_one  stored_vertex_type_one;
		typedef typename Config::stored_vertex_type_two  stored_vertex_type_two;

		typedef typename Config::edge_type_one_descriptor   edge_type_one_descriptor;
		typedef typename Config::edge_type_two_descriptor   edge_type_two_descriptor;

	    typedef typename Config::edge_type_one_container   edge_type_one_container;
		typedef typename Config::edge_type_two_container   edge_type_two_container;

		typedef typename Config::edge_type_one_iterator edge_type_one_iterator;
		typedef typename Config::edge_type_two_iterator edge_type_two_iterator;

		typedef typename Config::vertex_type_one_iterator vertex_type_one_iterator;
		typedef typename Config::vertex_type_two_iterator vertex_type_two_iterator;

		typedef typename Config::adjacency_type_one_iterator	adjacency_type_one_iterator;
		typedef typename Config::adjacency_type_two_iterator	adjacency_type_two_iterator;

		//O(E) operation
		inline bool find_edge_type_one(typename edge_type_one_container::value_type e)
		{
			if(m_edges_one.size() == 0 )
				return false;
			edge_type_one_iterator i_begin = m_edges_one.begin();
			edge_type_one_iterator i_end = m_edges_one.end();

			if(i_end == find(i_begin, i_end, e))
				return false;
			return true;
		}

		//O(E) operation
		inline bool find_edge_type_two(typename edge_type_two_container::value_type e)
		{
			if(m_edges_two.size() == 0)
				return false;

			edge_type_one_iterator i_begin = m_edges_two.begin();
			edge_type_one_iterator i_end = m_edges_two.end();

			if(i_end == find(i_begin, i_end, e))
				return false;

			return true;
		}

		inline bipartite_impl(){};
		
		//initialized the size of two stored vertices with specific sizes
		inline bipartite_impl(vertices_type_one_size _num_vertices_one, vertices_type_two_size _num_vertices_two)
			: m_vertices_one(_num_vertices_one), m_vertices_two(_num_vertices_two) {}

		inline boost::integer_range<vertex_type_one_descriptor> vertex_set_one() const 
		{
			return boost::integer_range<vertex_type_one_descriptor>(0, m_vertices_one.size());
		}
		
		inline boost::integer_range<vertex_type_two_descriptor> vertex_set_two() const 
		{
			return boost::integer_range<vertex_type_two_descriptor>(0, m_vertices_two.size());
		}

		//funtion to return out edge list one, which is of type vector<vertex_type_two_descriptor>
		inline out_edge_list_type_one& out_edge_type_one_list(vertex_type_one_descriptor v) 
		{
			return m_vertices_one[v].m_out_edges;
		}

		//funtion to return in edge list one, which is of type vector<vertex_type_two_descriptor>
		inline in_edge_list_type_one& in_edge_type_one_list(vertex_type_one_descriptor v) 
		{
			return m_vertices_one[v].m_in_edges;
		}

		//funtion to return out edge list two, which is of type vector<vertex_type_one_descriptor>
		inline out_edge_list_type_two& out_edge_type_two_list(vertex_type_two_descriptor v) 
		{
			return m_vertices_two[v].m_out_edges;
		}

		//funtion to return in edge list two, which is of type vector<vertex_type_one_descriptor>
		inline in_edge_list_type_two& in_edge_type_two_list(vertex_type_two_descriptor v) 
		{
			return m_vertices_two[v].m_in_edges;
		}

		//Edge container to contain edges
		typename Config::edge_type_one_container m_edges_one;
		typename Config::edge_type_two_container m_edges_two;

		//vector container to contain two different types of nodes
		StoredVertexListOne m_vertices_one;
		StoredVertexListTwo m_vertices_two;
	};


	//template <class Graph, class Config>
 //   inline std::pair<typename Config::adjacency_type_one_iterator,
 //                    typename Config::adjacency_type_one_iterator>
 //   adjacent_vertices_type_one(typename Config::vertex_type_one_descriptor u,
 //                     const bipartite_impl<Graph, Config>& g_)
 //   {
 //     const Graph& g = static_cast<const Graph&>(g_);
 //     typedef typename Config::adjacency_type_one_iterator adjacency_iterator;
	//  typename Config::out_edge_list_type_one  = 
	//  adjacency_iterator iter = g.out_edge_type_one_list(u).begin();
	//  //cout<<"First Element: "<< *iter;
 //     //typename Config::out_edge_iterator first, last;
 //     //boost::tie(first, last) = out_edges(u, g);
 //     //return std::make_pair(adjacency_iterator(first, &g),
 //     //                      adjacency_iterator(last, &g));

	//  std::pair<typename Config::adjacency_type_one_iterator,
 //                    typename Config::adjacency_type_one_iterator> a;
	//  return a;
 //   }


	//Returns all the vertices of type one in the graph
	template <class Graph, class Config>
    inline std::pair<typename Config::vertex_type_one_iterator,
                     typename Config::vertex_type_one_iterator>
    vertices_type_one(const bipartite_impl<Graph, Config>& g_)
    {
	  const Graph& g = static_cast<const Graph&>(g_);
      return std::make_pair( g.vertex_set_one().begin(), g.vertex_set_one().end() );
    }


	template <class Graph, class Config>
    inline std::pair<typename Config::vertex_type_two_iterator,
                     typename Config::vertex_type_two_iterator>
    vertices_type_two(const bipartite_impl<Graph, Config>& g_)
    {
	  const Graph& g = static_cast<const Graph&>(g_);
      return std::make_pair( g.vertex_set_two().begin(), g.vertex_set_two().end() );
    }

	//Implementation of add_vertex_one
	//Simply increase the size of vector<stored_vertex_one> by one.
	template<class Graph, class Config>
	inline typename Config::vertex_type_one_descriptor
	add_vertex_type_one(bipartite_impl<Graph, Config>& g_)
	{
		Graph& g = static_cast<Graph&>(g_);
		g.m_vertices_one.resize(g.m_vertices_one.size()+1);
		return g.m_vertices_one.size() - 1;
	}

	//Implementation of add_vertex_two
	//Simply increase the size of vector<stored_vertex_two> by one.
	template<class Graph, class Config>
	inline typename Config::vertex_type_two_descriptor
	add_vertex_type_two(bipartite_impl<Graph, Config>& g_)
	{
		Graph& g = static_cast<Graph&>(g_);
		g.m_vertices_two.resize(g.m_vertices_two.size()+1);
		return g.m_vertices_two.size() - 1;
	}

	/*==============================================================
	 *Overloaded function to add vetex of type one, which takes 
	 *stored type object too
	 *=============================================================*/
	template <class Graph, class Config>
	inline typename Config::vertex_type_one_descriptor
	add_vertex_type_one(const typename Config::vertex_type_one& inside_vertex,
						bipartite_impl<Graph, Config>& g_)
	{
		typedef typename Config::vertex_type_one_descriptor vertex_type_one_descriptor;
		Graph& g = static_cast<Graph&>(g_);
		typedef typename Config::stored_vertex_type_one stored_vertex_type_one;
		g.m_vertices_one.push_back(stored_vertex_type_one(inside_vertex));
		return g.m_vertices_one.size() - 1;
	}


	/*==============================================================
	 *Overloaded function to add vetex of type two, which takes 
	 *stored type object too
	 *=============================================================*/
	template <class Graph, class Config>
	inline typename Config::vertex_type_two_descriptor
	add_vertex_type_two(const typename Config::vertex_type_two& inside_vertex,
						bipartite_impl<Graph, Config>& g_)
	{
		typedef typename Config::vertex_type_two_descriptor vertex_type_two_descriptor;
		Graph& g = static_cast<Graph&>(g_);
		typedef typename Config::stored_vertex_type_two stored_vertex_type_two;
		g.m_vertices_two.push_back(stored_vertex_type_two(inside_vertex));
		return g.m_vertices_two.size() - 1;
	}
	
	template <class Graph, class Config>
    inline typename Config::vertices_type_one_size
    num_vertices_type_one(const bipartite_impl<Graph, Config>& g_)
    { 
      const Graph& g = static_cast<const Graph&>(g_);
      return g.m_vertices_one.size();
    }

	template <class Graph, class Config>
    inline typename Config::vertices_type_two_size
    num_vertices_type_two(const bipartite_impl<Graph, Config>& g_)
    { 
      const Graph& g = static_cast<const Graph&>(g_);
      return g.m_vertices_two.size();
    }

	template <class Graph, class Config>
	inline std::pair<typename Config::edge_type_one_descriptor, bool>
	add_edge_type_one(typename Config::vertex_type_one_descriptor source, typename Config::vertex_type_two_descriptor target,
						bipartite_impl<Graph, Config>& g_)
	{

		typedef typename Config::edge_type_one_descriptor edge_type_one_descriptor;

		typename Config::vertices_type_one_size size_one
														= num_vertices_type_one(g_);
		typename Config::vertices_type_two_size size_two
														= num_vertices_type_two(g_);
		
		Graph& g = static_cast<Graph&>(g_);
		
		if(source >= size_one)
		{
			g.m_vertices_one.resize(source + 1);
		}
		if(target >= size_two)
		{
			g.m_vertices_two.resize(target + 1);
		}

		typename Config::edge_type_one_container::value_type out_e(source, target);
		typename Config::edge_type_two_container::value_type in_e(target, source);

		typedef typename Config::out_edge_list_type_one::iterator EdgeIterType;
		typedef pair<EdgeIterType, bool> ReturnType;
		ReturnType ret = g.out_edge_type_one_list(source).insert(target);
		if(ret.second) //If insert is successfull
		{
			g.m_edges_one.push_back(out_e);
			g.m_edges_two.push_back(in_e);
			g.in_edge_type_two_list(target).insert(source);
			return make_pair(edge_type_one_descriptor(source, target), true);
		}
		else
		{
			return make_pair(edge_type_one_descriptor(source, target), false);
		}


		//If any of above if is true the insert for sure
		/* This code is not used
		 * Implemeted while considering outedgelist as vector
		 * but now it is type set
		 if(!is_edge_present)
		{
			//in this case we should create a new edge pointing from source to target
			//it means push one in out edge list of source and one in in edge list of target
			g.m_edges_one.push_back(out_e);
			g.m_edges_two.push_back(in_e);
			g.out_edge_type_one_list(source).push_back(target);
			g.in_edge_type_two_list(target).push_back(source);
			return make_pair(edge_type_one_descriptor(source, target), true);
		}
		else
		{
			//We do not need to perform any modification on graph structure
			return make_pair(edge_type_one_descriptor(source, target), false);
		}
		*/
	}


	template <class Graph, class Config>
	inline std::pair<typename Config::edge_type_two_descriptor, bool>
	add_edge_type_two(typename Config::vertex_type_two_descriptor source, typename Config::vertex_type_one_descriptor target,
						bipartite_impl<Graph, Config>& g_)
	{

		typedef typename Config::edge_type_two_descriptor edge_type_two_descriptor;

		typename Config::vertices_type_two_size size_two
														= num_vertices_type_two(g_);
		typename Config::vertices_type_one_size size_one
														= num_vertices_type_one(g_);
		
		Graph& g = static_cast<Graph&>(g_);
		
		if(source >= size_two)
		{
			g.m_vertices_two.resize(source + 1);
		}
		if(target >= size_one)
		{
			g.m_vertices_one.resize(target + 1);
		}

		typename Config::edge_type_two_container::value_type out_e(source, target);
		typename Config::edge_type_one_container::value_type in_e(target, source);

		typedef typename Config::out_edge_list_type_two::iterator EdgeIterType;
		typedef pair<EdgeIterType, bool> ReturnType;
		ReturnType ret = g.out_edge_type_two_list(source).insert(target);
		if(ret.second) //If insert is successfull
		{
			g.m_edges_two.push_back(out_e);
			g.m_edges_one.push_back(in_e);
			g.in_edge_type_one_list(target).insert(source);
			return make_pair(edge_type_two_descriptor(source, target), true);
		}
		else
		{
			return make_pair(edge_type_two_descriptor(source, target), false);
		}

		/* OBSELETE CODE
		//If an edge exists it must be there in in_edge_container as well as out_edge_container
		bool is_edge_present = g.find_edge_type_two(out_e);
		//Note: If out edge information is not present it means in edge information should
		//not be present or else information for the graph will not remain consistent

		//If any of above if is true the insert for sure
		if(!is_edge_present)
		{
			//in this case we should create a new edge pointing from source to target
			//it means push one in out edge list of source and one in in edge list of target
			g.m_edges_two.push_back(out_e);
			g.m_edges_onw.push_back(in_e);
			g.out_edge_type_two_list(source).push_back(target);
			g.in_edge_type_one_list(target).push_back(source);
			return make_pair(edge_type_two_descriptor(source, target), true);
		}
		else
		{
			//We do not need to perform any modification on graph structure
			return make_pair(edge_type_two_descriptor(source, target), false);
		}
		*/
	}

	namespace details
	{

		template <class Vertex1, class Vertex2>
		class edge_base
		{
		public:
			inline edge_base(){}
			inline edge_base(Vertex1 msrc, Vertex2 mtarg)
				:m_source(msrc), m_target(mtarg){}
			Vertex1 m_source;
			Vertex2 m_target; 
	    };

		//Overloading operator for edgebase
		template <class V1, class V2>
		inline bool
		operator==(const edge_base<V1,V2>& a, 
               const edge_base<V1,V2>& b)
		{
			return (a.m_source == b.m_source && a.m_target == b.m_target);
		}
		
		template<class graphtype, class type_one, class type_two>
		class bipartite_gen
		{
			struct config
			{
				typedef graphtype	graph_type;
				
				typedef type_one	vertex_type_one;
				typedef type_two	vertex_type_two;
				
				typedef std::size_t		vertices_type_one_size;
				typedef std::size_t		vertices_type_two_size;
				
				typedef vertices_type_one_size	vertex_type_one_descriptor;
				typedef vertices_type_two_size	vertex_type_two_descriptor;

				typedef boost::integer_range<vertex_type_one_descriptor> RandVertexListOne;
				typedef boost::integer_range<vertex_type_two_descriptor> RandVertexListTwo;

				typedef typename RandVertexListOne::iterator vertex_type_one_iterator;
				typedef typename RandVertexListTwo::iterator vertex_type_two_iterator;

				typedef edge_base<vertex_type_one_descriptor, vertex_type_two_descriptor> edge_type_one_descriptor;
				typedef edge_base<vertex_type_two_descriptor, vertex_type_one_descriptor> edge_type_two_descriptor;

				typedef list<edge_type_one_descriptor> edge_type_one_container; 
				typedef list<edge_type_two_descriptor> edge_type_two_container; 

				typedef typename edge_type_one_container::iterator   edge_type_one_iterator;
				typedef typename edge_type_two_container::iterator   edge_type_two_iterator;


				//typedef vertex_descriptor_type_two stored_edge_one;    //In bipartite graph each stored edge one (adjacency list of type one) should contain vertices of type two
				//typedef vertex_descriptor_type_one stored_edge_two;    //In bipartite graph each stored edge two (adjacency list of type two) should contain vertices of type one
				
				typedef set<vertex_type_two_descriptor> out_edge_list_type_one;  //adjacency lists - defined as vector type as of nows
				typedef set<vertex_type_two_descriptor> in_edge_list_type_one;
				typedef set<vertex_type_one_descriptor> out_edge_list_type_two;
				typedef set<vertex_type_one_descriptor> in_edge_list_type_two;

				typedef typename out_edge_list_type_one::size_type   degree_size_type_one;
				typedef typename out_edge_list_type_two::size_type   degree_size_type_two;

				typedef typename out_edge_list_type_one::iterator   adjacency_type_one_iterator;
				typedef typename out_edge_list_type_two::iterator   adjacency_type_two_iterator;

				/*====================================================
				 * Structure defined for each vertex in to be stored as 
				 * parent in the adjacency list representation. Each node
				 * one out edge list( a vector to store out adjacent vectors),
				 * one in edge list( a vector to store in adjacent vectors)
				 * and a stored object o type one
				 *===================================================*/
				struct stored_vertex_type_one  // Equivalent to "struct bidir_rand_stored_vertex" in BGL , combined the "stored_vertex" 
										  // and "StoredVertex" (a typedef of "struct bidir_rand_stored_vertex" in BGL)
				{
					//default constructor
					stored_vertex_type_one():m_vertex_inside() {};

					//constructor which takes a type to store at each vertex
					stored_vertex_type_one(const vertex_type_one& vertex):m_vertex_inside(vertex) {cout<<vertex.hen<<"mmmm"<<vertex.i;};

					out_edge_list_type_one	 m_out_edges;  // all the out vertices in this edge list, should be of type vertex_desriptor_two
					in_edge_list_type_one    m_in_edges;   // all the in vertices in this edge list, should be of type vertex_desriptor_two
					vertex_type_one m_vertex_inside;
				};

				/*===================================================
				 *Similar to stored_vertex_type_one
				 *==================================================*/

				struct stored_vertex_type_two   //Similar comments as of stored_vertex_one
				{
					stored_vertex_type_two():m_vertex_inside() {};
					stored_vertex_type_two(const vertex_type_two& vertex):m_vertex_inside(vertex) {};
					out_edge_list_type_two	 m_out_edges;
					in_edge_list_type_two    m_in_edges;
					vertex_type_two m_vertex_inside;
				};

				//typedef stored_vertex_one stored_vertex_one;
				//typedef stored_vertex_two stored_vertex_two;

				typedef vector<stored_vertex_type_one> StoredVertexListOne;
				typedef vector<stored_vertex_type_two> StoredVertexListTwo;
				
			};
		public:
			typedef bipartite_impl<graphtype, config> type;
		};

	}

template< class type_one, class type_two>
class bipartite_graph : 
	public details::bipartite_gen<bipartite_graph<type_one, type_two>, type_one, type_two>::type
{
public:
	typedef type_one vertex_type_one;
	typedef type_two vertex_type_two;
private:
	typedef bipartite_graph self; //self type
	typedef typename details::bipartite_gen<
											self,
											vertex_type_one, //instead of using BGL property<tag_type, value_type> we use only value_type
											vertex_type_two
											>::type Base;    //typenamed the base type, bipartite_impl 

public:
	typedef typename Base::vertex_type_one_descriptor   vertex_type_one_descriptor;
	typedef typename Base::vertex_type_two_descriptor   vertex_type_two_descriptor;

	typedef typename Base::vertices_type_one_size   vertices_type_one_size;
	typedef typename Base::vertices_type_two_size   vertices_type_two_size;

	typedef typename Base::stored_vertex_type_one   stored_vertex_type_one;
	typedef typename Base::stored_vertex_type_one   stored_vertex_type_one;

	typedef typename Base::edge_type_one_descriptor edge_type_one_descriptor;
	typedef typename Base::edge_type_two_descriptor edge_type_two_descriptor;

	inline bipartite_graph(){}

	inline bipartite_graph(vertices_type_one_size num_vertices_one,
						   vertices_type_two_size num_vertices_two)
		   :Base(num_vertices_one, num_vertices_two){}
};
}
#endif

//template<class TypeOne, class TypeTwo>
//class BipartiteGraphp
//{
//
//public:
//
//	typedef TypeOne vertex_type_one_descriptor;
//	typedef TypeTwo vertex_type_two_descriptor;
//
//	//Edges are differentiated based on source and destination
//	//A type one edge is defined when source is of type one and destination is of type two
//	//A type two edge is defined when source is of type two and destination is of type one
//	typedef pair<TypeOne, TypeTwo> EdgeTypeOne; //type of Type one edge
//	typedef pair<TypeTwo, TypeOne> EdgeTypeTwo; //type of Type two edge
//
//	//Each edge descriptor is a pair type with source as its first type and destination as its second type
//	typedef EdgeTypeOne edge_type_one_descriptor;
//	typedef EdgeTypeTwo edge_type_two_descriptor;
//
//	vector<vector<int>> 
//
//	typedef map<int, > map_vertices_type_one;
//	typedef map<TypeTwo, vector<TypeOne>> map_vertices_type_two;
//	map_vertices_type_one vertices_type_one;
//	map_vertices_type_two vertices_type_two;
//};

//Adds a vertex of type one to bipartite graph.

//
//template <class BpGraph>
//bool
//add_vertex_type_one(BpGraph &bpGraph, typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor key)
//{
//		typedef typename BpGraph::map_vertices_type_one     map_vertices_type_one;
//
//		typedef vector<graph_traits_BG<BpGraph>::vertex_type_two_descriptor>     vec_two_type;
//		
//		typedef pair<typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor, vec_two_type> pair_to_insert;
//
//		vec_two_type emptyVec;
//		
//		pair<map_vertices_type_one::iterator, bool> is_not_exist = 
//									bpGraph.vertices_type_one.insert(pair_to_insert(key, emptyVec));
//		return is_not_exist.second;
//}
//
////Adds a vertex of type one to bipartite graph.
//template <class BpGraph>
//bool
//add_vertex_type_two(BpGraph &bpGraph, typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor key)
//{
//		typedef typename BpGraph::map_vertices_type_two      map_vertices_type_two;
//
//		typedef vector<graph_traits_BG<BpGraph>::vertex_type_one_descriptor>     vec_one_type;
//		
//		typedef pair<typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor, vec_one_type> pair_to_insert;
//
//		vec_one_type emptyVec;
//		
//		pair<map_vertices_type_two::iterator, bool> is_not_exist = 
//									bpGraph.vertices_type_two.insert(pair_to_insert(key, emptyVec));
//		return is_not_exist.second;
//}
//
//template <class BpGraph>
//bool
//add_edge_type_one(BpGraph& bpGraph, 
//				  typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor sourceVertex,
//				  typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor destinationVertex)
//{
//	bool edge_doesnt_exists = false;
//	typedef typename BpGraph::map_vertices_type_one map_vertices_type_one; //map type of vertices type one
//	typedef typename BpGraph::map_vertices_type_two map_vertices_type_two; //map type of verices type two
//
//	typedef graph_traits_BG<BpGraph>::vertex_type_one_descriptor sourceVertexType;
//	typedef graph_traits_BG<BpGraph>::vertex_type_two_descriptor destinationVertexType;
//
//	typedef vector<destinationVertexType> destinationVectorType;
//	destinationVectorType destVector;
//	destVector.push_back(destinationVertex);
//	//check whether source exist or not in Vertex map of source type
//	pair<map_vertices_type_one::iterator, bool> is_not_exist
//			= bpGraph.vertices_type_one.insert(pair<sourceVertexType, destinationVectorType>(sourceVertex, destVector));
//	if(!is_not_exist.second)
//	{				
//		//We are here means source exists, now we should check whether destination exists in adjacency list of source.
//		destinationVectorType::iterator iter = find(bpGraph.vertices_type_one[sourceVertex].begin(),
//													bpGraph.vertices_type_one[sourceVertex].end(),
//													destinationVertex);
//		//if condition below is true, means destination is not there in adjacency list of source. hence pushback destination
//		if(iter == bpGraph.vertices_type_one[sourceVertex].end())
//		{
//			bpGraph.vertices_type_one[sourceVertex].push_back(destinationVertex);
//			edge_doesnt_exists = true;
//		}
//	}
//	else
//		edge_doesnt_exists = true;
//
//	//try to find destination vertex in type two vertices
//	typedef vector<sourceVertexType> sourceVectorType;
//	sourceVectorType srcvector;
//	pair<map_vertices_type_two::iterator, bool> is_two_not_exist
//			= bpGraph.vertices_type_two.insert(pair<destinationVertexType, sourceVectorType>(destinationVertex, srcvector));
//
//	return edge_doesnt_exists;
//}
//
//template <class BpGraph>
//bool
//add_edge_type_two(BpGraph& bpGraph, 
//				  typename graph_traits_BG<BpGraph>::vertex_type_two_descriptor sourceVertex,
//				  typename graph_traits_BG<BpGraph>::vertex_type_one_descriptor destinationVertex)
//{
//	bool edge_doesnt_exists = false;
//	typedef typename BpGraph::map_vertices_type_one map_vertices_type_one; //map type of vertices type one
//	typedef typename BpGraph::map_vertices_type_two map_vertices_type_two; //map type of verices type two
//
//	typedef graph_traits_BG<BpGraph>::vertex_type_two_descriptor sourceVertexType;
//	typedef graph_traits_BG<BpGraph>::vertex_type_one_descriptor destinationVertexType;
//
//	typedef vector<destinationVertexType> destinationVectorType;
//	destinationVectorType destVector;
//	destVector.push_back(destinationVertex);
//	//check whether source exists or not in Vertex map of source type
//	pair<map_vertices_type_two::iterator, bool> is_not_exist
//			= bpGraph.vertices_type_two.insert(pair<sourceVertexType, destinationVectorType>(sourceVertex, destVector));
//	if(!is_not_exist.second)
//	{				
//		//We are here means source exists, now we should check whether destination exists in adjacency list of source.
//		destinationVectorType::iterator iter = find(bpGraph.vertices_type_two[sourceVertex].begin(),
//													bpGraph.vertices_type_two[sourceVertex].end(),
//													destinationVertex);
//		//if condition below is true, means destination is not there in adjacency list of source. hence pushback destination
//		if(iter == bpGraph.vertices_type_two[sourceVertex].end())
//		{
//			bpGraph.vertices_type_two[sourceVertex].push_back(destinationVertex);
//			edge_doesnt_exists = true;
//		}
//	}
//	else
//		edge_doesnt_exists = true;
//
//	//try to find destination vertex in type one vertices
//	typedef vector<sourceVertexType> sourceVectorType;
//	sourceVectorType srcvector;
//	pair<map_vertices_type_one::iterator, bool> is_one_not_exist
//			= bpGraph.vertices_type_one.insert(pair<destinationVertexType, sourceVectorType>(destinationVertex, srcvector));
//
//	return edge_doesnt_exists;
//}
//
//}
// 
//
//#endif