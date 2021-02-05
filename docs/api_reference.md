# API Reference: Gradient Descent in C

This API provides you with multiple tools to find a local extreme in any function.

---
## gradient_descent.c

Calculates derivatives and runs basic gradient descent. Requires `vector_math.c`.

### 2-Dimensional

The 2-dimensional functions assume a function that takes a single double-input and output a single double value.

#### two_d_double_gradient_descend()

Finds a local extreme in a function from a starting point

**Returns:** *double* - x value where y is extreme.

Inputs:

|        Argument       |        Type       | Description
|-----------------------|-------------------|------------
| **function(double)**  | double \*function  | Pointer to the processed function of type double. Takes a single double.
| **start**             | double            | Starting point of gradient descent.
| **precision**         | double            | Step size at which the gradient descent will be terminated.
| **gamma**             | double            | Conversion rate between derivative and step size. Set this to a negative value to find the maximum value.
| **max_iterations**    | unsigned int      | Maximum numbers of iterations before forcefull termination.
| **dx**                | double            | Step size in numerical derivation: df/dx = (f(x+dx)-f(x))/dx
| **data_x**            | double *          | Array to store x-values in. Must be of length max_iterations.
| **data_y**            | double *          | Array to store y-values in. Must be of length max_iterations.
| **data_step**         | double *          | Array to store step-values in. Must be of length max_iterations.
| **iterations**        | double *          | Pointer to variable storing the iterations actually executed.

**Example:**
```c
double f(double x) {
  return x*x-x*2+1;
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

  printf("Found: %f", x);
  printf("Iters: %f", iterations);
}
```

#### two_d_derive_double()

Calculates approximate derivative (numerical) between `x` and `x+dx`. Called on by `two_d_double_gradient_descend()`

**Returns**: *double* - derivative

|        Argument       |        Type       | Description
|-----------------------|-------------------|------------
| **function(double)**  | double \*function  | Pointer to the processed function of type double. Takes a single double.
| x                     | double            | X-position at which to calculate the derivative
| dx                    | double            | Step size used to get the slope.

**Example:**
```c
double f(double x) {
  return x*x-x*2+1;
}

int main() {
  double dx = 0.00001;
  double x  = 2;

  double df = two_d_derive_double(&f, x, dx);

  printf("df/dx | (x=%f) = %f", x, df);
}
```


### n-dimensional

The n-dimensional functions assume a function that takes an array (vector) of doubles as an input and ouputs a single double value.

#### gradient_descent_double()

Finds extreme in function with n-dimensional inputs.

**Returns**: void

|        Argument       |        Type       | Description
|-----------------------|-------------------|------------
| **function( \*double)**| double \*function  | Pointer to the processed function of type double. Takes a double-array.
| **dimensions**        | unsigned int      | Number of dimensions in input vector -> Length of input-array.
| **start**             | double *          | Starting point of gradient descent. Array mus be of length dimensions
| **precision**         | double            | Step size at which the gradient descent will be terminated.
| **gamma**             | double            | Conversion rate between derivative and step size. Set this to a negative value to find the maximum value
| **max_iterations**    | unsigned int      | Maximum numbers of iterations before forcefull termination.
| **dx**                | double            | Step size in numerical derivation.
| double * output       | double *          | Will containt resting point after gradient descent.
| **iterations**        | double *          | Pointer to variable storing the iterations actually executed.

Example:
```c
double f(double *x) { //requires length of 3
  return 0.5*(x[0]-2)*(x[0]-2)+3*(x[1]+1)*(x[1]+1)-x[0];
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
  print_double_array(endpoint, dimensions); //Defined in the code, prints array of doubles.
  printf("Iterations:\t%u\n", iterations);
  printf("Dimensions:\t%u\n", dimensions);
}
```

#### get_gradient_double

Calculates the gradient of a function at the point x.

**Returns**: void

|        Argument       |        Type       | Description
|-----------------------|-------------------|------------
| **function( \*double)**| double * function  | Pointer to the processed function of type double. Takes a double-array.
| **x**                 | double *          | Position at which the gradient is calculated.
| **dx**                | double            | Step size for derivative.
| **gradient**          | double *          | Output array for the gradient. Must be of size dimensions
| **dimensions**        | unsigned int      | Length of x.

**Example:**
```c
double f(double *x) { //requires length of 3
  return 0.5*(x[0]-2)*(x[0]-2)+3*(x[1]+1)*(x[1]+1)-x[0];
}

int main() {
  unsigned int dimensions = 2;
  double x[] =  {3.0, 1.0}
  double dx = 0.0001;

  gradient[dimensions];

  get_gradient_double(&f, x, dx, gradient, dimensions);
  print_double_array(gradient, dimensions); //Defined in the code, prints array of doubles.
}
```

---
## vector_math.c
