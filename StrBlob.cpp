#include "stdafx.h"
#include "StrBlob.h"


StrBlob::StrBlob():data(make_shared<vector<string>>())
{
}

StrBlob::StrBlob(initializer_list<string> li):data(make_shared<vector<string>>(li))
{
}

StrBlob::~StrBlob()
{
}


void StrBlob::check(size_type i, const string& msg) const
{
	if (i > data->size())
	{
		throw out_of_range(msg);
	}
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}


void StrBlob::pop_back()
{
	check(0, "pop back on empty StrBlob");
	data->pop_back();
}