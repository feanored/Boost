import numpy as np
import pandas as pd
from math import pi, sin, cos
import matplotlib.pyplot as plt

pasta = "C:/Users/eduar/OneDrive/Mestrado/Exame/metodos/dados/"

def plotar(nome, x, y, titulo):
	arq = pd.read_csv(pasta+nome+".csv", header=0, sep=";")
	plt.plot(arq[x], arq[y], "r-", label="%s(%s)"%(y, x))
	plt.title("Simulações: %s"%titulo)
	plt.xlabel("%s"%x)
	plt.ylabel("%s"%y)
	ymin, ymax = np.min(arq[y]), np.max(arq[y])
	uni = (ymax-ymin)/20
	plt.yticks(np.arange(ymin, ymax+uni*0.1, uni))
	plt.legend()
	plt.show()

# plotar("dipolo", "x", "theta", "Dipolo num campo elétrico constante")


def exe_3_f(x):
	if x < 0:
		return 0
	return 2*x

def exe_3_F(x):
	s = 3/2
	for n in range(1, 101):
		s += 6/((n*pi)**2)*cos(n*pi*x/3)*((-1)**n-1) - 6/(n*pi)*sin(n*pi*x/3)*(-1)**n
	return s

def exe_6_f(x):
	if x <= 0:
		return 0
	return 3

def exe_6_F(x):
	s = 3/2
	for k in range(1, 101):
		n = 2*k-1
		s += 6/(n*pi)*sin(n*pi*x/5)
	return s

def fourier(f, F, L):
	X, fList, FList = [], [], []
	dx = 0.01
	x = -L
	while x < L:
		X.append(x)
		fList.append(f(x))
		FList.append(F(x))
		x += dx
	plt.plot(X, fList, "b-")
	plt.plot(X, FList, "r-.")
	plt.title("Séries de Fourier")
	plt.show()

fourier(exe_3_f, exe_3_F, 3)
fourier(exe_6_f, exe_6_F, 5)