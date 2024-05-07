import matplotlib.pyplot as plt
import json

json_path = './ps.json'
# json_path = './poly.json'
# 读取之前保存的带噪声的点数据
with open(json_path, 'r') as file:
    points_loaded = json.load(file)

# 提取x, y, z坐标
x_loaded = [point['x'] for point in points_loaded]
y_loaded = [point['y'] for point in points_loaded]
z_loaded = [point['z'] for point in points_loaded]

# 绘制这些点及其连接线
plt.figure(figsize=(10, 6))
plt.plot(x_loaded, y_loaded, marker='o', linestyle='-', color='b')
plt.title('Plot of the Points with Noise')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.show()
