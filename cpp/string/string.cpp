#include "string.h"
#include <cassert>
#include <cstring>

inline std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str;
}

String::String()
:str_(new )
{
    str = new char[1];
    str[0] = '\0';
    len = 0;
}

String::String(const char *s)
{
    str = new char[strlen(s)+1];  //malloc
    assert(str);
    strcpy(str, s);

    len = strlen(s);
}


String::String(const String& rhs)
{   
    str = new char[rhs.len + 1];
    assert(str);
    strcpy(str, rhs.str);
    
    len = rhs.len;
}

inline String::~String()
{   
    delete [] str;        //free
}


String& String::operator=(const String& rhs)
{
    delete [] str; //공간 삭제후 공간 재 할당
    str = new char[rhs.len];
    assert(str);
    strcpy(str, rhs.str);

    len = rhs.len;

    return *this;
}

bool String::operator==(const String& rhs)
{
    return strcmp(str, rhs.str) == 0;
}

const String String::operator+(const String& rhs)
{
    char buf[len + rhs.len + 1];
    strcpy(buf, str);
    strcat(buf, rhs.str);
    String result(buf);

    return result;
}


inline const char *String::c_str()
{
    return str;
}

inline int String::size()
{
    return len;
}