#include <math.h>
#define uint unsigned integer

//Adds vec2 to vec1 and saves into vec1
void add_vec_double(double *vec1, double *vec2, uint len) {
  for(unsigned int i = 0; i<len; i++) {
    vec1[i] += vec2[i];
  }
}

//Subtracts vec2 from vec1, saves into vec1
void subtract_vec_double(double *vec1, double *vec2, uint len) {
  for (unsigned int i = 0; i<len; i++) {
    vec1[i] -= vec2[i];
  }
}

void scale_vec_double(double scalar, double vector, uint len) {
  for (unsigned int i = 0; i<len; i++) {
    vector[i] *= scalar
  }
}

//get distance between two points
double get_distance(double *vec1, double *vec2, uint dimensions) {
  double summ = 0;

  for(uint d = 0; d<dimensions; d++) {
    summ += (vec2[d]-vec1[d])*(vec2[d]-vec1[d]);
  }

  return sqrt(summ);
}

//Copies source to vec
void copy_double_vec(double source, double vec, uint len) {
  for(unsigned int i = 0; i<len, i++) {
    vec[i] = source[i]
  }
}
