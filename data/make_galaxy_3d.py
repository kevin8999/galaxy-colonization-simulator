import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation as animation

# Constants
G = 4.302e-6  # kpc * (km/s)^2 / Msun

# Galaxy parameters (example values)
M_smbh = 4e6
M_bulge = 1e10
a_bulge = 0.5
M_disk = 5e10
R_d = 3.0
rho_s = 0.015
r_s = 15.0

def M_bulge_enclosed(r):
    return M_bulge * r**2 / (r + a_bulge)**2

def M_disk_enclosed(r):
    return 2 * np.pi * M_disk / (2 * np.pi * R_d**2) * R_d**2 * (1 - (1 + r/R_d) * np.exp(-r / R_d))

def M_halo_enclosed(r):
    x = r / r_s
    return 4 * np.pi * rho_s * r_s**3 * (np.log(1 + x) - x / (1 + x))

def v_c(r):
    r = np.maximum(r, 1e-5)
    M_total = M_smbh + M_bulge_enclosed(r) + M_disk_enclosed(r) + M_halo_enclosed(r)
    return np.sqrt(G * M_total / r)

def omega(r):
    return v_c(r) / r

# Generate disk stars
N_stars = 1000
r_max = 20
r = np.random.exponential(scale=R_d, size=N_stars)
r = np.clip(r, 0.1, r_max)
theta = np.random.uniform(0, 2*np.pi, N_stars)

# Add vertical scatter (thickness)
z = np.random.normal(0, 0.3, N_stars)  # 0.3 kpc stddev

# Calculate angular velocities and convert units
w = omega(r)
conv = 3.154e13 / 3.086e16
w_rad_myr = w * conv

# Initial Cartesian coordinates
x = r * np.cos(theta)
y = r * np.sin(theta)

# Setup 3D plot
fig = plt.figure(figsize=(10,10))
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim(-r_max, r_max)
ax.set_ylim(-r_max, r_max)
ax.set_zlim(-3, 3)
ax.set_facecolor('black')
ax.axis('off')

scat = ax.scatter(x, y, z, s=1, color='white')

def update(frame):
    global theta
    dt = 1
    theta = (theta + w_rad_myr * dt) % (2 * np.pi)
    x = r * np.cos(theta)
    y = r * np.sin(theta)
    scat._offsets3d = (x, y, z)
    return scat,

ani = animation.FuncAnimation(fig, update, frames=360, interval=20, blit=False)
plt.show()
