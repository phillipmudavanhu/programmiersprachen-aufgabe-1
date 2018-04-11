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


int sumMultiples(int a, int b, int Count){ 
		int sum = 0;
		 for( int i = 1; i <= Count; ++i )
		 {			       
			if (i%a==0 || i%b==0 )
			   	{
			   	   	sum = sum + i;
			   	}
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
REQUIRE (checksum(12345) == 15);
REQUIRE (checksum(1) == 1);
REQUIRE (checksum(02) == 2);
REQUIRE (checksum(-1) == -1);
}


TEST_CASE ("describe_sumMultuples", "[sumMultiples]")
{
REQUIRE (sumMultiples(3,5,1000) == 234168);
REQUIRE (sumMultiples(3,5,5) == 8);
REQUIRE (sumMultiples(3,5,10) == 33);
REQUIRE (sumMultiples(3,5,1) == 0);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
