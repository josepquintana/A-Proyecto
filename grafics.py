import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import csv

dtb = pd.read_csv("data.csv")

dtb.head()

ax = sns.kdeplot(dtb.arista_number,dtb.p_value)
fig = ax.get_figure()
fig.savefig("grafic.png")
