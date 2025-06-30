// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

class Object
{
    // all your code goes here
private:
    char c;

public:
    Object(char c) : c(c) {};
    Object() : c('2') {};

    char k() const
    {
        return c;
    }

    char l() const
    {
        return c;
    }

    static char m()
    {
        return '2';
    }
};

template <typename Object>
void test()
{
    Object m('2'), n;
    if (m.k() == n.l())
    {
        const Object l;
        if (l.l() == Object::m())
            return;
    }
}

int main(int argc, char **argv)
{
    test<Object>();
    return 0;
}