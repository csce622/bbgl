#ifndef _BPTRAITS_H
#define _BPTRAITS_H

using namespace std;

namespace bipartite_graph_space
{
	template <class BGraph>
	struct bpgraph_traits
	{
		typedef typename BGraph::vertices_type_one_size			vertices_type_one_size;
		typedef typename BGraph::vertices_type_two_size			vertices_type_two_size;

		typedef typename BGraph::vertex_type_one_descriptor		vertex_type_one_descriptor;
		typedef typename BGraph::vertex_type_two_descriptor		vertex_type_two_descriptor;

		typedef typename BGraph::edge_type_one_descriptor		edge_type_one_descriptor;
		typedef typename BGraph::edge_type_two_descriptor		edge_type_two_descriptor;

		typedef typename BGraph::vertex_type_one_iterator		vertex_type_one_iterator;
		typedef typename BGraph::vertex_type_two_iterator		vertex_type_two_iterator;

		typedef typename BGraph::adjacency_type_one_iterator    adjacency_type_one_iterator;
		typedef typename BGraph::adjacency_type_two_iterator    adjacency_type_two_iterator;

		typedef typename BGraph::edge_type_one_iterator			edge_type_one_iterator;
		typedef typename BGraph::edge_type_two_iterator			edge_type_two_iterator;
	};
}

#endif