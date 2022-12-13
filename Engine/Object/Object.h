//
// Created by f33dir on 12/13/22.
//

#ifndef LAB_OBJECT_H
#define LAB_OBJECT_H
#include "../Application.h"

class Object {
public:
    int x;
    int y;
    virtual int Process(Application context);
};


#endif //LAB_OBJECT_H
