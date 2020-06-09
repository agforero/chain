#include "chain.h"
using namespace std;

// #define TTT template <typename T> 

// constructors
TTT link::link(T n) {
    T * adr = new T;
    *adr = n; // the thing adr is pointing to set to n
    v = adr;
    nx = NULL;
}

// gets
void * link::val() {
    return v;
}

link * link::next() {
    return nx;
}

// functionality
int link::linkNext(link * l) {
    if (!l) return 1; 
    nx = l;
    return 0;
}

TTT void link::set(T n) {
    T * adr = new T;
    *adr = n;
    v = adr;
}

void link::deleteVal() {
    delete v;
}

// operators 
TTT void link::operator = (T i) {
    set(i);
}

// constructors
chain::chain() { // no predetermined hd value
    hd = NULL;
    ln = -1; // this might be wacky
}

chain::~chain() {
    link * cur = hd;
    for (int i = ln; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cur = cur->next();
        }
        cur->deleteVal();
        delete cur;
        cur = hd;
    }
    delete hd;
}

// gets
int chain::len() {
    return ln;
}

link * chain::head() {
    return hd;
}

link * chain::tail() {
    return find(ln);
}

link * chain::find(int i) {
    link * ret = hd;
    for (int j = 0; j < i; j++) {
        ret = ret->next();
    }
    return ret;
}

// functionality
TTT void chain::append(T n) {
    if (ln < 0) hd = new link(n); // if we've added nothing yet
    
    link * temp = new link(n);
    tail()->linkNext(temp);
    ln++;
}

// operators
int chain::operator [] (int i) { // returns the VALUE of the link
    int * ptr = reinterpret_cast<int*>(find(i)->val());
    int ret = *ptr;
    return ret;
}