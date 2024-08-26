
#include "factory.h"

std::map<KeyType, ProcessObjPtr *> &MyFactory::GetCreatePtrRecord()
{
    static std::map<KeyType, ProcessObjPtr *> createFunPtrRecord;
    return createFunPtrRecord;
}

void MyFactory::AddType(const KeyType &type, ProcessObjPtr *createInstPtr)
{
    auto cmdInst = GetCreatePtrRecord().find(type);
    if (cmdInst == GetCreatePtrRecord().end()) {
        GetCreatePtrRecord()[type] = createInstPtr;
    }
}

std::unique_ptr<IBaseInterface> MyFactory::GetInstance(const KeyType &type)
{
    auto cmdInst = GetCreatePtrRecord().find(type);
    if (cmdInst == GetCreatePtrRecord().end()) {
        return nullptr;
    }
    return (cmdInst->second)();
}