#include "C:\Users\enkwi\Desktop\laba4\lab03\lb3\svg.h"
#include <cassert>

void test_bin()
{
    size_t bin = 1;
    size_t max_count = 10;
    assert( opacity_factor(bin, max_count) == 0.1);
}

void max_count()
{
    size_t bin = 5;
    size_t max_count = bin;
    assert( opacity_factor(bin, max_count) == 1 );
}
int
main()
{
    test_bin();
    max_count();
return 0;
}
