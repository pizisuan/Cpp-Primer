#include "TextQuery.h"

#include <sstream>

// 构造函数
// 读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(ifstream& infile):file(new vector<string>)
{
    string text;
    while (getline(infile, text))
    {
        file->push_back(text);     // 保存文本
        int n = file->size() - 1;  // 当前行号
        istringstream line(text);  // 将文本分解为单词
        string word;
        while (line >> word)
        {
            // 如果单词不在wm中，以之为下标在wm中添加一项
            auto& lines = wm[word];                     // lines 是一个share_ptr
            if (!lines)                                 // 第一次遇到这个单词，指针为空
                lines.reset(new set<line_no>);          // 分配一个新的set
            lines->insert(n);                           // 将行号插入set中
        }
    }
}

QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
    
}
