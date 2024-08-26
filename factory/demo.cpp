#include "demo.h"
#include <iostream>

MyFactory::RegOneType<Demo> g_demo(KeyType(static_cast<int>(TYPE::RED)));

std::unique_ptr<IBaseInterface> Demo::Create()
{
    return std::make_unique<Demo>();
}

bool Demo::FunTodo()
{
    std::cout << "This is Demo's FunTodo." << std::endl;
    return true;
}

// ----------------------------------------------------------------

MyFactory::RegOneType<Demo2> g_demo2(KeyType(static_cast<int>(TYPE::GREEN)));

std::unique_ptr<IBaseInterface> Demo2::Create()
{
    return std::make_unique<Demo2>();
}

bool Demo2::FunTodo()
{
    std::cout << "This is Demo2's FunTodo." << std::endl;
    return true;
}