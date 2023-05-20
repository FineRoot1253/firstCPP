#ifndef FIRSTCPP_ALGRAPHBFS _H
#define FIRSTCPP_ALGRAPHBFS _H

#include <iostream>
#include "enthusiasm/graph/ALGraph.h"
#include "enthusiasm/queue/ListBaseQueue.h"

using namespace Collection::Graph;
using namespace Collection::Queue;

namespace Enthusiasm {
    namespace Graph {
        namespace Search {
            class BFS {
            private:
                ALGraph *graph;
                bool *visitInfoArray;
                ListBaseQueue<int> queue;

            private:
                bool visitVertex(const int &vertex);

            public:
                BFS(const int &vertexNumber, ALGraph *graph);
                BFS(const BFS &ref);
                BFS(BFS &&ref) noexcept;
                BFS &operator=(const BFS &ref);
                BFS &operator=(BFS &&ref) noexcept;

                ~BFS() {
                    delete[] visitInfoArray;
                };

            public:
                void showBFSTraverse(const int &startVertex);
            };

            BFS::BFS(const int &vertexNumber, ALGraph *graph)
                    : graph(graph)
                      , visitInfoArray(new bool[vertexNumber])
                      , queue(ListBaseQueue<int>()) {
            }

            BFS::BFS(const BFS &ref)
                    : graph(ref.graph)
                      , visitInfoArray(new bool[sizeof(ref.visitInfoArray) / sizeof(bool)])
                      , queue(ListBaseQueue<int>()) {
                for (int i = 0; i < sizeof(ref.visitInfoArray) / sizeof(bool); ++i) {
                    visitInfoArray[i] = ref.visitInfoArray[i];
                }
            }

            BFS::BFS(BFS &&ref) noexcept
                    : graph(ref.graph)
                      , visitInfoArray(nullptr)
                      , queue(ListBaseQueue<int>()) {
                std::swap(visitInfoArray, ref.visitInfoArray);
                ref.visitInfoArray = nullptr;
            }

            BFS &BFS::operator=(const BFS &ref) {
                if(this != &ref){
                    graph = ref.graph;
                    queue = ListBaseQueue<int>();

                    delete[] visitInfoArray;
                    visitInfoArray = new bool[sizeof(ref.visitInfoArray) / sizeof(bool)];
                    for (int i = 0; i < sizeof(ref.visitInfoArray) / sizeof(bool); ++i) {
                        visitInfoArray[i] = ref.visitInfoArray[i];
                    }
                }
                return *this;
            }

            BFS &BFS::operator=(BFS &&ref) noexcept {
                graph = ref.graph;
                queue = ListBaseQueue<int>();
                std::swap(visitInfoArray, ref.visitInfoArray);
                ref.visitInfoArray = nullptr;
                return *this;
            }

            bool BFS::visitVertex(const int &vertex) {
                if (!visitInfoArray[vertex]) {
                    visitInfoArray[vertex] = true;
                    std::cout << static_cast<char>(vertex + 65)<<" ";
                    return true;
                }
                return false;
            }

            void BFS::showBFSTraverse(const int &startVertex) {
                DLinkedList<int> list = graph->getAdjacentList(startVertex); // 2, 4, 3
                int beforeVertex = startVertex;
                bool isDone = false;
                // 초기 시작 정점 방문 처리
                visitVertex(startVertex);
                
                while(!isDone){
                    // 이동 가능한 정점 검사 후 하나씩 큐에 삽입 처리
                    for (list.first(); !list.isDone(); list.next()) {
                        // 방문 검사 후 통과시 현재 시작 정점 큐에 추가
                        if (visitVertex(list.current().getData())) {
                            queue.enqueue(list.current().getData());
                        }
                    }
                    if(!queue.isEmpty()){
                        int vertex = queue.dequeue();
                        list = graph->getAdjacentList(vertex);
                    }else{
                        // 큐가 텅 비면 끝,
                        // 만약 간선이 없는 정점으로 시작하면 큐가 당연히 텅 비므로 무조건 탈출한다. 주의할 것
                        isDone = true;
                    }
                }
                std::fill(visitInfoArray, visitInfoArray + (sizeof(visitInfoArray)/sizeof(bool)), false);
            }
        }
    }
}
#endif // FIRSTCPP_ALGRAPHBFS _H

