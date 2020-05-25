#ifndef ARCGRAPH_H_
#define ARCGRAPH_H_

#include "IGraph.h"
#include <vector>
#include <utility>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(size_t verticesCount);

    ArcGraph(const IGraph& graph);

    virtual ~ArcGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> edges;
    size_t verticesCount;
};

#endif  //  ARCGRAPH_H_
