#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    Weapon *_weapon;
    std::string _name;

public:
    HumanB( std::string name );
    ~HumanB( void );

    void setWeapon( Weapon *weapon ) ;

    void attack( void ) ;
};

#endif