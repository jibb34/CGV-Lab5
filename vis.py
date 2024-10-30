import numpy as np
import pandas as pd
import matplotlib.pyplot as mpl
from scipy.optimize import curve_fit

PATH = str("./")
mydata = np.genfromtxt("timing.csv", delimiter=',')
index_values = []
for x in range(10, 1002):
    index_values.append(x*10)
compTime = pd.Series(mydata, index=index_values)
mpl.plot(compTime, label='data')
mpl.show()
