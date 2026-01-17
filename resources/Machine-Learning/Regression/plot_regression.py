import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("data_multifeature.csv")
plt.scatter(df['area'], df['price'] * 1000, label='Training data')
m = 0.2
b = 0
x = np.linspace(df['area'].min(), df['area'].max(), 100)
plt.plot(x, m * x * 1000 + b, color='red', label='Regression line')

plt.xlabel('Area (sqft)')
plt.ylabel('Price ($)')
plt.legend()
plt.show()
