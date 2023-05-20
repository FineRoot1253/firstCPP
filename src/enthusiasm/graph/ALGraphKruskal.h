#ifndef FIRSTCPP_ALGRAPHKRUSKAL _H
#define FIRSTCPP_ALGRAPHKRUSKAL _H

#include <utility>

#include "enthusiasm/linked_list/DLinkedList.h"
#include "enthusiasm/priority_queue/PriorityQueue.h"
#include "enthusiasm/stack/ListBaseStack.h"
#include "enthusiasm/graph/ALEdge.h"

using namespace Collection::Queue;

namespace Collection{
    namespace Graph{
        enum class GraphVertexAlphabets : int{
            A = 0,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K
        };
        Priority weightCompare(const WeightedEdge& edge1, const WeightedEdge& edge2){
            if(edge1.getWeight() > edge2.getWeight()){
                return Priority::RIGHT_GT;
            }else if(edge1.getWeight() < edge2.getWeight()){
                return Priority::LEFT_GT;
            }else{
                return Priority::EQUAL;
            }
        }

        class WeightedALGraph{
        private:
            int vertexNumber;
            int edgeNumber;
            DLinkedList<int> **adjacentList;


        private:

        public:
            WeightedALGraph();
            WeightedALGraph(const int& vertexNumber);
            WeightedALGraph(const WeightedALGraph& ref);
            WeightedALGraph(WeightedALGraph&& ref) noexcept;
            WeightedALGraph& operator=(const WeightedALGraph& ref);
            WeightedALGraph& operator=(WeightedALGraph&& ref) noexcept;
            ~WeightedALGraph();

            friend std::ostream &operator<<(std::ostream &output, const WeightedALGraph &ref);

        public:
            void removeEdge(const int& vertex1, const int& vertex2);
            void removeWayEdge(const int& vertex1, const int& vertex2);
            void recoverEdge(const int& vertex1, const int& vertex2, const int& weight);
            void addEdge(const int &fromVertex, const int &toVertex, const int& weight);

            DLinkedList<int> getAdjacentList(const int &vertex) const;
            const int getVertexNumber() const;
            const int getEdgeNumber() const;
        };

        WeightedALGraph::WeightedALGraph()
        : vertexNumber(0)
          , edgeNumber(0)
          , adjacentList(nullptr){
        }

        WeightedALGraph::WeightedALGraph(const int& vertexNumber)
        : vertexNumber(vertexNumber)
        , edgeNumber(0)
        , adjacentList(new DLinkedList<int> * [vertexNumber]){
            for (int i = 0; i < vertexNumber; ++i) {
                adjacentList[i] = new DLinkedList<int>();
                adjacentList[i]->setSortRule(whichIsPrecede);
            }
        }

        WeightedALGraph::WeightedALGraph(const WeightedALGraph& ref)
        : vertexNumber(ref.vertexNumber)
        , edgeNumber(0)
        , adjacentList(new DLinkedList<int> * [vertexNumber]){
            adjacentList = new DLinkedList<int> *[vertexNumber];
            for (int i = 0; i < vertexNumber; ++i) {
                adjacentList[i] = new DLinkedList<int>(*ref.adjacentList[i]);
            }
        }

        WeightedALGraph::WeightedALGraph(WeightedALGraph&& ref) noexcept
        : vertexNumber(ref.vertexNumber)
        , edgeNumber(ref.edgeNumber)
        , adjacentList(new DLinkedList<int> * [vertexNumber]){
            ref.adjacentList = nullptr;
        }

        WeightedALGraph& WeightedALGraph::operator=(const WeightedALGraph& ref){
            if(this != &ref){
                for (int i = 0; i < vertexNumber; ++i) {
                    delete adjacentList[i];
                }
                delete[] adjacentList;
                vertexNumber = ref.vertexNumber;
                edgeNumber = ref.edgeNumber;
                adjacentList = new DLinkedList<int>*[vertexNumber];
                for (int i = 0; i < vertexNumber; ++i) {
                    adjacentList[i] = new DLinkedList<int>(*ref.adjacentList[i]);
                }
            }
        }

        WeightedALGraph& WeightedALGraph::operator=(WeightedALGraph&& ref) noexcept{
            vertexNumber = ref.vertexNumber;
            edgeNumber = ref.edgeNumber;
            adjacentList = ref.adjacentList;
            ref.adjacentList = nullptr;
            return *this;
        }

        WeightedALGraph::~WeightedALGraph(){
             for (int i = 0; i < vertexNumber; ++i) {
                delete adjacentList[i];
            }
            delete[] adjacentList;
        }

        void WeightedALGraph::addEdge(const int &fromVertex, const int &toVertex, const int& weight) {
            adjacentList[fromVertex]->insert(toVertex);
            adjacentList[toVertex]->insert(fromVertex);
            ++edgeNumber;
        }

        std::ostream &operator<<(std::ostream &output, const WeightedALGraph &ref) {
            for (int i = 0; i < ref.vertexNumber; ++i) {
                output << static_cast<char>(i + 65) << "와 연결된 정점: ";
                for (ref.adjacentList[i]->first(); !ref.adjacentList[i]->isDone(); ref.adjacentList[i]->next()) {
                    if (!ref.adjacentList[i]->current().isError()) {
                        output << static_cast<char>(ref.adjacentList[i]->current().getData() + 65) << " ";
                    }
                }
                output << std::endl;
            }
            return output;
        }

        void WeightedALGraph::removeEdge(const int &vertex1, const int &vertex2) {
            removeWayEdge(vertex1, vertex2);
            removeWayEdge(vertex2, vertex1);
            --edgeNumber;
        }

        void WeightedALGraph::removeWayEdge(const int &vertex1, const int &vertex2) {
            for (adjacentList[vertex1]->first(); !adjacentList[vertex1]->isDone(); adjacentList[vertex1]->next()) {
                if(adjacentList[vertex1]->current().getData() == vertex2){
                    adjacentList[vertex1]->remove();
                    return;
                }
            }
        }

        void WeightedALGraph::recoverEdge(const int &vertex1, const int &vertex2, const int &weight) {
            adjacentList[vertex1]->insert(vertex2);
            adjacentList[vertex2]->insert(vertex1);
            ++edgeNumber;
        }

        DLinkedList<int> WeightedALGraph::getAdjacentList(const int &vertex) const{
            if(vertexNumber < vertex+1){
                return DLinkedList<int>();
            }
            return *adjacentList[vertex];
        }

        const int WeightedALGraph::getVertexNumber() const {
            return vertexNumber;
        }

        const int WeightedALGraph::getEdgeNumber() const {
            return edgeNumber;
        }

        class ALGraphKruskal{
        private:
            WeightedALGraph *graph;
            bool *visitInfoArray;
            PriorityQueue<WeightedEdge> priorityQueue;
            ListBaseStack<int> stack;

        public:
            ALGraphKruskal(WeightedALGraph* graph, const int& vertexNumber);
            ALGraphKruskal(const ALGraphKruskal& ref);
            ALGraphKruskal(ALGraphKruskal&& ref) noexcept;
            ALGraphKruskal& operator=(const ALGraphKruskal& ref);
            ALGraphKruskal& operator=(ALGraphKruskal&& ref) noexcept;
            ~ALGraphKruskal();

        public:
            void showGraphDFSTraverse(const int& startVertex);
            void showGraphWeightInfo() const;
            bool isVertexConnected(const int& vertex1, const int& vertex2);
            void addEdge(const int &fromVertex, const int &toVertex, const int& weight);


            void changeToMSTByKruskal();
        };

        ALGraphKruskal::ALGraphKruskal(WeightedALGraph* graph, const int& vertexNumber)
        : graph(graph)
        , visitInfoArray(new bool[vertexNumber])
        , stack(ListBaseStack<int>())
        , priorityQueue((PriorityQueue<WeightedEdge>(weightCompare))){
        }

        ALGraphKruskal::ALGraphKruskal(const Collection::Graph::ALGraphKruskal &ref)
        : graph(ref.graph)
        , visitInfoArray(new bool[sizeof(ref.visitInfoArray) / sizeof(bool)])
        , stack(ListBaseStack<int>())
        , priorityQueue((PriorityQueue<WeightedEdge>(weightCompare))){

        }

        ALGraphKruskal::ALGraphKruskal(Collection::Graph::ALGraphKruskal &&ref) noexcept
        : graph(ref.graph)
        , visitInfoArray(new bool[sizeof(ref.visitInfoArray) / sizeof(bool)])
        , stack(ListBaseStack<int>())
        , priorityQueue((PriorityQueue<WeightedEdge>(weightCompare))){
            std::swap(visitInfoArray, ref.visitInfoArray);
            ref.visitInfoArray = nullptr;
        }

        ALGraphKruskal &ALGraphKruskal::operator=(const Collection::Graph::ALGraphKruskal &ref) {
            if(this != &ref){
                graph = ref.graph;
                stack = ListBaseStack<int>();
                priorityQueue = PriorityQueue<WeightedEdge>(weightCompare);

                delete[] visitInfoArray;
                visitInfoArray = new bool[sizeof(ref.visitInfoArray) / sizeof(bool)];
                for (int i = 0; i < sizeof(ref.visitInfoArray) / sizeof(bool); ++i) {
                    visitInfoArray[i] = ref.visitInfoArray[i];
                }
            }
            return *this;
        }

        ALGraphKruskal &ALGraphKruskal::operator=(Collection::Graph::ALGraphKruskal &&ref) noexcept {
            graph = ref.graph;
            stack = ListBaseStack<int>();
            priorityQueue = PriorityQueue<WeightedEdge>(weightCompare);
            std::swap(visitInfoArray, ref.visitInfoArray);
            ref.visitInfoArray = nullptr;
            return *this;
        }

        ALGraphKruskal::~ALGraphKruskal() {
            delete graph;
            delete []visitInfoArray;
        }

        void ALGraphKruskal::showGraphDFSTraverse(const int& startVertex) {
            DLinkedList<int> list = graph->getAdjacentList(startVertex); // 2, 4, 3

            // 방문 처리
            if(!visitInfoArray[startVertex]){
                visitInfoArray[startVertex] = true;
            }

            for (list.first(); !list.isDone(); list.next()) {
                // 방문 검사 후 통과시 현재 시작 정점 스택에 추가
                if (!visitInfoArray[list.current().getData()]) {
                    stack.push(startVertex);
                    showGraphDFSTraverse(list.current().getData());
                }
            }

            if(!stack.isEmpty()){
                stack.pop();
            }else{
                for (int i = 0; i < sizeof(visitInfoArray) / sizeof(bool); ++i) {
                    visitInfoArray[i] = false;
                }
            }
        }

        void ALGraphKruskal::showGraphWeightInfo() const {
            PriorityQueue<WeightedEdge> tempQueue = priorityQueue;
            WeightedEdge tempEdge;

            while(!tempQueue.isEmpty()){
                tempEdge = tempQueue.dequeue();
               std::cout<<"("<<static_cast<char>(tempEdge.getVertex1()+65)<<"-"<<static_cast<char>(tempEdge.getVertex2()+65)<<"), weight: "<<tempEdge.getWeight()<<std::endl;
            }
        }

        bool ALGraphKruskal::isVertexConnected(const int &vertex1, const int &vertex2) {


            DLinkedList<int> list = graph->getAdjacentList(vertex1); // 2, 4, 3

            // 방문 처리
            if(!visitInfoArray[vertex1]){
                visitInfoArray[vertex1] = true;
            }

            // 타겟에 도달 가능한지 검사
            for (list.first(); !list.isDone(); list.next()) {
                if(list.current().getData() == vertex2){
                    for (int i = 0; i < sizeof(visitInfoArray) / sizeof(bool); ++i) {
                        visitInfoArray[i] = false;
                    }
                    return true;
                }
            }

            for (list.first(); !list.isDone(); list.next()) {
                // 방문 검사 후 통과시 현재 시작 정점 스택에 추가
                if (!visitInfoArray[list.current().getData()]) {
                    stack.push(vertex1);
                    return isVertexConnected(list.current().getData(), vertex2);
                }
            }

            if(!stack.isEmpty()){
                stack.pop();
            }else{
                for (int i = 0; i < sizeof(visitInfoArray) / sizeof(bool); ++i) {
                    visitInfoArray[i] = false;
                }
            }
            return false;
        }

        void _dfsTraverse(const int &startVertex, const int &target, bool* isFound){
            *isFound = true;
        }

        void ALGraphKruskal::changeToMSTByKruskal() {
            WeightedEdge reserveEdge[20];
            WeightedEdge tempEdge;
            int edgeIndex = 0;

            for (int i = 0; graph->getEdgeNumber() + 1 > graph->getVertexNumber(); ++i) {
                tempEdge = priorityQueue.dequeue();
                graph->removeEdge(tempEdge.getVertex1(), tempEdge.getVertex2());

                if(!isVertexConnected(tempEdge.getVertex1(), tempEdge.getVertex2())){
                    graph->recoverEdge(tempEdge.getVertex1(), tempEdge.getVertex2(), tempEdge.getWeight());
                    reserveEdge[edgeIndex++] = tempEdge;
                }
            }

            for (int i = 0; i < edgeIndex; ++i) {
                priorityQueue.enqueue(reserveEdge[i]);
            }
        }

        void ALGraphKruskal::addEdge(const int &fromVertex, const int &toVertex, const int &weight) {
            graph->addEdge(fromVertex, toVertex, weight);
            priorityQueue.enqueue(WeightedEdge(fromVertex, toVertex, weight));
        }


    }
}

#endif // FIRSTCPP_ALGRAPHKRUSKAL _H

