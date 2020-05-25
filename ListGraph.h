#ifndef LISTGRAPH_H_
#define LISTGRAPH_H_

#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph {
public:
    explicit ListGraph(size_t verticesCount);

    ListGraph(const IGraph& graph);

    virtual ~ListGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> vertices;
    std::vector<std::vector<int>> parents;
};

#endif  //  LISTGRAPH_H_
