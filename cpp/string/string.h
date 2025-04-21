#ifndef STRING_H
#define STRING_H
#include<iostream>

class String
{
    friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char *str;
    int len;

public:
    String();
    String(const char *s);
    String(const String& rhs);
    ~String();

    String& operator=(const String& rhs);    //s3=s1

    bool operator==(const String& rhs) const;     

    const String operator+(const String& rhs) const;


    const char *c_str() const;
    int size() const;

    // set ??
    inline std::ostream& operator<<(std::ostream& out, const String& rhs)
};


#endif