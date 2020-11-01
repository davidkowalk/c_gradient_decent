# include <stdio.h>
# include "./gradient_descent.c"

double f(double x) {
  return x*x-x*2+1;
}

void print_double_array(double *array, unsigned int len) {
  printf("[");
  for(unsigned int i = 0; i<len; i++) {
    printf("%f", array[i]);

    if(i != len-1) {
      printf(",");
    }
  }

  printf("]\n");
}

int main() {
  printf("Started...\n");

  //Setup
  double start = 0;
  double precision = 0.001;
  double gamma = 0.2;
  double dx = 0.00001; //dx for derivative

  unsigned int max_iters = 20;

  double data_x[max_iters]; //data to be saved
  double data_y[max_iters];
  double data_s[max_iters];
  unsigned int iterations;

  printf("Getting lowest Point...\n");
  double x = two_d_double_gradient_descend(
    &f, start, precision, gamma, max_iters, dx,
    data_x, data_y, data_s, &iterations
  );

  printf("Results:\n");
  print_double_array(data_x, iterations);
  print_double_array(data_y, iterations);
  print_double_array(data_s, iterations);

  printf("\nX = %f\n", x);
}
