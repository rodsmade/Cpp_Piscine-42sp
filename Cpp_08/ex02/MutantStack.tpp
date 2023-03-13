template <typename T>
MutantStack<T>::MutantStack() : _mStack(std::stack<T>()) {}

template <typename T>
const T &MutantStack<T>::top() {
    return this->_mStack.top();
};