#include "enthusiasm/graph/ALGraphBFS.h"

using namespace Enthusiasm::Graph::Search;
using Vertex = GraphVertexAlphabets;

int vertexToIntegerCast(const Vertex& vertex){
    return static_cast<int>(vertex);
}
int main(){
    ALGraph* graph = new ALGraph(7);
    BFS bfs = BFS(7,graph);

    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::B));
    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::D));
    graph->addEdge(vertexToIntegerCast(Vertex::B), vertexToIntegerCast(Vertex::C));
    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::C));
    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::E));
    graph->addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::F));
    graph->addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::G));

    std::cout<<*graph;

    bfs.showBFSTraverse(vertexToIntegerCast(Vertex::A));
    std::cout<<std::endl;
    bfs.showBFSTraverse(vertexToIntegerCast(Vertex::C));
    std::cout<<std::endl;
    bfs.showBFSTraverse(vertexToIntegerCast(Vertex::E));
    std::cout<<std::endl;
    bfs.showBFSTraverse(vertexToIntegerCast(Vertex::G));
    std::cout<<std::endl;
    return 0;
}


