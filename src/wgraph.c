#include "wgraph.h"

#include <stdlib.h>

wgraph wgraph_init(unsigned vcount) {
  wgraph graph = (wgraph)malloc(sizeof(struct wgraph_t));
  double **adj = malloc(vcount * sizeof(double *));

  for (unsigned i = 0; i < vcount; i++) {
    adj[i] = malloc(vcount * sizeof(double));
    for (int j = 0; j < vcount; j++) adj[i][j] = -1.0;
  }

  graph->vcount_ = vcount;
  graph->adj_ = adj;
  return graph;
}

void wgraph_free(wgraph graph) {
  if (graph == NULL) return;

  for (int i = 0; i < graph->vcount_; i++) free(graph->adj_[i]);
  free(graph->adj_);
  free(graph);
}

res_t wgraph_set_edge(wgraph graph, unsigned vstart, unsigned vend,
                      double weight) {
  if (graph == NULL || vstart >= graph->vcount_ || vend >= graph->vcount_)
    return 1;

  graph->adj_[vstart][vend] = weight;
  return 0;
}

res_t wgraph_get_edges(wgraph graph, unsigned vertex, double **edges) {
  if (graph == NULL || vertex >= graph->vcount_) return 1;

  *edges = graph->adj_[vertex];
  return 0;
}