template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _elements(new T[size]), _size(size) {
    for (unsigned int i = 0; i < size; i++)
        this->_elements[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &other) {
    this->_size = other._size;

    this->_elements = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        *(this->_elements + i) = *(other._elements + i);
};

template <typename T>
Array<T>::~Array() {
    delete[] this->_elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        this->_size = other._size;
        delete[] this->_elements;
        this->_elements = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
            *(this->_elements + i) = *(other._elements + i);
    }
    return (*this);
};

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= this->_size) {
        throw std::exception();
    }

    return this->_elements[index];
};

template <typename T>
unsigned int Array<T>::size() const {
    return (this->_size);
};
