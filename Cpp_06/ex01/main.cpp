#include "ex01header.hpp"

int main(void) {
    Data *myDataPtr = new Data();

    std::cout << "Original data:" << std::endl;
    std::cout << "Important Tidbit: " << myDataPtr->_importantTidbit << std::endl;
    std::cout << "Relevant Tidbit: " << myDataPtr->_relevantTidbit << std::endl;
    std::cout << "Interesting Tidbit: " << myDataPtr->_interestingTidbit << std::endl;

    uintptr_t intPtr = serialize(myDataPtr);

    Data *myDataPtrPostDeserialization = deserialize(intPtr);
    std::cout << "Deserialized data:" << std::endl;
    std::cout << "Important Tidbit: " << myDataPtrPostDeserialization->_importantTidbit << std::endl;
    std::cout << "Relevant Tidbit: " << myDataPtrPostDeserialization->_relevantTidbit << std::endl;
    std::cout << "Interesting Tidbit: " << myDataPtrPostDeserialization->_interestingTidbit << std::endl;

    delete myDataPtr;

    return 0;
}