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
    // 输入文件
    shared_ptr<vector<string>> file;
    // 每个单词到它所在的行号的集合的映射
    map<string, shared_ptr<set<line_no>>> wm;
};

