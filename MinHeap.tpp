template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    
    // compare 
    while (i > 0 && data[i] < data[parent(i)])
    {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int small = i; 
    int leftChild = left(i);
    int rightChild = right(i);

    // check if left child is smaller 
    if (leftChild < size() && data[leftChild] < data[small])
    {
        small = leftChild;
    }

    // check if right child is smaller
    if (rightChild < size() && data[rightChild] < data[small])
    {
        small = rightChild;
    }

    // if small is not current index, swap and continue sifting down
    if (small != i)
    {
        swap(data[i], data[small]);
        siftDown(small);
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
   
    // TODO: Implement removing the root element.
    if (empty())
    {
        throw runtime_error("Heap is empty");
    }
   
   T rootValue = data[0];

   // swap root w/ last elem 
   swap(data[0], data[size() - 1]);

   // remove last elem (old root)
   data.pop_back();

   // restore heap property from root 
   if (!empty())
   {
    siftDown(0);
   }

  return rootValue; 

}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    // pop if removing last elem
    if (index == size() - 1)
    {
        data.pop_back();
        return;
    } 


    // save moved value to index position 
    T valueAtEnd = data.back();

    // replace elem at index w/ last elem and pop
    data[index] = data.back();
    data.pop_back();

    if (index < size() && data[index] == valueAtEnd)
    {
        siftDown(index);
    }

}
