#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H

#include "BaseClass.h"

class DerivedClass : public BaseClass {
public:
    virtual double function(double x) const override;
};

#endif // DERIVEDCLASS_H
