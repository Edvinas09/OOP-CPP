#include <iostream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <cassert>

using namespace std;

class knyga
{
public:
    string PAVADINIMAS;
    string AUTORIUS;
    int LEIDIMO_METAI;

    static int AMOUNT;

    knyga(string p, string a) //konstruktorius
    {
        setPavadinimas(p);
        setAutorius(a);
        setLeidimo_metai(0);

        AMOUNT++;
    }

    knyga(string p, string a, int l) //konstruktorius
    {
        setPavadinimas(p);
        setAutorius(a);
        setLeidimo_metai(l);

        AMOUNT++;
    }

    ~knyga() //destruktorius
    {
        AMOUNT--;
    }

    //Seteriai
    void setPavadinimas(string p)
    {
        if((p.length() != 0) && (p != ""))
        {
            PAVADINIMAS = p;
        }
    }

    void setAutorius(string a)
    {
        if((a.length() >= 4) && (a != "")
           && isupper(a[0]) && isupper(a[3]) && (a[1] == '.') && (a[2] == ' '))
        {
            AUTORIUS = a;
        }
    }

    void setLeidimo_metai(int l)
    {
        if(l > 0)
        {
            LEIDIMO_METAI = l;
        }
    }

    //Geteriai
    string getPavadinimas()
    {
        return PAVADINIMAS;
    }

    string getAutorius()
    {
        return AUTORIUS;
    }

    int getLeidimo_metai()
    {
        return LEIDIMO_METAI;
    }

    static int getAmount()
    {
        return AMOUNT;
    }

    string toString()
    {
        stringstream ss;

        ss<<AUTORIUS<<" \""<<PAVADINIMAS<<"\", "<<LEIDIMO_METAI;

        return ss.str();
    }
};

int knyga::AMOUNT = 0;

int main()
{
    knyga* knygos[5];

    // Test no.1
    knygos[0] = new knyga("Kelione", "K. Keliauninkas");

    assert(knygos[0]->getAutorius() == "K. Keliauninkas");
    assert(knygos[0]->getPavadinimas() == "Kelione");
    assert(knyga::getAmount() == 1);

    // Test no.2
    knygos[1] = new knyga("Maistas", "V. Vyrejas", 2000);

    assert(knygos[1]->getAutorius() == "V. Vyrejas");
    assert(knygos[1]->getPavadinimas() == "Maistas");
    assert(knygos[1]->getLeidimo_metai() == 2000);
    assert(knyga::getAmount() == 2);

    // Test no.3
    knygos[2] = new knyga(" ", "Kelionis Keliauninkas", -2000);

    assert(knygos[2]->getAutorius() != "Kelionis Keliauninkas");
    assert(knygos[2]->getPavadinimas() != "");
    assert(knygos[2]->getLeidimo_metai() != -2000);
    assert(knyga::getAmount() == 3);

    // Test no.4
    knygos[3] = new knyga("Pasaulis", "A. Keliautojas", 2025);

    assert(knygos[3]->getAutorius() == "A. Keliautojas");
    assert(knygos[3]->getPavadinimas() == "Pasaulis");
    assert(knygos[3]->getLeidimo_metai() == 2025);
    assert(knyga::getAmount() == 4);

    // Test no.5
    knygos[4] = new knyga("Gyvenimas", "", 1999);

    assert(knygos[4]->getAutorius() != " ");
    assert(knygos[4]->getPavadinimas() == "Gyvenimas");
    assert(knygos[4]->getLeidimo_metai() == 1999);
    assert(knyga::getAmount() == 5);

    delete knygos[0];
    delete knygos[1];
    delete knygos[2];
    delete knygos[3];
    delete knygos[4];

    assert(knyga::getAmount() == 0);

    return 0;
}
