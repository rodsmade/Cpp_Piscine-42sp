#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        Contact() ;

        Contact(std::string firstName,
                std::string lastName,
                std::string nickname,
                std::string phoneNumber,
                std::string darkestSecret) ;

        ~Contact() ;

        void    ListDetails() ;
};

#endif