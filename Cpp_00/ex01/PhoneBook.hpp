#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <iostream>

const int PHONEBOOK_SIZE = 8;

class PhoneBook
{
public:
	Contact allContacts[PHONEBOOK_SIZE];

	PhoneBook();

	~PhoneBook();

	void ListContactByIndex(int index);

	void ListAllContacts();

	void AddNewContact(Contact newContact, int index);
};

#endif