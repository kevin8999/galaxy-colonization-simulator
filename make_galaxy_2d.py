import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import csv

# Parameters
num_arms = 3
num_stars = 100000
arm_spread = 0.5
arm_rotation = 4
disk_radius = 10

# Dark matter-inspired rotation curve
def rotation_speed(r, vmax=1.0, rc=2.0):
    return vmax * r / np.sqrt(r**2 + rc**2)

# Clamp function for colors
def clamp(val, min_val=0.0, max_val=1.0):
    return max(min(val, max_val), min_val)

def create_galaxy(num_stars):
    # Generate stars with initial positions and motion
    stars_r = []
    stars_theta = []
    stars_omega = []
    stars_color = []

    for i in range(num_stars):
        r = disk_radius * np.random.beta(2, 5)
        arm_offset = (2 * np.pi / num_arms) * (i % num_arms)
        spiral_theta = arm_rotation * np.log1p(r) + arm_offset
        delta_theta = np.random.normal(0, arm_spread)
        delta_r = np.random.normal(0, 0.3)

        final_r = r + delta_r
        final_theta = spiral_theta + delta_theta

        stars_r.append(final_r)
        stars_theta.append(final_theta)
        stars_omega.append(rotation_speed(final_r) / final_r)

        t = final_r / disk_radius
        color = (clamp(1.0), clamp(1.0 - t), clamp(0.8 - t))
        stars_color.append(color)

    # Convert to NumPy arrays
    stars_r = np.array(stars_r)
    stars_theta = np.array(stars_theta)
    stars_omega = np.array(stars_omega)
    stars_color = np.array(stars_color)

    # Initial positions
    x_init = stars_r * np.cos(stars_theta)
    y_init = stars_r * np.sin(stars_theta)

    # Setup plot
    fig, ax = plt.subplots(figsize=(8, 8), facecolor='black')
    ax.set_facecolor('black')
    ax.axis('off')
    ax.set_aspect('equal')
    sc = ax.scatter(x_init, y_init, s=0.5, color=stars_color, alpha=0.8)

# Update function
def update(frame):
    global stars_theta
    stars_theta -= stars_omega * 0.1
    x = stars_r * np.cos(stars_theta)
    y = stars_r * np.sin(stars_theta)
    sc.set_offsets(np.c_[x, y])
    return sc,

# Animate galaxy
def animate():
    ani = animation.FuncAnimation(fig, update, frames=300, interval=20, blit=True)

    # Show or save the animation
    plt.show()
    # ani.save('rotating_galaxy.mp4', fps=20, dpi=200)  # Uncomment to save

def save_data():
    # Save galaxy data to CSV
    with open("galaxy_data.csv", mode="w", newline="") as file:
        writer = csv.writer(file)
        writer.writerow(["ID", "Radius", "AngularVelocity"])
        for i in range(num_stars):
            writer.writerow([i + 1, stars_r[i], stars_omega[i]])

if __name__ == "__main__":
    create_galaxy(num_stars)
