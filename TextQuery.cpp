#include "TextQuery.h"

#include <sstream>

// ���캯��
// ��ȡ�����ļ����������ʵ��кŵ�ӳ��
TextQuery::TextQuery(ifstream& infile):file(new vector<string>)
{
    string text;
    while (getline(infile, text))
    {
        file->push_back(text);     // �����ı�
        int n = file->size() - 1;  // ��ǰ�к�
        istringstream line(text);  // ���ı��ֽ�Ϊ����
        string word;
        while (line >> word)
        {
            // ������ʲ���wm�У���֮Ϊ�±���wm�����һ��
            auto& lines = wm[word];                     // lines ��һ��share_ptr
            if (!lines)                                 // ��һ������������ʣ�ָ��Ϊ��
                lines.reset(new set<line_no>);          // ����һ���µ�set
            lines->insert(n);                           // ���кŲ���set��
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
