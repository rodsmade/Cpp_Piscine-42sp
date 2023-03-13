template <typename T>
MutantStack<T>::MutantStack() : _mStack(std::stack<T>()) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
const T &MutantStack<T>::top() const {
    return _mStack.top();
};

template <typename T>
std::size_t MutantStack<T>::size() const {
    return _mStack.size();
};

template <typename T>
void MutantStack<T>::push(T element) {
    _mStack.push(element);
};

template <typename T>
void MutantStack<T>::pop() {
    _mStack.pop();
};
