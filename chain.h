#ifndef _CHAIN_H_
#define _CHAIN_H_
#endif

#include <iostream>
#include <cstdarg>
#define TTT template <typename T> 

class link {
private:
    void * v;
    link * nx;

public:
    // constructors
    TTT link(T n);

    // gets
    void * val(); // cursed? or not.
    link * next();

    // functionality
    int linkNext(link *);
    TTT void set(T);
    void deleteVal();

    // operators
    TTT void operator = (T);
};

class chain {
private:
    link * hd;
    int ln;

public:
    // constructors
    chain();
    chain(int);
    ~chain();

    // gets
    int len();
    link * head();
    link * tail();
    link * find(int);

    // functionality
    TTT void append(T);

    // custom operators
    int operator [](int i);
};