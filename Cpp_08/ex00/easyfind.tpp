template <typename T>
typename T::iterator easyfind(T &container, int find) {
    typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end()) {
        throw std::out_of_range("Value not found in container");
    }
    return it;
}
