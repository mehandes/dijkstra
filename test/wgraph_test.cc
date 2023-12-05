extern "C" {
#include <wgraph.h>
}

#include <gtest/gtest.h>

TEST(WGraphTest, Initialize) {
  wgraph graph = wgraph_init(5);
  EXPECT_EQ(-1.0, graph->adj_[0][0]);
  wgraph_free(graph);
}

TEST(WGraphTest, SetEdge) {
  wgraph graph = wgraph_init(5);
  res_t res = wgraph_set_edge(graph, 0, 1, 20.1);

  EXPECT_EQ(20.1, graph->adj_[0][1]);
  EXPECT_EQ(0, res);

  wgraph_free(graph);
}

TEST(WGraphTest, SetEdgeOutOfRange) {
  wgraph graph = wgraph_init(5);
  res_t res = wgraph_set_edge(graph, 5, 3, 10);

  EXPECT_EQ(1, res);

  wgraph_free(graph);
}

TEST(WGraphTest, GetEdges) {
  wgraph graph = wgraph_init(5);
  wgraph_set_edge(graph, 0, 1, 2.1);
  wgraph_set_edge(graph, 0, 2, 2.2);
  wgraph_set_edge(graph, 0, 3, 2.3);
  wgraph_set_edge(graph, 0, 4, 2.4);

  double *edges = NULL;
  wgraph_get_edges(graph, 0, &edges);

  EXPECT_EQ(2.1, edges[1]);
  EXPECT_EQ(2.2, edges[2]);
  EXPECT_EQ(2.3, edges[3]);
  EXPECT_EQ(2.4, edges[4]);

  wgraph_free(graph);
}

TEST(WGraphTest, GetEdgesOutOfRange) {
  wgraph graph = wgraph_init(5);

  double *edges = NULL;
  res_t res = wgraph_get_edges(graph, 5, &edges);

  EXPECT_EQ(1, res);
  EXPECT_EQ(NULL, edges);

  wgraph_free(graph);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}