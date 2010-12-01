#ifndef _GRAPH_TRAITS_BG_H
#define _GRAPH_TRAITS_BG_H
using namespace std;

namespace bipartite_old
{
	template <class BGraph>
	struct graph_traits_BG
	{
		typedef typename BGraph::vertex_type_one_descriptor vertex_type_one_descriptor;
		typedef typename BGraph::vertex_type_two_descriptor vertex_type_two_descriptor;
		typedef typename BGraph::edge_type_one_descriptor edge_type_one_descriptor;
		typedef typename BGraph::edge_type_two_descriptor edge_type_two_descriptor;
	};
}

#endif