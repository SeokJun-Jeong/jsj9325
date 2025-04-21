#ifndef STRING_REP_H
#define STRING_REP_H

class StringRep
{
friend class String;        //0415txt

private:
    char *str_;
    int len_;
    int rc;     //ref.count
    
    StringRep();
    StringRep(const char* s);
    ~StringRep();
    
public:


};


#endif