#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
        :data_(new char [strlen(s) + 1]), len_(strlen(s))
	{
        strcpy(data_, s);
    }

    string::string( const char* s, size_t len )
    {
        data_ = new char[len + 1];
	    strcpy(data_, s);
    }

    string::string( const string& rhs )
        :data_(new char [rhs.size() + 1]) ,len_(rhs.size())
    {
        strcpy(data_, rhs.c_str());
    }

    string& string::operator=( const string& rhs )
    {
        if (this == &rhs)
        {
            return *this;    
        } 
        len_ = rhs.len_;
        delete data_;
        data_ = new char[rhs.len_ + 1];
        strcpy(data_, rhs.c_str());
            
        return *this;
    }

    string::~string()
    {
        len_ = 0;
        delete data_;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char* string::operator[]( size_t index )
    {
		if (index < len_ && index > 0)
		{
			return &data_[index];
		}
		//operator[]不检查索引是否有效
    }
}
