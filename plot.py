# libraries
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
import pandas as pd

# y-axis in bold
rc('font', weight='bold')
 
# Values of each group
bars1 = [103.4,107.1,92.5,93.8,141.7]
bars2 = [85.3,90,69.6,70.8,114.3]
bars3 = [94.8,106.4,61.6,82.6,133.3]
 
 
# The position of the bars on the x-axis
r = [0,1,2,3,4]



# Names of group and bar width
names = ['10','30','60','80','90']
barWidth = 0.5
 
# Create brown bars
plt.plot(r, bars1, marker='o',color='#2980B9',label='BST not balanced')
# Create green bars (middle), on top of the first ones
plt.plot(r, bars2, marker='x', color='#1ABC9C',label='BST balanced')
# Create green bars (top)
plt.plot(r, bars3, marker='v', color='red',label='MAP Tree')
 
# Custom X axis
plt.xticks(r, names, fontweight='bold')
plt.xlabel("Number of bst nodes")
plt.ylabel("Time(nano seconds)")
plt.title("Timing")
#plt.xscale('log')

plt.legend()
# Show graphic
plt.show()

