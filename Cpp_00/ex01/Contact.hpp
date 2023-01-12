#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>
#include <iomanip>

class Contact {

public:

	Contact( void );
	Contact(std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string darkestSecret);
	~Contact( void );

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);

	void	ListDetails( void );
	void	ListDetailsShort( void );

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif