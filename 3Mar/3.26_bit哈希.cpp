
#include <iostream>
#include <vector>
using namespace std;

namespace bit
{
    template <size_t N>
    class bitset
    {
    public:
        bitset()
        {
            _bits.resize(N / 8 + 1, 0);
        }

        void set(size_t x)
        {
            size_t i = x / 8;
            size_t j = x % 8;
            _bits[i] |= (1 << j);
        }

        void reset(size_t x)
        {
            size_t i = x / 8;
            size_t j = x % 8;
            _bits[i] &= ~(1 << j);
        }

        bool test(size_t x)
        {
            size_t i = x / 8;
            size_t j = x % 8;
            return (bool)(_bits[i] & (1 << j));
        }

    private:
        vector<char> _bits;
    };

    void test_bitset1()
    {
        bitset<100> bs1;
        bs1.set(8);
        bs1.set(9);
        bs1.set(20);

        cout << bs1.test(8) << endl;
        cout << bs1.test(9) << endl;
        cout << bs1.test(20) << endl;

        bs1.reset(8);
        bs1.reset(9);
        bs1.reset(20);

        cout << bs1.test(8) << endl;
        cout << bs1.test(9) << endl;
        cout << bs1.test(20) << endl;
    }

    template <size_t N>
    class twobitset
    {
        public:
        void set(size_t x)
        {
            bool insert1 = _bs1.test(x);
            bool insert2 = _bs2.test(x);
            if (insert1 == false && insert2 == false)
            {
                //- >  01
                _bs2.set(x);
            }
            else if (insert1 == false && insert2 == true)
            {
                //- >  01
                _bs2.set(x);
            }

            else if (insert1 == true && insert2 == true)
            {
                //- >  10
                _bs1.set(x);
                _bs2.reset(x);
            }
        }

        void print_once_num()
        {
            for(size_t i=0;i<N;++i)
            {
                if(_bs1.test(i) == false && _bs2.test(i) == true)
                cout<<i<<endl;
            }

        }

    private:
        bitset<N> _bs1;
        bitset<N> _bs2;
    };

    void test_bit_set3()
    {
        int a[] = {1,5,4,45,5,5,4,4,88,88,89};
        twobitset<100> bs;
        for (auto e:a)
        {
            bs.set(e);
            /* code */
        }

        bs.print_once_num();
        
    }

}

int main()
{
    // bit::test_bitset1();
    bit::test_bit_set3();
    return 0;
}