#include "ex01header.hpp"

int main(void) {
    {  // DEFAULT VALUES
        std::cout << "===== WITH DEFAULT VALUES: =====" << std::endl;
        Data *myDataPtr = new Data();

        std::cout << "Original data:" << std::endl;
        std::cout << "Important Tidbit: " << myDataPtr->_importantTidbit << std::endl;
        std::cout << "Relevant Tidbit: " << myDataPtr->_relevantTidbit << std::endl;
        std::cout << "Interesting Tidbit: " << myDataPtr->_interestingTidbit << std::endl;

        uintptr_t intPtr = serialize(myDataPtr);

        Data *myDataPtrPostDeserialization = deserialize(intPtr);
        std::cout << "\nDeserialized data:" << std::endl;
        std::cout << "Important Tidbit: " << myDataPtrPostDeserialization->_importantTidbit << std::endl;
        std::cout << "Relevant Tidbit: " << myDataPtrPostDeserialization->_relevantTidbit << std::endl;
        std::cout << "Interesting Tidbit: " << myDataPtrPostDeserialization->_interestingTidbit << std::endl;

        delete myDataPtr;
    }
    {  // CUSTOM VALUES
        std::cout << "\n===== WITH CUSTOM VALUES: =====" << std::endl;
        std::string tidbit1 = "The shortest war in history was fought between the countries of Zanzibar and Great Britain in 1896, lasting just 38 minutes before Zanzibar surrendered.";
        std::string tidbit2 = "The largest snowflake on record was reportedly 15 inches wide and 8 inches thick, and fell in Montana, USA in 1887.";
        std::string tidbit3 = "The world's largest living organism is a fungus known as Armillaria ostoyae, which covers over 2,200 acres (8.9 square kilometers) in the Blue Mountains of Oregon, USA.";

        Data *myCustomDataPtr = new Data(tidbit1, tidbit2, tidbit3);

        std::cout << "Original data:" << std::endl;
        std::cout << "Important Tidbit: " << myCustomDataPtr->_importantTidbit << std::endl;
        std::cout << "Relevant Tidbit: " << myCustomDataPtr->_relevantTidbit << std::endl;
        std::cout << "Interesting Tidbit: " << myCustomDataPtr->_interestingTidbit << std::endl;

        uintptr_t intPtr = serialize(myCustomDataPtr);

        Data *myCustomDataPtrPostDeserialization = deserialize(intPtr);
        std::cout << "\nDeserialized data:" << std::endl;
        std::cout << "Important Tidbit: " << myCustomDataPtrPostDeserialization->_importantTidbit << std::endl;
        std::cout << "Relevant Tidbit: " << myCustomDataPtrPostDeserialization->_relevantTidbit << std::endl;
        std::cout << "Interesting Tidbit: " << myCustomDataPtrPostDeserialization->_interestingTidbit << std::endl;

        delete myCustomDataPtr;
    }

    return 0;
}