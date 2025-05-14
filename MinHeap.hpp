#ifndef MIN_HEAP
#define MIN_HEAP

class MinHeap{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void heapify(int i);
        void buildHeap(const std::vector<std::vector<int>>& arr);
        struct dado extractMin();
    private:
        std::vector<std::vector<int>> array; //vetor de vetores de int
        int size;
        int capacity;

}

#endif
