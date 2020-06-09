#include <iostream>
#include <cstdarg>
using namespace std;

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
    TTT int append(T);

    // custom operators
    int operator [](int i);
};

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
TTT int chain::append(T n) {
    if (ln < 0) hd = new link(n); // if we've added nothing yet
    
    link * temp = new link(n);
    tail()->linkNext(temp);
    ln++;
    return 0;
}

// operators
int chain::operator [] (int i) { // returns the VALUE of the link
    int * ptr = reinterpret_cast<int*>(find(i)->val());
    int ret = *ptr;
    return ret;
}

int main () {
    int testcount;
    cout << "Enter test count: ";
    cin >> testcount;

    chain c;

    for (int i = 0; i < testcount; i++) {
        c.append(i); // doesn't even require stuff from triple T!!!! I think!!!!!!
    }

    for (int i = 0; i < testcount; i++) {
        cout << c[i] << endl;
    }

    return 0;
}