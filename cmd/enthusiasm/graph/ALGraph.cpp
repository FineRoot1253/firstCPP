#include "enthusiasm/graph/ALGraph.h"

using namespace Collection::Graph;
using Vertex = GraphVertexAlphabets;

int vertexToIntegerCast(const Vertex& vertex){
    return static_cast<int>(vertex);
}

int main(){
    ALGraph graph = ALGraph(5);

    graph.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::B));
    graph.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::D));
    graph.addEdge(vertexToIntegerCast(Vertex::B), vertexToIntegerCast(Vertex::C));
    graph.addEdge(vertexToIntegerCast(Vertex::C), vertexToIntegerCast(Vertex::D));
    graph.addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::E));
    graph.addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::A));

    std::cout<<graph;
    return 0;
}


