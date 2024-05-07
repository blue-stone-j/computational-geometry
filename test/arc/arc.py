import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Arc

# draw points and arc

# 角度数据
theta1 = -np.pi+0.2  # θ1 = 0
theta2 = np.pi-0.1  # θ2 = π/2
mid_angle = -3.09159  # 计算中点角度

# 创建图和圆
fig, ax = plt.subplots()
circle = plt.Circle((0.5, 0.5), 0.4, color='blue', fill=False)
ax.add_artist(circle)

# 标记原始角度
ax.plot([0.5, 0.5 + 0.4 * np.cos(theta1)], [0.5, 0.5 + 0.4 * np.sin(theta1)], marker='o', color='red', label='Theta1')
ax.plot([0.5, 0.5 + 0.4 * np.cos(theta2)], [0.5, 0.5 + 0.4 * np.sin(theta2)], marker='o', color='green', label='Theta2')

# 标记中点角度
ax.plot([0.5, 0.5 + 0.4 * np.cos(mid_angle)], [0.5, 0.5 + 0.4 * np.sin(mid_angle)], marker='o', color='purple', label='Midpoint Angle')

arc = Arc((0.5, 0.5), 0.8, 0.8, angle=0, theta1=np.degrees(4.71), theta2=np.degrees(1.57), color='black', linewidth=2)
ax.add_patch(arc)

# 设置图形属性
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.set_aspect('equal', 'box')
plt.legend()
plt.show()
