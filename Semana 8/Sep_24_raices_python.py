import numpy as np

f1 = lambda x: np.sin(10*x) - np.cos(3*x)
f2 = lambda x: np.exp(-x) - x
f3 = lambda x: x**10 - 1
f4 = lambda x: x**3 - 5*(x**2) - 7*x - 3  

import scipy as sp

r1_1 = sp.optimize.root_scalar(f1, method='bisect', bracket=[3, 5])

r2_2 = sp.optimize.root_scalar(f2, method='newton', x0=0)

r2_3 = sp.optimize.root_scalar(f2, method='secant', x0=0)

r3_2 = sp.optimize.root_scalar(f3, method='newton', x0=0.5)

r3_3 = sp.optimize.root_scalar(f3, method='secant', x0=0.5)

r4_2_1 = sp.optimize.root_scalar(f4, method='newton', x0=0)

r4_3_1 = sp.optimize.root_scalar(f4, method='secant', x0=0)

r4_2_2 = sp.optimize.root_scalar(f4, method='newton', x0=4)

r4_3_2 = sp.optimize.root_scalar(f4, method='secant', x0=4)

print("f(x)=sen(10x)-cos(3x) en el rango [3,5], método de bisección")
print("Resultado C: 4.470728 en 18 iteraciones")
print("Resultado Python: ")
print(r1_1)

print("")

print("f(x) = exp(-x) - x, con x0 = 0, método de Newton")
print("Resultado C: 0.567143290410 en 4 iteraciones")
print("Resultado Python: ")
print(r2_2)

print("")

print("f(x) = exp(-x) - x, con x0 = 0, método de la secante")
print("Resultado C: 0.567143290410 en 5 iteraciones")
print("Resultado Python: ")
print(r2_3)

print("")

print("f(x) = x^10 - 1, con x0 = 0.5, método de Newton")
print("Resultado C: No converge")
print("Resultado Python: ")
print(r3_2)

print("")

print("f(x) = x^10 - 1, con x0 = 0.5, método de la secante")
print("Resultado C: 0.5 en 2 iteraciones")
print("Resultado Python: ")
print(r3_3)

print("")

print("f(x) = x^3 - 5x^2 - 7x - 3, con x0 = 0, método de Newton")
print("Resultado C: -")
print("Resultado Python: ")
print(r4_2_1)

print("")

print("f(x) = x^3 - 5x^2 - 7x - 3, con x0 = 0, método de la secante")
print("Resultado C: -")
print("Resultado Python: ")
print(r4_3_1)

print("")

print("f(x) = x^3 - 5x^2 - 7x - 3, con x0 = 4, método de Newton")
print("Resultado C: No converge")
print("Resultado Python: ")
print(r4_2_2)

print("")

print("f(x) = x^3 - 5x^2 - 7x - 3, con x0 = 4, método de la secante")
print("Resultado C: 6.140054944640 en 22 iteraciones")
print("Resultado Python: ")
print(r4_3_2)