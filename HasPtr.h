#pragma once
#include <string>
using namespace std;
class HasPtr
{
public:
    // 构造函数分配新的string 和 新的计数器, 将计数器置为1
    HasPtr(const string& s = string()) :ps(new string(s)), i(0), use(new size_t(0))
    {

    }
    // 拷贝构造函数拷贝所有三个成员,并递增计数器
    HasPtr(const HasPtr& p) : ps(p.ps), i(p.i), use(p.use)
    {
        ++*use;
    }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string* ps;
    int i;
    size_t* use;
};

