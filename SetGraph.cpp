#include "SetGraph.h"

SetGraph::SetGraph(size_t verticesCount) : vertices(verticesCount) {}

SetGraph::SetGraph(const IGraph& graph) {
    vertices.resize(graph.VerticesCount());

    for (size_t i = 0; i < vertices.size(); i++) {
        std::vector<int> children = graph.GetNextVertices(i);

        for (int child : children) {
            vertices[i][child] = true;
        }
    }
}

SetGraph::~SetGraph() {
    vertices.clear();
    std::vector<std::map<int, bool>>().swap(vertices);
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from][to] = true;
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (auto it = vertices[vertex].begin(); it != vertices[vertex].end(); it++) {
        if (it->second) {
            result.push_back(it->first);
        }
    }

    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].find(vertex) != vertices[i].end()) {
            result.push_back(i);
        }
    }

    return result;
}
