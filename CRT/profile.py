import matplotlib.pyplot as plt
import numpy as np

num_points = 1000
circle_radius = 1.0
inner_clear_radius = 0.3

def quadratic_bezier(p0, p1, p2, t):
    return (1 - t)**2 * p0 + 2 * (1 - t) * t * p1 + t**2 * p2

fig, ax = plt.subplots(figsize=(8, 8))
ax.set_aspect('equal')
ax.axis('off')

theta = np.linspace(0, 2 * np.pi, num_points)
x = circle_radius * np.cos(theta)
y = circle_radius * np.sin(theta)

ax.plot(x, y, color='black', linewidth=1.2)

for i in range(0, num_points, 10):
    for j in range(i + 20, num_points, 100):
        p0 = np.array([x[i], y[i]])
        p2 = np.array([x[j], y[j]])
        
        midpoint = (p0 + p2) / 2
        
        # Vector from midpoint to center (0,0)
        vec_to_center = -midpoint
        dist_to_center = np.linalg.norm(vec_to_center)
        
        # Normalize direction
        dir_to_center = vec_to_center / dist_to_center if dist_to_center != 0 else np.zeros_like(vec_to_center)
        
        # Physics-inspired force magnitude (e.g., inverse linear with some clamp)
        force_magnitude = min(0.8, 0.5 + 0.5 * (1 - dist_to_center))  # stronger when farther, max 0.8
        
        # Random noise to add clumsiness
        noise = np.random.uniform(-0.15, 0.15, size=2)
        
        # Compute control point with force + noise
        proposed_p1 = midpoint + force_magnitude * dir_to_center + noise
        
        # Keep control point outside the clear center radius
        dist_p1 = np.linalg.norm(proposed_p1)
        if dist_p1 < inner_clear_radius:
            p1 = proposed_p1 / dist_p1 * inner_clear_radius if dist_p1 != 0 else np.array([inner_clear_radius, 0])
        else:
            p1 = proposed_p1
        
        t_vals = np.linspace(0, 1, 100)
        curve = np.array([
            quadratic_bezier(p0[0], p1[0], p2[0], t_vals),
            quadratic_bezier(p0[1], p1[1], p2[1], t_vals)
        ])
        
        alpha = 0.3 + 0.6 * np.random.rand()
        lw = 0.3 + 1.0 * np.random.rand()
        
        ax.plot(curve[0], curve[1], color='black', alpha=alpha, linewidth=lw)

plt.tight_layout()
plt.savefig("roots_with_physics.png", dpi=300)
plt.show()
