/*
 	Basic Data Types
*/
	
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */
  int i;
  long l;
  char c;
  float f;
  double d;

  //input example : 3 12345678912345 a 334.23 14049.30493
  scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);

  printf("%d\n", i);
  printf("%ld\n", l);
  printf("%c\n", c);
  printf("%.3f\n", f);
  printf("%.9lf\n", d);

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
