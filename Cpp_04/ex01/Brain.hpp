#pragma once

#include <iostream>

class Brain {
   private:
    std::string _type;
    std::string _ideas[100];

   public:
    Brain();
    Brain(const Brain &other);
    ~Brain();

    std::string getType(void);
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string &idea);

    Brain &operator=(const Brain &other);
};
