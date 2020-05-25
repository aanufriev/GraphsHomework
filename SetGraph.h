#ifndef SETGRAPH_H_
#define SETGRAPH_H_

#include "IGraph.h"
#include <vector>
#include <map>

class SetGraph : public IGraph {
public:
    explicit SetGraph(size_t verticesCount);

    SetGraph(const IGraph& graph);

    virtual ~SetGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::map<int, bool>> vertices;
};

#endif  //  SETGRAPH_H_
