#ifndef WGRAPH_H
#define WGRAPH_H

typedef struct wgraph_t {
  double **adj_;
  unsigned vcount_;
} *wgraph;

typedef unsigned char res_t;

wgraph wgraph_init(unsigned vcount);
void wgraph_free(wgraph graph);

res_t wgraph_set_edge(wgraph graph, unsigned vstart, unsigned vend,
                      double weight);
res_t wgraph_get_edges(wgraph graph, unsigned vertex, double **edges);

#endif  // WGRAPH_H