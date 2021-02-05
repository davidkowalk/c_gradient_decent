# c_gradient_decent

This project supplies the tools for simple gradient descent in either two dimensions (1 input and 1 output) or generalized concepts in more dimensions.

It can find either minimums or maximums by adjusting the gamma-scalar (see documentation) from a supplied function. Derivatives are determined numerically with a supplied step-size.

See the documentation ind `/docs/` for more information.

## Installation

To install this api in your project copy the following files into your workspace:

- gradient_descent.h
- gradient_descent.c
- vector_math.c

Please note that gradient_descent.c will try to include vector_math.c regardless of whether or not it's functions are already defined.
