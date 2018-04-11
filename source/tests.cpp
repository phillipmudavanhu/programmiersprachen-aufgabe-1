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


int sumMultiples(int a, int b){ 
		int sum = 0;
		 for( int i = 1; i <= 1000; ++i )
		 {			       
			if (i%a==0 || i%b==0 )
			   	{
			   	   	sum = sum + i;
			   	}
		 }

	return sum;
}


//Aufgabe 1.11 Fraction Anteil---------------------------------------

int fract(float frac)
{
    double integer, value = frac, number = modf(value, &integer);
    return number;
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
REQUIRE (checksum(12345) == 15);
REQUIRE (checksum(1) == 1);
REQUIRE (checksum(02) == 2);
REQUIRE (checksum(-1) == -1);
}


TEST_CASE ("describe_sumMultuples", "[sumMultiples]")
{
REQUIRE (sumMultiples (3,5) == 234168);
REQUIRE (sumMultiples (1,5) == 500500);
REQUIRE (sumMultiples (1,3) == 500500);
}


TEST_CASE("fract","[fract]")
{
	REQUIRE(7.009999 == Approx( 7.01 ).epsilon(0.001));
	REQUIRE(0.009999 == Approx( 0.01 ).epsilon(0.001));
	REQUIRE(1.9999 == Approx( 2.0 ).epsilon(0.001));
}





int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
