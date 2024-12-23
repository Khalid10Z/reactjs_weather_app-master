import matplotlib.pyplot as plt
from scipy.integrate import odeint
import numpy as np

#theta -> angle
#omega (derivée de theta) -> vitesse

def pendule(y, t, k, g):
    theta, omega = y
    dydt = [omega, -k/m * omega - g/l * np.sin(theta)]
    return dydt

k0 = 0.15 #à déterminer expérimentalement (coeff de frottements visqueux)
g = 9.80665
l = 0.25
m = 0.144
y0 = [np.pi/4, 0.0] # initialisation
t = np.linspace(0, 10, 100) # discretisation du temps continu

graduation = np.arange(0,11,1)

sol0 = odeint(pendule, y0, t, args=(k0, g))

plt.plot(t[0:2],sol0[0:2,0],color='blue',label='theta') #uniquement l'angle theta
plt.xlabel('temps (en s)')
plt.ylabel('angle (en rad)')
plt.xticks(graduation)
plt.savefig('angle.png',dpi=200)
plt.figure()
plt.plot(t,sol0[:,1],color='orange',label='vitesse') #uniquement la vitesse du pendule
plt.xlabel('t')
plt.ylabel('vitesse en rad/s')
plt.xticks(graduation)
plt.show()