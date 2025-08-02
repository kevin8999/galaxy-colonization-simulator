# Solar Sails
## Acceleration
This section describes how to get the acceleration ($a$) of a spaceship of mass $m$ given the radiation pressure ($P$) of a star.

---

Pressure is broadly defined as the force divided by area [^2]:

[^2]: https://phys.libretexts.org/Bookshelves/College_Physics/College_Physics_1e_%28OpenStax%29/11%3A_Fluid_Statics/11.03%3A_Pressure

$$P = \frac{F}{A}$$

where

- $F$ is force in Newtons
- $A$ is area in metres squared ($\text{m}^2$).

which can be rearranged as:

$$F = PA$$

Radiation pressure $P$ is defined as [^3]:

[^3]: https://openstax.org/books/university-physics-volume-2/pages/16-key-equations

$$P = \frac{2I}{c}$$

where

- $I$ is the intensity of light in $\text{W/m}^2$ (Watts per metre squared)
- $c$ is the speed of light ($\approx 3 \times 10^8 \text{ m/s}$ (metres per second)
- **Note that this assumes the sail perfectly reflects light!**

Thus, the force on a sail of area $A_{\text{sail}}$ is:

$$F = \frac{2I}{c} \cdot A_{\text{sail}}$$

---

Force $F$ is also defined as[^4]:

[^4]: https://openstax.org/books/college-physics-2e/pages/4-3-newtons-second-law-of-motion-concept-of-a-system

$$F = ma$$

where

- $m$ is the mass in kilograms
- $a$ is the acceleration in metres per second squared

To get acceleration $a$:

$$\begin{align}
F &= ma \\
a &= \frac{F}{m} \\
& \boxed{= \frac{2I }{c} \cdot A_{\text{sail}} \cdot \frac{1}{m}}
\end{align}$$

where

- $I$ is the intensity of light in $\text{W/m}^2$ (Watts per metre squared)
- $c$ is the speed of light (approximately $3 \times 10^8 \text{ m/s}$ (metres per second)
- $a$ is acceleration in $\text{m/s}^2$ (metres per second squared)
- $A_{\text{sail}}$ is the area of the sail in $\text{m}^2$ (metres squared)
- $m$ is the total mass of the spacecraft in kilograms ($\text{kg}$)

---

The apparent brightness $I$ is determined using [^5]:

[^5]: https://www.e-education.psu.edu/astro801/content/l4_p4.html

$$I = \frac{P_{\text{star}}}{A_{\text{star}}} =  \frac{P_{\text{star}}}{4\pi r^2}$$

where

- $P_{\text{star}}$ is the total power (or luminosity) of the star
- $A_{\text{star}}$ is the area of the sphere at distance $r$ (which can be found using $A_\text{star} = 4\pi r^2$).
- $r$ is the distance between the spacecraft and the star


Substituting the above for $I$, we get:

$$\begin{align}
a &= \frac{2I }{c} \cdot A_{\text{sail}} \cdot \frac{1}{m} \\\\
&\boxed{= \frac{2}{c} \left( \frac{ P_\text{star} } {4\pi r^2} \right) \cdot A_\text{sail} \cdot \frac{1}{m}}
\end{align}$$

The meaning of the variables is defined in the table below.

| Symbol          | Quantity Description                              | Unit Name                 | Unit Symbol    |
| --------------- | ------------------------------------------------- | ------------------------- | -------------- |
| $a$             | Acceleration                                      | metres per second squared | $\text{m/s}^2$ |
| $c$             | Speed of light ($\approx 3 \times 10^8$)          | metres per second         | $\text{m/s}$   |
| $P_\text{star}$ | Power output of the star                          | watts                     | $\text{W}$     |
| $r$             | Distance to the star (point source approximation) | metres                    | $\text{m}$     |
| $A_\text{sail}$ | Area of the solar sail                            | square metres             | $\text{m}^2$   |
| $m$             | Mass of the spacecraft                            | kilograms                 | $\text{kg}$    |

Note that the above formula can be combined into one fraction to get:

$$\boxed{a = \frac{2 \cdot P_\text{star} \cdot A_\text{sail}}{cm \cdot 4\pi r^2}}$$


## Minimum Time to Travel Between Stars
Knowns:

- Launch at time $t_0 = 0$.
- $v_\text{max}$ can be calculated
- $a_0$ (acceleration from the original star) and $a_1$ (deceleration at the destination star) are known
- $v_2 = 0$
- $v_1 = 0$
- Position of $\mathbf{A}$ and $\mathbf{B}$.

### Why We Don't Need to Factor in Acceleration for Travel Time

From the [Acceleration](#acceleration) section, we know that acceleration $a$ can be found using:

$$a = \frac{2 \cdot P_\text{star} \cdot A_\text{sail}}{cm \cdot 4\pi r^2}$$

The only variable that changes is $r$. Thus, $a$ varies inversely with the square of the distance $r$. That is,

$$
a \propto \frac{1}{r^2}.
$$

To find the total amount of acceleration experienced between two points $a$ and $b$, we integrate $\dfrac{1}{r^2}$ over the interval $[a, b]$:

$$
\begin{aligned}
\int_a^b \frac{1}{r^2} \, dr &= \int_a^b r^{-2} \, dr \\
&= -1 \cdot r^{-1} \Bigg|_{a}^{b} \\
&= \left(-\frac{1}{r}\right) \Bigg|_a^b \\
&= \left(-\frac{1}{b}\right) - \left(-\frac{1}{a}\right) \\
&= - \frac{1}{b} + \frac{1}{a} \\\\
&\boxed{= \frac{1}{a} - \frac{1}{b}}.
\end{aligned}
$$

Note that constants are removed as we are only interested in how total acceleration accumulates.

Now, if we let $b$ be a constant multiple of $a$, and set $a = 1$, then

$$
\int_1^b \frac{1}{r^2} \, dr = 1 - \frac{1}{b}.
$$

Here, $b$ represents a distance greater than $a$ by some constant factor.

This equation tells us that the majority of the acceleration happens at very small distances. Additionally, the further you move away from a star, the faster acceleration will decrease.

Many planets are close to their stars, so calculating the acceleration part is negligible and only adds unnecessary computational resources to our simulation.



### Calculating Trajectory from Star A to Star B

This section goes over how to calculate the trajectory between star $A$ and a moving target star $B$.

- Objects in circular motion require centripetal acceleration.

#todo: calculate path between two paths between Star A and B

- https://openstax.org/books/physics/pages/6-2-uniform-circular-motion
- Desmos visualization: https://www.desmos.com/calculator/ywye0tnu9e

Let star $A$ be defined as

$$A = (r_1 , \theta_1 , \omega_1)$$

where

- $r_1$ is the distance between $A$ and the centre
- $\theta_1$ is the current angle that $A$ is at (relative to the positive $x$ axis)
- $\omega_1$ is the angular velocity of $A$

Let star $B$ be similarly defined as

$$B = (r_2 , \theta_2 , \omega_2)$$

- $r_2$ is the distance between $B$ and the centre
- $\theta_2$ is the current angle that $B$ is at (relative to the positive $x$ axis)
- $\omega_2$ is the angular velocity of $B$

We can define parametric equations for star $A$ and $B$ to map their polar coordinates at time $t$ to an Cartesian coordinate.

$$f(r, \theta, \omega, t) = \begin{bmatrix} r_{i}\cos\left(\theta_{i}+w_{i}\cdot t\right) \\ r_{i}\sin\left(\theta_{i}+w_{i}\cdot t\right) \end{bmatrix}$$

which can be converted to

$$\begin{align}
x_i &= r_{i}\cos\left(\theta_{i}+w_{i}\cdot t\right) \\
y_i &= r_{i}\sin\left(\theta_{i}+w_{i}\cdot t\right)
\end{align}$$

