#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <map>
#include <set>

#include "QueryResult.h"

using namespace std;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    // �����ļ�
    shared_ptr<vector<string>> file;
    // ÿ�����ʵ������ڵ��кŵļ��ϵ�ӳ��
    map<string, shared_ptr<set<line_no>>> wm;
};

