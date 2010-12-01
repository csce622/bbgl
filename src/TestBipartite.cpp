#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
//#include"BipartiteGraph_old.hpp"
//#include"graph_traits_BG_old.hpp"

#include "bipartite_graph.hpp"
#include "bpgraph_traits.hpp"
#include<string>

using namespace std;
using namespace bipartite_graph_space;
int main()
{
	//typedef BipartiteGraph<int, string> bpGraph;
	//bpGraph bp;
	////graph_traits_BG<bpGraph>::vertex_type_one_descriptor vertex;
	//cout<<"Adding Vertex Type One:"<<endl;
	//cout<<add_vertex_type_one(bp, 10)<<" ";
	//cout<<add_vertex_type_one(bp, 20)<<" ";
	//cout<<add_vertex_type_one(bp, 30)<<endl<<endl;

	//cout<<"Adding Vertex Type Two:"<<endl;
	//cout<<add_vertex_type_two(bp, "10s")<<" ";
	//cout<<add_vertex_type_two(bp, "20s")<<" ";
	//cout<<add_vertex_type_two(bp, "20s")<<endl<<endl;

	//cout<<"Adding Edge Type One"<<endl;
	//cout<<add_edge_type_one(bp, 10, "40s")<<" ";
	//cout<<add_edge_type_one(bp, 40, "40s")<<" ";
	//cout<<add_edge_type_one(bp, 40, "40s")<<" ";
	//cout<<add_edge_type_one(bp, 40, "50s")<<endl<<endl;

	//cout<<"Adding Edge Type Two"<<endl;
	//cout<<add_edge_type_two(bp, "50s", 40)<<" ";
	//cout<<add_edge_type_two(bp, "50s", 40)<<" ";
	//cout<<add_edge_type_two(bp, "60s", 50)<<endl<<endl;

	//cout<<endl<<"Vertices Type one and its adjacency list"<<endl;
	//map<int, vector<string>>::iterator vec_type_one_iter;
	//for(vec_type_one_iter = bp.vertices_type_one.begin(); vec_type_one_iter != bp.vertices_type_one.end(); vec_type_one_iter++)
	//{
	//	cout<<vec_type_one_iter->first<<" : ";
	//	vector<string>::iterator char_iter;
	//	for(char_iter = (vec_type_one_iter->second).begin(); char_iter != vec_type_one_iter->second.end(); char_iter++)
	//		cout<<*char_iter<<"\t";

	//	cout<<endl;
	//}

	//cout<<endl<<"Vertices Type two and its adjacency list"<<endl;
	//map<string, vector<int>>::iterator vec_type_two_iter;
	//for(vec_type_two_iter = bp.vertices_type_two.begin(); vec_type_two_iter != bp.vertices_type_two.end(); vec_type_two_iter++)
	//{
	//	cout<<vec_type_two_iter->first<<" : ";
	//	vector<int>::iterator int_iter;
	//	for(int_iter = (vec_type_two_iter->second).begin(); int_iter != vec_type_two_iter->second.end(); int_iter++)
	//		cout<<*int_iter<<"\t";
	//	cout<<endl;
	//}
	//class Hen
	//{
	//public:
	//	Hen(){};
	//	string hen;
	//	int i;
	//};

	//Hen h;
	//h.hen = "abc";
	//h.i = 222;
	//typedef bipartite_graph<Hen, string> graph_type;

	//graph_type g(2,3);

	//add_edge_type_one(1,2, g).second ;
	//add_edge_type_one(1,3, g).second ;
	//add_edge_type_one(1,4, g).second ;

	////adjacent_vertices_type_one(1,g);


	//typedef bpgraph_traits<graph_type>::vertex_type_one_iterator vertex_iter;
	//std::pair<vertex_iter, vertex_iter> vp;
	//for (vp = vertices_type_one(g); vp.first != vp.second; ++vp.first)
	//	std::cout <<  *vp.first <<  " ";
	//std::cout << std::endl;

	//typedef bpgraph_traits<graph_type>::vertex_type_two_iterator vertex_iter_1;
	//std::pair<vertex_iter_1, vertex_iter_1> vp_1;
	//for (vp_1 = vertices_type_two(g); vp_1.first != vp_1.second; ++vp_1.first)
	//	std::cout <<  *vp_1.first <<  " ";
	//std::cout << std::endl;

	//getch();


 enum vertices_type1_t { apple, banana, cherry, num_vertices_t1 };
  enum vertices_type2_t { dallas, elpaso, num_vertices_t2 };
  std::vector<std::string> name_vertices_type1;
  name_vertices_type1.push_back("apple");
  name_vertices_type1.push_back("banana");
  name_vertices_type1.push_back("cherry");
  std::vector<std::string> name_vertices_type2;
  name_vertices_type2.push_back("dallas");
  name_vertices_type2.push_back("elpaso");

  // create a typedef for the bipartite graph type
  typedef bipartite_graph<vertices_type1_t, vertices_type2_t> BipartiteGraph;

  typedef std::pair<vertices_type1_t, vertices_type2_t> edge_type1;
  edge_type1 edge_type1_array[]  = 
  { edge_type1(apple , dallas),
    edge_type1(apple , elpaso),
    edge_type1(banana, dallas),
    edge_type1(cherry, elpaso) };
  const int num_edges_t1 = sizeof(edge_type1_array)/sizeof(edge_type1_array[0]); 

  typedef std::pair<vertices_type2_t, vertices_type1_t> edge_type2;
  edge_type2 edge_type2_array[]  = 
  { edge_type2(dallas, apple ),
    edge_type2(elpaso, banana) };
  const int num_edges_t2 = sizeof(edge_type2_array)/sizeof(edge_type2_array[0]); 

  // declare a bipartite graph object
  BipartiteGraph g;

  // add the edges of type one to the bipartite graph object
  for (int i = 0; i < num_edges_t1; i++) 
    add_edge_type_one(edge_type1_array[i].first, edge_type1_array[i].second, g);

  // add the edges of type two
  for (int i = 0; i < num_edges_t2; i++) 
    add_edge_type_two(edge_type2_array[i].first,edge_type2_array[i].second , g);

  std::cout << "vertices of type one =  ";
  typedef bpgraph_traits<BipartiteGraph>::vertex_type_one_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter> vp;
	for (vp = vertices_type_one(g); vp.first != vp.second; ++vp.first)
    std::cout << name_vertices_type1[*vp.first] << "   ";
  std::cout << std::endl;
   std::cout << "vertices of type two =  ";
  typedef bpgraph_traits<BipartiteGraph>::vertex_type_two_iterator vertex_iter2;
	std::pair<vertex_iter2, vertex_iter2> vp2;
	for (vp2 = vertices_type_two(g); vp2.first != vp2.second; ++vp2.first)
    std::cout << name_vertices_type2[*vp2.first] << "   ";
  getch();
	return 0;
}