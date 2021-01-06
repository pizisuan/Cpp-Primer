#pragma once
#include <string>
using namespace std;
class HasPtr
{
public:
    // ���캯�������µ�string �� �µļ�����, ����������Ϊ1
    HasPtr(const string& s = string()) :ps(new string(s)), i(0), use(new size_t(0))
    {

    }
    // �������캯����������������Ա,������������
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

