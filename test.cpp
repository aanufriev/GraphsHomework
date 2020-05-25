#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void runTests() {
    // Test for correct GetNextVerticies and GetPrevVerticies
    {
        ListGraph list(5);
        MatrixGraph matrix(5);
        SetGraph set(5);
        ArcGraph arc(5);

        std::vector<IGraph*> graphs = {&list, &matrix, &set, &arc};
        for (IGraph* graph : graphs) {
            graph->AddEdge(0, 1);
            graph->AddEdge(1, 2);
            graph->AddEdge(1, 3);
            graph->AddEdge(2, 3);
            graph->AddEdge(3, 4);
        }

        std::vector<int> next1 = {2, 3};

        assert(list.GetNextVertices(1) == next1);
        assert(list.GetNextVertices(0) == matrix.GetNextVertices(0));
        assert(matrix.GetNextVertices(1) == set.GetNextVertices(1));
        assert(set.GetNextVertices(2) == arc.GetNextVertices(2));
        assert(arc.GetNextVertices(3) == list.GetNextVertices(3));
        assert(list.GetNextVertices(4) == set.GetNextVertices(4));

        std::vector<int> prev3 = {1, 2};

        assert(matrix.GetPrevVertices(3) == prev3);
        assert(list.GetPrevVertices(4) == arc.GetPrevVertices(4));
        assert(matrix.GetPrevVertices(3) == arc.GetPrevVertices(3));
        assert(set.GetPrevVertices(2) == list.GetPrevVertices(2));
        assert(arc.GetPrevVertices(1) == set.GetPrevVertices(1));
        assert(list.GetPrevVertices(0) == matrix.GetPrevVertices(0));
    }

    // Test for copy constructor
    {
        ListGraph list(5);
        list.AddEdge(0, 1);
        list.AddEdge(1, 3);
        list.AddEdge(4, 0);

        MatrixGraph matrix(list);
        assert(list.GetNextVertices(0) == matrix.GetNextVertices(0));
        assert(list.GetNextVertices(2) == matrix.GetNextVertices(2));
        assert(list.GetNextVertices(4) == matrix.GetNextVertices(4));

        assert(list.GetPrevVertices(1) == matrix.GetPrevVertices(1));
        assert(list.GetPrevVertices(3) == matrix.GetPrevVertices(3));

        matrix.AddEdge(3, 2);
        matrix.AddEdge(2, 0);

        SetGraph set(matrix);
        assert(matrix.GetNextVertices(0) == set.GetNextVertices(0));
        assert(matrix.GetNextVertices(2) == set.GetNextVertices(2));
        assert(matrix.GetNextVertices(3) == set.GetNextVertices(3));

        assert(matrix.GetPrevVertices(1) == set.GetPrevVertices(1));
        assert(matrix.GetPrevVertices(4) == set.GetPrevVertices(4));

        set.AddEdge(4, 3);
        set.AddEdge(2, 1);

        ArcGraph arc(set);
        assert(set.GetNextVertices(1) == arc.GetNextVertices(1));
        assert(set.GetNextVertices(3) == arc.GetNextVertices(3));
        assert(set.GetNextVertices(4) == arc.GetNextVertices(4));

        assert(set.GetPrevVertices(0) == arc.GetPrevVertices(0));
        assert(set.GetPrevVertices(2) == arc.GetPrevVertices(2));
    }

    std::cout << "SUCCESS" << std::endl;
}

int main(int argc, const char * argv[]) {
    runTests();
    return 0;
}
