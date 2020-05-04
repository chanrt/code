import numpy as np
import matplotlib.pyplot as plt
# import pandas as pd
from sklearn.linear_model import LinearRegression



algo = input("Which algorithm? : ")
with open("c:\\Users\\dirac\\Desktop\\Programs\\Algos_project\\Raw_data\\" + algo + "_sort_runtimes.txt") as twodimarray:
    raw_data = [line.split() for line in twodimarray]

data = np.array(raw_data).astype(np.float)
means = []
sds = []

x_ax = np.array([10000,20000,30000,40000,50000,60000,70000,80000,90000,100000])

row_num = 0
while row_num < 10:
    row_array = data[row_num, :].copy()
    means.append(row_array.mean())
    sds.append(row_array.std())
    row_num += 1

means = np.array(means)
sds = np.array(sds)

print("Means:")
for mean in means:
    print(f"%.4f" % (mean))

print("\nStandard Deviations:")
for sd in sds:
    print(f"%.4f" % (sd))

log_x_ax = np.log10(x_ax)
log_means = np.log10(means)

y_learn = log_means.reshape(10,1)
x_learn = log_x_ax.reshape(10,1)

model = LinearRegression().fit(x_learn, y_learn)
print(f"\nSlope: %f\nIntercept: %f" % (model.coef_,model.intercept_))
print(f"\nAntilog of intercept: %f" % (np.exp(model.intercept_)))

plt.plot(x_ax, means)
ax = plt.gca()

ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))
plt.tick_params(axis = 'both', which = 'major')
plt.xlabel("Number of elements sorted", fontsize = 10)
plt.ylabel("Runtime (in seconds)", fontsize = 10)
plt.title("Algorithmic Analysis of " + algo.title() + " sort")

plt.show()

plt.plot(log_x_ax, log_means)
ax = plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))

plt.show()


    