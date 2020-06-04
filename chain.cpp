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
    int append(int);

    // custom operators
    int operator [](int i);
};

// constructors
chain::chain() { // no predetermined hd value
    hd = NULL;
    ln = -1; // this might be wacky
}

chain::chain(int v) { // w/ predetermined hd value
    link * hd = new link(v);
    ln = 0; // makes finding the tail smoother
}

chain::~chain() {
    link * cur = hd;
    for (int i = ln; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cur = cur->next();
        }
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
int chain::append(int n) {
    if (ln < 0) { // if we've added nothing yet
        hd = new link(n);
    }

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
    cout << "Hello, world!" << endl;

    int testcount;
    cout << "Enter test count: ";
    cin >> testcount;

    chain c;

    for (int i = 0; i < testcount; i++) {
        c.append(i);
    }

    for (int i = 0; i < testcount; i++) {
        cout << c[i] << endl;
    }

    return 0;
}