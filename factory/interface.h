#ifndef INTERFACE_H
#define INTERFACE_H

class IBaseInterface {
public:
    virtual bool FunTodo() = 0; // 具体干活的函数
    virtual ~IBaseInterface() = default;
};

#endif // INTERFACE_H