#pragma once

/*
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array.
*/
template <typename T>
void iter(T *arrayAddress, unsigned int arrayLength, T f(T element)) {
    int i = -1;

    while ((unsigned int) ++i < arrayLength)
        arrayAddress[i] = f(arrayAddress[i]);
}

template <typename T>
T sumItself(T element) {
    return (element + element);
}
