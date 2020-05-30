#include <iostream>
#include <vector>
#include <utility>
#include <set>

class MatrixGraph {
public:
    MatrixGraph(size_t verticesCount);

    ~MatrixGraph();

    void AddEdge(int from, int to, int time);

    int VerticesCount() const;

    std::vector<int> GetNextVertices(int vertex) const;

    int getDistance(int from, int to) const;
private:
    std::vector<std::vector<int>> matrix;
};

MatrixGraph::MatrixGraph(size_t verticesCount) : matrix(verticesCount) {
    for (size_t i = 0; i < verticesCount; i++) {
        matrix[i] = std::vector<int>(verticesCount, 0);
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

void MatrixGraph::AddEdge(int from, int to, int time) {
    matrix[from][to] = time;
    matrix[to][from] = time;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (size_t i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i] != 0) {
            result.push_back(i);
        }
    }

    return result;
}

int MatrixGraph::getDistance(int from, int to) const {
    return matrix[from][to];
}

struct SetComparator {
    bool operator() (const std::pair<int, int>& l, const std::pair<int, int>& r) const {
        return l.second < r.second;
    }
};

int findBestWay(MatrixGraph graph, int from, int to) {
    std::vector<int> minDistance(graph.VerticesCount(), INT_MAX);
    minDistance[from] = 0;

    std::set<std::pair<int, int>, SetComparator> prioritySet;
    prioritySet.emplace(std::make_pair(from, minDistance[from]));

    while (!prioritySet.empty()) {
        int vertex = prioritySet.begin()->first;
        prioritySet.erase(std::make_pair(vertex, minDistance[vertex]));

        std::vector<int> nextVerticies = graph.GetNextVertices(vertex);
        for (int child : nextVerticies) {

            if (minDistance[child] == INT_MAX) {
                minDistance[child] = minDistance[vertex] + graph.getDistance(vertex, child);
                prioritySet.emplace(std::make_pair(child, minDistance[child]));

            } else if (minDistance[child] > minDistance[vertex] + graph.getDistance(vertex, child)) {
                prioritySet.erase(std::make_pair(child, minDistance[child]));
                minDistance[child] = minDistance[vertex] + graph.getDistance(vertex, child);
                prioritySet.emplace(std::make_pair(child, minDistance[child]));
            }

        }
    }
    return minDistance[to];
}

MatrixGraph initGraph(int v, int e) {
    MatrixGraph graph(v);

    for (int i = 0; i < e; i++) {
        int parent = 0;
        int child = 0;
        int time = 0;
        std::cin >> parent >> child >> time;

        graph.AddEdge(parent, child, time);
    }

    return graph;
}

void run() {
    int v = 0;
    int e = 0;
    std::cin >> v >> e;
    MatrixGraph graph = initGraph(v, e);

    int from = 0;
    int to = 0;
    std::cin >> from >> to;

    std::cout << findBestWay(graph, from, to) << std::endl;
}

int main() {
    run();
    return 0;
}
