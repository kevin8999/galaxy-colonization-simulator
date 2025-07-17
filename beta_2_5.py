import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import beta

x = np.linspace(0, 1, 1000)
y = beta.pdf(x, 2, 5)

plt.plot(x, y, label='Beta(2, 5)')
plt.fill_between(x, y, alpha=0.3)
plt.title('Beta(2, 5) Distribution')
plt.xlabel('Value (e.g., normalized radius)')
plt.ylabel('Density')
plt.grid(True)
plt.legend()
plt.savefig("beta_2_5_distribution.png", dpi=300)  # Save before show()
plt.show()

