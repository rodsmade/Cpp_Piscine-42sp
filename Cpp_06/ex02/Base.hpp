#pragma once

enum ObjectType {
    Type_Base = 0,
    Type_A = 1,
    Type_B = 2,
    Type_C = 3
};


class Base {
   public:
    virtual int getType(void);
    virtual ~Base();
};
