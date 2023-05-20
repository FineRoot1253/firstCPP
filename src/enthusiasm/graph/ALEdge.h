#ifndef FIRSTCPP_ALEDGE _H
#define FIRSTCPP_ALEDGE _H

namespace Collection{
    namespace Graph{
        class WeightedEdge{
        private:
            int vertex1;
            int vertex2;
            int weight;

        public:
            WeightedEdge();
            WeightedEdge(const int& vertex1, const int& vertex2, const int& weight);
            WeightedEdge(const WeightedEdge& ref);
            WeightedEdge(WeightedEdge&& ref) noexcept = default;
            WeightedEdge& operator=(const WeightedEdge& ref);
            WeightedEdge& operator=(WeightedEdge&& ref) noexcept = default;
            ~WeightedEdge() = default;

        public:
            int getVertex1() const;
            int getVertex2() const;
            int getWeight() const;
        };

        WeightedEdge::WeightedEdge()
        : vertex1(0)
        , vertex2(0)
        , weight(0){
        }

        WeightedEdge::WeightedEdge(const int &vertex1, const int &vertex2, const int &weight)
        : vertex1(vertex1)
        , vertex2(vertex2)
        , weight(weight){
        }

        WeightedEdge::WeightedEdge(const Collection::Graph::WeightedEdge &ref)
        : vertex1(ref.vertex1)
        , vertex2(ref.vertex2)
        , weight(ref.weight){
        }

        WeightedEdge &WeightedEdge::operator=(const Collection::Graph::WeightedEdge &ref) {
            vertex1 = ref.vertex1;
            vertex2  = ref.vertex2;
            weight = ref.weight;
            return *this;
        }

        int WeightedEdge::getVertex1() const {
            return vertex1;
        }

        int WeightedEdge::getVertex2() const {
            return vertex2;
        }

        int WeightedEdge::getWeight() const {
            return weight;
        }


    }
}

#endif // FIRSTCPP_ALEDGE _H

