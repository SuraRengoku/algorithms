#include"basics.h"
#include"basics.cpp"

struct Str{
    virtual void foo();
    void Bar();
    virtual ~Str();
    string s;
    bool operator<(const Str &str) const{
        return s.length()<str.s.length();
    }
};
void Str::foo(){}
Str::~Str(){}

struct ChildStr:Str{
    void foo() override;
    ~ChildStr();
};
void ChildStr::foo(){}
ChildStr::~ChildStr(){}
