import pandas as pd
import seaborn as sns
import matplotlib as mpl
import matplotlib.pyplot as plt
import networkx as nx
import random
import importlib
import csv

dtb_giant = pd.read_csv("data/dataGG.csv")
dtb_erg = pd.read_csv("data/dataERG.csv")
dtb_rrg = pd.read_csv("data/dataRRG.csv")


plist = [0] * 400
rclist = [0] * 400
vlist = [0] * 400
for k in range(4):
    vertex = random.randint(10, 100) + 10

    for item in range(100):
        vlist[k * item] = vertex
        p = item / 100
        dtb = nx.uniform_random_intersection_graph(vertex, 20, p)
        rc = nx.number_connected_components(dtb)
        plist[k * item] = p
        rclist[k * item] = rc


dtb_cave = pd.DataFrame({"p": plist, "componentes": rclist, "vertices": vlist})

ax = sns.lineplot(dtb_cave.p, dtb_cave.componentes, dtb_cave.vertices)
fig = ax.get_figure()
fig.savefig("../data/graficuniform.png")
importlib.reload(mpl)
importlib.reload(plt)
importlib.reload(sns)
ax1 = sns.lineplot(
    dtb_giant.p_value, dtb_giant.greatest_component, dtb_giant.vertex_number
)
fig1 = ax1.get_figure()
fig1.savefig("../data/graficgiant.png")
importlib.reload(mpl)
importlib.reload(plt)
importlib.reload(sns)
ax2 = sns.lineplot(dtb_erg.p_value, dtb_erg.n_connexions, dtb_erg.vertex_number)
fig2 = ax2.get_figure()
fig2.savefig("../data/graficerg.png")
importlib.reload(mpl)
importlib.reload(plt)
importlib.reload(sns)
ax3 = sns.lineplot(dtb_rrg.r_value, dtb_rrg.n_connexions, dtb_rrg.vertex_number)
fig3 = ax3.get_figure()
fig3.savefig("../data/graficrrg.png")

