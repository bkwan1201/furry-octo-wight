#include <stdio.h>
//#include <gsl/gsl_sf_bessel.h>

#include <iostream>
#include <string>
using namespace std;

#include <iomanip>
#include <map>
#include <random>

int main(void)
{
  /*
  // BLAS Calcs
  double x = 5.0;
  double y = 0.0;
  int i = 0;
  for (i=0; i<100000000; i++)
    {
      y = gsl_sf_bessel_J0 (x);
    }
  cout << "BLAS Calculations:\n--------------------------\n";
  printf("J0(%g) = %.18e\n", x, y);
  cout << "J0(" << x << ") = " << y << "\n\n";
  */
  cout << "Exponential Distri Calcs (C++11):\n---------------------\n";
  std::random_device rd;
  std::mt19937 gen(rd());
  std::exponential_distribution<> d(1);

  std::map<int, int> hist;
  for (int n=0; n<100000000; ++n) {
    ++hist[2*d(gen)];
  }
  for (auto p : hist) {
    std::cout << std::fixed << std::setprecision(1)
	      << p.first/2.0 << '-' << (p.first+1)/2.0 <<
      ' ' << std::string(p.second/200, '*') << '\n';
  }

  return 0;
}

