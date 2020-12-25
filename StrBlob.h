#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>


using namespace std;

class StrBlob
{
public:
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string> li);

	size_type size()const
	{
		return data->size();
	}

	bool empty()const
	{
		return data->empty();
	}

	// �����ɾ��Ԫ��
	void push_back(const string& t)
	{
		data->push_back(t);
	}
	void pop_back();

	// Ԫ�ط���
	string& front();
	string& back();

	~StrBlob();
private:
	shared_ptr<vector<string>>  data;

	// ���data[i]���Ϸ�������һ���쳣
	void check(size_type i, const string& msg) const;

};

