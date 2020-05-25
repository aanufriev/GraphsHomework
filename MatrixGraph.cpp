#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t verticesCount) : matrix(verticesCount) {
    for (size_t i = 0; i < verticesCount; i++) {
        matrix[i] = std::vector<int>(verticesCount, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph) {
    matrix.resize(graph.VerticesCount());

    for (size_t i = 0; i < matrix.size(); i++) {
        matrix[i].resize(graph.VerticesCount());

        std::vector<int> children = graph.GetNextVertices(i);
        for (int child : children) {
            matrix[i][child] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (size_t i = 0; i < matrix.size(); i++) {
        matrix[i].clear();
        std::vector<int>().swap(matrix[i]);
    }

    matrix.clear();
    std::vector<std::vector<int>>().swap(matrix);
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (size_t i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i] == 1) {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (size_t i = 0; i < matrix.size(); i++) {
        if (matrix[i][vertex] == 1) {
            result.push_back(i);
        }
    }

    return result;
}
