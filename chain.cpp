#include <iostream>
#include <tuple>
using namespace std;

class link {
private:
    int v;
    link * nx;

public:
    // constructors
    link(int);

    // gets
    int val();
    link * next();

    // functionality
    int linkNext(link *);
};

// constructors
link::link(int n) {
    v = n;
    nx = NULL;
}

// gets
int link::val() {
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

class chain {
private:
    link * head;
    int ln;

public:
    // constructors
    chain();
    chain(int);
    ~chain();

    // gets
    int len();
    link * tail();
    link * find(int);

    // functionality
    int addLink(int);

    // custom operators
    int operator [](int i);
};

// constructors
chain::chain() { // no predetermined head value
    head = NULL;
    ln = -1; // this might be wacky
}

chain::chain(int v) { // w/ predetermined head value
    link * head = new link(v);
    ln = 0; // makes finding the tail smoother
}

chain::~chain() {
    // do nothing for now
}

// gets
int chain::len() {
    return ln;
}

link * chain::tail() {
    return find(ln);
}

link * chain::find(int i) {
    link * ret = head;
    for (int j = 0; j < i; j++) {
        ret = ret->next();
    }
    return ret;
}

// functionality
int chain::addLink(int n) {
    link * temp = new link(n);
    tail()->linkNext(temp);
    ln++;
    return 0;
}

// operators
int chain::operator[](int i) { // returns the VALUE of the ith link
    return find(i)->val();
}

int main () {
    cout << "Hello, world!" << endl; cout << endl;

    return 0;
}