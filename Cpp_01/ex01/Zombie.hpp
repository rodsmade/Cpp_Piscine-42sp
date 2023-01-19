#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>

class Zombie {
public:
    Zombie( void );
    ~Zombie( void );

    std::string getName( void );
    void setName(std::string name);

    void announce( void );

private:
    std::string _name;

};

#endif
