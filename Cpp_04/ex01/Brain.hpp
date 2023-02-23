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

    Brain &operator=(const Brain &other);

    std::string *getIdeas(void) const;
    std::string getIdeaById(unsigned int id) const;
    void setIdeas(const std::string **ideas);
    void setIdeaById(unsigned int id, const std::string *idea);
};
