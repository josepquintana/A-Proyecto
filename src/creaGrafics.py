import pandas as pd
import seaborn as sns
import matplotlib as mpl
import matplotlib.pyplot as plt
import networkx as nx
import time
import random
import importlib
import csv

dtb_erg = pd.read_csv("../data/dataERG.csv", encoding = "utf-8")
dtb_rgg = pd.read_csv("../data/dataRGG.csv", encoding = "utf-8")
dtb_giant = pd.read_csv("../data/dataGG.csv", encoding = "utf-8")

#ERG:
graficosERG = sns.pairplot(dtb_erg, hue="vertex_number", diag_kind="hist")
graficosERG.savefig("../data/ERG/graficosERG.png")

p_y_connexionsERG = sns.lineplot(data=dtb_erg, x="p_value", y="n_connexions", hue="vertex_number")
p_y_connexionsERG.get_figure().savefig("../data/ERG/p_y_connexionsERG.png")

vertex_y_timeERG = sns.lineplot(data=dtb_erg, x="vertex_number", y="computation_time")
vertex_y_timeERG.get_figure().savefig("../data/ERG/vertex_y_timeERG.png")

es_connex_y_pVERG = sns.lineplot(data=dtb_erg, x="p_value", y="és_connex", hue="vertex_number", n_boot = 0)
es_connex_y_pVERG.get_figure().savefig("../data/ERG/es_connex_y_pVERG.png")

es_connex_y_pERG = sns.lineplot(data=dtb_erg, x="p_value", y="és_connex")
es_connex_y_pERG.get_figure().savefig("../data/ERG/es_connex_y_pERG.png")

p_y_connexionsECERG = sns.lineplot(data=dtb_erg, x="p_value", y="n_connexions", hue="és_connex")
p_y_connexionsECERG.get_figure().savefig("../data/ERG/p_y_connexionsECERG.png")

p_y_timeERG = sns.lineplot(data=dtb_erg, x="p_value", y="computation_time", hue="vertex_number")
p_y_timeERG.get_figure().savefig("../data/ERG/p_y_timeERG.png")


#RGG:
graficosRGG = sns.pairplot(dtb_rgg, hue="vertex_number", diag_kind='hist')
graficosRGG.savefig("../data/RGG/graficosRGG.png")

r_y_connexionsRGG = sns.lineplot(data=dtb_rgg, x="r_value", y="n_connexions", hue="vertex_number")
r_y_connexionsRGG.get_figure().savefig("../data/RGG/r_y_connexionsRGG.png")

vertex_y_timeRGG = sns.lineplot(data=dtb_rgg, x="vertex_number", y="computation_time")
vertex_y_timeRGG.get_figure().savefig("../data/RGG/vertex_y_timeRGG.png")

r_y_timeRGG = sns.lineplot(data=dtb_rgg, x="r_value", y="computation_time", hue="vertex_number")
r_y_timeRGG.get_figure().savefig("../data/RGG/r_y_timeRGG.png")

r_y_connexRGG = sns.lineplot(data=dtb_rgg, x="r_value", y="és_connex")
r_y_connexRGG.get_figure().savefig("../data/RGG/r_y_connexRGG.png")

r_y_connexVRGG = sns.lineplot(data=dtb_rgg, x="r_value", y="és_connex", hue="vertex_number", n_boot = 0)
r_y_connexVRGG.get_figure().savefig("../data/RGG/r_y_connexVRGG.png")


#GG:
graficosGiant = sns.pairplot(dtb_giant, hue="vertex_number", diag_kind="hist")
graficosGiant.savefig("../data/GG/graficosGG.png")

greatest_y_pGiant = sns.lineplot(data=dtb_giant, x="p_value", y="greatest_component", hue="vertex_number")
greatest_y_pGiant.get_figure().savefig("../data/GG/greatest_y_pGG.png")

greatest_y_timeGiant = sns.lineplot(data=dtb_giant, x="greatest_component", y="computation_time")
greatest_y_timeGiant.get_figure().savefig("../data/GG/greatest_y_timeGG.png")

greatest_y_vertexGiant = sns.lineplot(data=dtb_giant, x="vertex_number", y="greatest_component", hue="is_giant")
greatest_y_vertexGiant.get_figure().savefig("../data/GG/greatest_y_vertexGG.png")

greatest_y_aristaGiant = sns.lineplot(data=dtb_giant, x="greatest_component", y="arista_number", hue="vertex_number")
greatest_y_aristaGiant.get_figure().savefig("../data/GG/greatest_y_aristaGG.png")


#Grafo extra: URIG
plist = [0] * 1000
rclist = [0] * 1000
vlist = [0] * 1000
vtimer = [0] * 1000
vertex = 0
for k in range(10):
    vertex = vertex +100

    for item in range(20):
        vlist[k * item] = vertex
        p = item / 20
        dtb = nx.uniform_random_intersection_graph(vertex, 20, p)
        ts = time.time()
        rc = nx.number_connected_components(dtb)
        plist[k * item] = p
        rclist[k * item] = rc
        vtimer[k * item] = time.time() -ts


dtb_cave = pd.DataFrame({"p": plist, "componentes": rclist, "vertices": vlist, "computation_time" : vtimer})

sns.pairplot(dtb_cave, hue="vertices", diag_kind='hist')
graficosGiant.savefig("../data/URIG/graficosURIG.png")

