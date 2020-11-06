# include <stdio.h>
# include "./gradient_descent.c"

double f(double *x) { //requires length of 3
  return 0.5*(x[0]-2)*(x[0]-2)+3*(x[1]+1)*(x[1]+1)-x[0];
}

void print_double_array(double *array, unsigned int len) {
  printf("[\n");
  for(unsigned int i = 0; i<len; i++) {
    printf("\t%f", array[i]);

    if(i != len-1) {
      printf(",\n");
    }
  }

  printf("\n]\n");
}

int main() {
  printf("Started...\n");

  //Setup
  unsigned int dimensions = 2;
  double precision = 0.001;
  double gamma = 0.2;
  double dx = 0.0001; //dx for derivative

  double start[] = {3.0, 1.0};
  print_double_array(start, dimensions);

  unsigned int max_iters = 200;

  unsigned int iterations = 0;
  double endpoint[] = {-1.0, 1.0};

  printf("Getting lowest Point...\n");
  gradient_descent_double(
    &f, dimensions, start, precision, gamma, max_iters, dx,
    endpoint, &iterations
  );

  printf("Result:\n");
  print_double_array(endpoint, dimensions);
  printf("Iterations:\t%u\n", iterations);
  printf("Dimensions:\t%u\n", dimensions);
}
