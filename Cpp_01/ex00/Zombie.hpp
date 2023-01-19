#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>

class Zombie {
public:
    Zombie( std::string );
    ~Zombie( void );

    void announce( void );

private:
    std::string _name;

};

#endif
