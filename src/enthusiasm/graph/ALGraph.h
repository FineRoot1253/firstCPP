#ifndef FIRSTCPP_ALGRAPH _H
#define FIRSTCPP_ALGRAPH _H

#include <iostream>

#include "enthusiasm/linked_list/DLinkedList.h"

using namespace Collection;


namespace Collection {
    namespace Graph {

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

        class ALGraph {
        private:
            int vertexNumber;
            int edgeNumber;
            DLinkedList<int> **adjacentList;

        public:
            ALGraph();

            explicit ALGraph(const int &vertexNumber);

            ALGraph(const ALGraph &ref);

            ALGraph(ALGraph &&ref) noexcept;

            ALGraph &operator=(const ALGraph &ref);

            ALGraph &operator=(ALGraph &&ref) noexcept;

            ~ALGraph();

            friend std::ostream &operator<<(std::ostream &output, const ALGraph &ref);

        public:
            void addEdge(const int &fromV, const int &toV);
            const DLinkedList<int> getAdjacentList(const int& vertex) const;
        };

        ALGraph::ALGraph()
                : vertexNumber(0)
                  , edgeNumber(0)
                  , adjacentList(nullptr) {
        }

        ALGraph::ALGraph(const int &vertexNumber)
                : vertexNumber(vertexNumber)
                , edgeNumber(0){
            adjacentList = new DLinkedList<int>*[vertexNumber];
            for (int i = 0; i < vertexNumber; ++i) {
                adjacentList[i] = new DLinkedList<int>();
                adjacentList[i]->setSortRule(whichIsPrecede);
            }
        }

        ALGraph::ALGraph(const ALGraph &ref)
                : vertexNumber(ref.vertexNumber)
                  , edgeNumber(ref.edgeNumber){
            adjacentList = new DLinkedList<int> *[vertexNumber];
            for (int i = 0; i < vertexNumber; ++i) {
                adjacentList[i] = new DLinkedList<int>(*ref.adjacentList[i]);
            }

        }

        ALGraph::ALGraph(ALGraph &&ref) noexcept
                : vertexNumber(ref.vertexNumber)
                  , edgeNumber(ref.edgeNumber)
                  , adjacentList(ref.adjacentList) {
            ref.adjacentList = nullptr;
        }

        ALGraph &ALGraph::operator=(const ALGraph &ref) {
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
            return *this;
        }

        ALGraph &ALGraph::operator=(ALGraph &&ref) noexcept {
            vertexNumber = ref.vertexNumber;
            edgeNumber = ref.edgeNumber;
            adjacentList = ref.adjacentList;
            ref.adjacentList = nullptr;
            return *this;
        }

        ALGraph::~ALGraph() {
            for (int i = 0; i < vertexNumber; ++i) {
                delete adjacentList[i];
            }
            delete[] adjacentList;
        }

        void ALGraph::addEdge(const int &fromV, const int &toV) {
            adjacentList[fromV]->insert(toV);
            adjacentList[toV]->insert(fromV);
            ++edgeNumber;
        }

        std::ostream &operator<<(std::ostream &output, const ALGraph &ref) {
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

        const DLinkedList<int> ALGraph::getAdjacentList(const int &vertex) const{
            if(vertexNumber < vertex+1){
                return DLinkedList<int>();
            }
            return *adjacentList[vertex];
        }

    }
}

#endif // FIRSTCPP_ALGRAPH _H

