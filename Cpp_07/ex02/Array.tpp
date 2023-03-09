template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _elements(new T[size]), _size(size) {}

template <typename T>
void Array<T>::do_something() {
    // do something with m_data
}