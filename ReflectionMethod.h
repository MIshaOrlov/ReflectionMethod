//
//  ReflectionMethod.h
//  somecode6.1
//
//  Created by Михаил on 04.10.2023.
//

#ifndef ReflectionMethod_h
#define ReflectionMethod_h
#include <math.h>
#include "MatrixHandlers.h"

int ReflectionInverse(int n, double* matrix, double* adjoint);

double ResidualCalc( double* a,  double* b, double* result, int n);

#endif /* ReflectionMethod_h */
