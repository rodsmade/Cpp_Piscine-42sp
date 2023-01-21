#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>

#include "Contact.hpp"

const int PHONEBOOK_SIZE = 8;

class PhoneBook {
   public:
    Contact allContacts[PHONEBOOK_SIZE];

    PhoneBook();
    ~PhoneBook();

    void ListContactByIndex(int index);
    void ListAllContacts();
    void AddNewContact(Contact newContact, int index);
};

#endif