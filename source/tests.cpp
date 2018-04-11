#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>


//Aufgabe 1.8 GCD Funktion Implementation ---------------------------


int gcd (int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}


//Aufgabe 1.9 CheckSum  Funktion Implementation---------------------- 

int checksum(int a)
{ 
	int sum = 0;

    while (a != 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}






//TESTS CASES---------------------- 


TEST_CASE ("describe_gcd", "[gcd]")
{
REQUIRE (gcd(2,4) == 2);
REQUIRE (gcd(9,6) == 3);
REQUIRE (gcd(3,7) == 1);
}


TEST_CASE ("describe_checksum", "[checksum]")
{
REQUIRE (checksum(112601) == 11);
REQUIRE (checksum(000000) == 0);
REQUIRE (checksum(111111) == 6);

}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
