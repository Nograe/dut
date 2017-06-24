#include <stdio.h>
#include <math.h>

double gaussienne(double x, double u, double s){
  double ent1=(x-u)*(x-u)/(2*s*s);
  return (1.0/sqrt(s*2.0*M_PI))*exp(-ent1);
}

int main(int argc, char* argv[]) {
	return 0;
}
