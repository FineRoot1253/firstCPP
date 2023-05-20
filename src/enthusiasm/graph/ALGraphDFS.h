#ifndef FIRSTCPP_ALGRAPHDFS _H
#define FIRSTCPP_ALGRAPHDFS _H

#include <iostream>
#include "enthusiasm/graph/ALGraph.h"
#include "enthusiasm/stack/ListBaseStack.h"

using namespace Collection::Graph;

namespace Enthusiasm {
    namespace Graph {
        namespace Search {
            class DFS {
            private:
                ALGraph *graph;
                bool *visitInfoArray;
                ListBaseStack<int> stack;

            private:
                bool visitVertex(const int &vertex);

            public:
                DFS(const int &vertexNumber, ALGraph *graph);
                DFS(const DFS &ref);
                DFS(DFS &&ref) noexcept;
                DFS &operator=(const DFS &ref);
                DFS &operator=(DFS &&ref) noexcept;

                ~DFS() {
                    delete[] visitInfoArray;
                };

            public:
                void showDFSTraverse(const int &startVertex);
            };

            DFS::DFS(const int &vertexNumber, ALGraph *graph)
                    : graph(graph)
                      , visitInfoArray(new bool[vertexNumber])
                      , stack(ListBaseStack<int>()) {
            }

            DFS::DFS(const DFS &ref)
                    : graph(ref.graph)
                      , visitInfoArray(new bool[sizeof(ref.visitInfoArray) / sizeof(bool)])
                      , stack(ListBaseStack<int>()) {
                for (int i = 0; i < sizeof(ref.visitInfoArray) / sizeof(bool); ++i) {
                    visitInfoArray[i] = ref.visitInfoArray[i];
                }
            }

            DFS::DFS(DFS &&ref) noexcept
                    : graph(ref.graph)
                      , visitInfoArray(nullptr)
                      , stack(ListBaseStack<int>()) {
                std::swap(visitInfoArray, ref.visitInfoArray);
                ref.visitInfoArray = nullptr;
            }

            DFS &DFS::operator=(const DFS &ref) {
                if(this != &ref){
                    graph = ref.graph;
                    stack = ListBaseStack<int>();

                    delete[] visitInfoArray;
                    visitInfoArray = new bool[sizeof(ref.visitInfoArray) / sizeof(bool)];
                    for (int i = 0; i < sizeof(ref.visitInfoArray) / sizeof(bool); ++i) {
                        visitInfoArray[i] = ref.visitInfoArray[i];
                    }
                }
                return *this;
            }

            DFS &DFS::operator=(DFS &&ref) noexcept {
                graph = ref.graph;
                stack = ListBaseStack<int>();
                std::swap(visitInfoArray, ref.visitInfoArray);
                ref.visitInfoArray = nullptr;
                return *this;
            }

            bool DFS::visitVertex(const int &vertex) {
                if (!visitInfoArray[vertex]) {
                    visitInfoArray[vertex] = true;
                    std::cout << static_cast<char>(vertex + 65)<<" ";
                    return true;
                }
                return false;
            }

            void DFS::showDFSTraverse(const int &startVertex) {
                DLinkedList<int> list = graph->getAdjacentList(startVertex); // 2, 4, 3
                int beforeVertex = startVertex;
                // 방문 처리
                visitVertex(startVertex);

                for (list.first(); !list.isDone(); list.next()) {
                    // 방문 검사 후 통과시 현재 시작 정점 스택에 추가
                    if (!visitInfoArray[list.current().getData()]) {
                        stack.push(startVertex);
                        showDFSTraverse(list.current().getData());
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
        }
    }
}
#endif // FIRSTCPP_ALGRAPHDFS _H

