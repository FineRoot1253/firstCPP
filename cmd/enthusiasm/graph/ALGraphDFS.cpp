#include "enthusiasm/graph/ALGraphDFS.h"
using namespace Collection::Graph;
using namespace Enthusiasm::Graph::Search;
using Vertex = GraphVertexAlphabets;

int vertexToIntegerCast(const Vertex& vertex){
    return static_cast<int>(vertex);
}
int main(){
//    ALGraph* graph = new ALGraph(6);
//    DFS dfs = DFS(6,graph);
    ALGraph* graph = new ALGraph(7);
    DFS dfs = DFS(7,graph);
//
//    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::B));
//    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::C));
//    graph->addEdge(vertexToIntegerCast(Vertex::B), vertexToIntegerCast(Vertex::D));
//    graph->addEdge(vertexToIntegerCast(Vertex::C), vertexToIntegerCast(Vertex::A));
//    graph->addEdge(vertexToIntegerCast(Vertex::C), vertexToIntegerCast(Vertex::D));
//    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::E));
//    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::F));
//    graph->addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::F));
//    graph->addEdge(vertexToIntegerCast(Vertex::F), vertexToIntegerCast(Vertex::E));

    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::B));
    graph->addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::D));
    graph->addEdge(vertexToIntegerCast(Vertex::B), vertexToIntegerCast(Vertex::C));
    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::C));
    graph->addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::E));
    graph->addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::F));
    graph->addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::G));

    std::cout<<*graph;

    dfs.showDFSTraverse(vertexToIntegerCast(Vertex::A));
    std::cout<<std::endl;
    dfs.showDFSTraverse(vertexToIntegerCast(Vertex::C));
    std::cout<<std::endl;
    dfs.showDFSTraverse(vertexToIntegerCast(Vertex::E));
    std::cout<<std::endl;
    dfs.showDFSTraverse(vertexToIntegerCast(Vertex::G));
    std::cout<<std::endl;

    return 0;
}


