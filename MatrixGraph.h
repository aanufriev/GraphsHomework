#ifndef MATRIXGRAPH_H_
#define MATRIXGRAPH_H_

#include "IGraph.h"
#include <vector>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(size_t verticesCount);

    MatrixGraph(const IGraph& graph);

    virtual ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> matrix;
};

#endif  //  MATRIXGRAPH_H_
