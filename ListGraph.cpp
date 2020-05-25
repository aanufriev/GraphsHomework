#include "ListGraph.h"

ListGraph::ListGraph(size_t verticesCount) : vertices(verticesCount), parents(verticesCount) {}

ListGraph::ListGraph(const IGraph& graph) {
    vertices.resize(graph.VerticesCount());
    parents.resize(graph.VerticesCount());

    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        vertices[i] = graph.GetNextVertices(i);
        parents[i] = graph.GetPrevVertices(i);
    }
}

ListGraph::~ListGraph() {
    for (size_t i = 0; i < vertices.size(); i++) {
        vertices[i].clear();
        std::vector<int>().swap(vertices[i]);
    }
    vertices.clear();
    std::vector<std::vector<int>>().swap(vertices);

    for (size_t i = 0; i < parents.size(); i++) {
        parents[i].clear();
        std::vector<int>().swap(parents[i]);
    }
    parents.clear();
    std::vector<std::vector<int>>().swap(parents);
}

void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
    parents[to].push_back(from);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    size_t childCount = vertices[vertex].size();
    std::vector<int> result(childCount);

    std::copy(vertices[vertex].begin(), vertices[vertex].end(), result.begin());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    size_t parentsCount = parents[vertex].size();
    std::vector<int> result(parentsCount);

    std::copy(parents[vertex].begin(), parents[vertex].end(), result.begin());
    return result;
}
