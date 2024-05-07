import numpy as np
import json

# 设置随机种子以保证结果的可复现性
np.random.seed(5)

# 定义x的范围和数量
x_values = np.linspace(0, 10, num=30) 

# add noise to x
x_noise = np.abs(np.random.normal(0, 0.5, x_values.shape))
x_values_noisy = x_values + x_noise

# 计算y值并添加噪声，假设噪声标准差为0.1
noise = np.random.normal(0, 0.5, x_values.shape)
y_values = 0.3 * x_values_noisy + 1 + noise

# z值为0
z_values = np.zeros(x_values.shape)

# 创建点列表
points = [{"x": float(x), "y": float(y), "z": float(z)} for x, y, z in zip(x_values_noisy, y_values, z_values)]

# 将点列表保存为JSON格式
json_path = './poly.json'
with open(json_path, 'w') as json_file:
    json.dump(points, json_file, indent=4)

json_path
