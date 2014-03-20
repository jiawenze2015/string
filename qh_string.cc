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
	{
		if (s)
		{
			len_  = strlen(s);
			data_ = new char [len_ + 1];
			strcpy(data_, s);
		}
		else
		{
			len_  = 0;
			data_ = NULL;
		}

    }

	//理解为用s的前len个字符初始化，len长度大于s长度则按s长度处理
    string::string( const char* s, size_t len )
    {
        if (!s)
		{
			len_  = 0;
			data_ = NULL;
		}
		else
		{
			len_ = (strlen(s) > len) ? len : strlen(s);
			data_ = new char[len_ + 1];
		    strcpy(data_, s);
		}
    }

    string::string( const string& rhs )
    {
		if (rhs)
		{
			len_  = strlen(rhs.data_);
			data_ = new char [len_ + 1];
			strcpy(data_, rhs.c_str());
		}
		else
		{
			len_  = 0;
			data_ = NULL;
		}
    }

    string& string::operator=( const string& rhs )
    {
        if (this == &rhs)
        {
            return *this;    
        }
		if (rhs)
		{
			len_ = rhs.len_;
			delete data_;
			data_ = new char[rhs.len_ + 1];
			strcpy(data_, rhs.c_str());
		}
		else
		{
			len_  = 0;
			data_ = NULL;	
		}
            
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
			return data_[index];
		}
	    return -1;
    }
}
