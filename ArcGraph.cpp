#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t verticesCount) : edges(0), verticesCount(verticesCount) {}

ArcGraph::ArcGraph(const IGraph& graph) {
    edges.clear();

    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        std::vector<int> children = graph.GetNextVertices(i);

        for (int child : children) {
            edges.push_back(std::pair<int, int>(i, child));
        }
    }
    verticesCount = graph.VerticesCount();
}

ArcGraph::~ArcGraph() {
    edges.clear();
    std::vector<std::pair<int, int>>().swap(edges);
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back(std::pair<int, int>(from, to));
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (std::pair<int, int> edge : edges) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }

    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (std::pair<int, int> edge : edges) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }

    return result;
}
