#include "QueryResult.h"

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}