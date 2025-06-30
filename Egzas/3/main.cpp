// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

#include <algorithm>

class Object
{
    // all your code goes here
    int i = 0;

public:
    Object() : i(0) {}
    Object(int val) : i(val) {}

    Object(const Object &other) : i(other.i) {}
    Object &operator=(const Object &other)
    {
        i = other.i;
        return *this;
    }

    Object &operator++()
    {
        ++i;
        return *this;
    }
    Object operator++(int)
    {
        Object tmp = *this;
        ++i;
        return tmp;
    }
    bool operator!=(const Object &other) const { return i != other.i; }

    Object &operator*() { return *this; }

    const Object &operator*() const { return *this; }

    Object operator+(int n) const
    {
        Object tmp = *this;
        tmp.i += n;
        return tmp;
    }

    static Object f(const Object &obj)
    {
        return obj;
    }
};

template <typename Object>
void test()
{
    Object o;
    std::transform(o, o + 5, o, &Object::f);
}

int main(int argc, char **argv)
{
    test<Object>();
    return 0;
}