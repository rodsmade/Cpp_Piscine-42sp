#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>

#include "Weapon.hpp"

class HumanB {
   private:
    std::string _name;
    Weapon *_weapon;

   public:
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon *weapon);

    void attack(void);
};

#endif
