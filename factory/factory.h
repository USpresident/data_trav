#ifndef FACTORY_H
#define FACTORY_H

#include "interface.h"
#include "key_type.h"
#include <map>
#include <memory>

// IBaseInterface 提供回调函数创建对应的对象
using ProcessObjPtr = std::unique_ptr<IBaseInterface>();

class MyFactory {
public:
    static void AddType(const KeyType &type, ProcessObjPtr *createInstPtr);

    static std::unique_ptr<IBaseInterface> GetInstance(const KeyType &type);

    template <typename T> struct RegOneType {
        explicit RegOneType(KeyType type)
        {
            MyFactory::AddType(type, &T::Create);
        }
    };

    static std::map<KeyType, ProcessObjPtr*> &GetCreatePtrRecord();
};

#endif // FACTORY_H