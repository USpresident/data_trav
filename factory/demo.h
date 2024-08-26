#ifndef DEMO_H
#define DEMO_H

#include "factory.h"

class Demo : public IBaseInterface {
public:
    static std::unique_ptr<IBaseInterface> Create();
    bool FunTodo() override;
};

class Demo2 : public IBaseInterface {
public:
    static std::unique_ptr<IBaseInterface> Create();
    bool FunTodo() override;
};

#endif // DEMO_H