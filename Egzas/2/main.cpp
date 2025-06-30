// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

#include <set>

class Object
{
    // all your code goes here
private:
    int value;

public:
    Object &l;

    Object(int v = 0) : value(v), l(temp()) {}
    
    Object(bool temp) : value(0), l(*this) {}

    ~Object() {}

    Object operator()(int v) const { return Object(v); }

    Object &operator++()
    {
        ++value;
        return *this;
    }

    Object operator-(const Object &other) const { return Object(value - other.value); }

    int k() const { return value; }

    bool operator<(const Object &other) const { return value < other.value; }

    static Object &temp()
    {
        static Object temp(true);
        return temp;
    }
};

template <typename Object>

void test()
{
    Object k, l = k(0) - (++l).k();
    std::set<Object> s;
    s.insert(k);
    if (k.l.k() == 0)
    {
        return;
    }
}

int main(int argc, char **argv)
{

    test<Object>();
    return 0;
}