/*
Provides a library to do gradient descent regression in c.
*/

# include "vector_math.c"


// 2-Dimensional double
double two_d_derive_double(double (*f)(double), double x, double dx) {
  return (f(x+dx)-f(x))/dx;
}

double two_d_double_gradient_descend(double (*function)(double), double start, double precision, double gamma, unsigned int max_iterations, double dx,
                                     double *data_x, double *data_y, double *data_step, unsigned int *iterations) {


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


// N-Dimensional

void get_gradient_double(double (*f)(double*), double *x, double dx, double *gradient, unsigned int len) {
  double df;
  for (unsigned int i = 0; i<len; i++) {
    //f(x+dx)-f(x)
    x[i] += dx;
    df = f(x);
    x[i] -= dx;
    df -= f(x);
    gradient[i] = df/dx; //df/dx_i
  }

  return;
}

void gradient_descent_double(double (*f)(double*), unsigned int dimensions, double *start, double precision, double gamma, unsigned int max_iterations, double dx, double *output, unsigned int *iterations) {

  // Init stepper
  //double *next_x = output;
  //copy_double_vec(start, next_x); //cp start to next_x

  double last_x[dimensions];

  double x[dimensions];
  copy_double_vec(start, x, dimensions); //cp start to current_x

  double step;

  double buffer_x[dimensions];
  double gradient_buffer[dimensions];


  for(unsigned int i = 0; i<max_iterations; i++) {

    copy_double_vec(x, last_x, dimensions); //save to old to calc step

    //next_x = current_x - gamma * two_d_derive_double(function, current_x, dx);
    //b = a - g*∇f(a)
    copy_double_vec(x, buffer_x, dimensions);
    get_gradient_double(f, x, dx, gradient_buffer, dimensions); //Writes gradient of f(x) to gradient_buffer
    scale_vec_double(gamma, gradient_buffer, dimensions); //g*nf

    subtract_vec_double(x, gradient_buffer, dimensions);

    step = get_distance(x, last_x, dimensions);

    if(step*step <= precision*precision) {
      *iterations = i;
      copy_double_vec(x, output, dimensions); //return x
      return;
    }
  }

}
