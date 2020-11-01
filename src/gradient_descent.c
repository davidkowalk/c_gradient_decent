/*
Provides a library to do gradient descent regression in c.
*/


double two_d_derive_double(double (*f)(double), double x, double dx) {
  return (f(x+dx)-f(x))/dx;
}

// 2-Dimensional double
double two_d_double_gradient_descend(double (*function)(double), double start, double precision, double gamma, int max_iterations, double dx,
                    double *data_x, double *data_y, double *data_step, int *iterations) {


  //set up next and current x for loop
  double next_x = start;
  double current_x = start;
  double step;

  printf("next_x = %f\n", next_x);

  for(int i = 0; i<max_iterations; i++) {

    current_x = next_x;
    next_x = current_x - gamma * two_d_derive_double(function, current_x, dx);

    step = next_x - current_x;

    data_x[i] = next_x;
    data_y[i] = function(next_x);
    data_step[i] = step;

    if(step*step <= precision*precision) {
      *iterations = i;
      return next_x;
    }

  }

}
