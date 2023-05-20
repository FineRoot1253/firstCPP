#include "enthusiasm/graph/ALGraphKruskal.h"
using namespace Collection::Graph;
using Vertex = GraphVertexAlphabets;

int vertexToIntegerCast(const Vertex& vertex){
    return static_cast<int>(vertex);
}
int main(){
    WeightedALGraph *graph = new WeightedALGraph(6);
    ALGraphKruskal graphKruskal = ALGraphKruskal(graph, 6);

    graphKruskal.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::B), 9);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::B), vertexToIntegerCast(Vertex::C), 2);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::C), 12);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::D), 8);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::C), 6);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::A), vertexToIntegerCast(Vertex::F), 11);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::F), vertexToIntegerCast(Vertex::D), 4);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::D), vertexToIntegerCast(Vertex::E), 3);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::E), vertexToIntegerCast(Vertex::C), 7);
    graphKruskal.addEdge(vertexToIntegerCast(Vertex::F), vertexToIntegerCast(Vertex::E), 13);

    std::cout<<*graph<<std::endl;
    graphKruskal.changeToMSTByKruskal();
    std::cout<<*graph<<std::endl;
    graphKruskal.showGraphWeightInfo();
    return 0;
}


