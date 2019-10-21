# A-Proyecto
Transició de fase i components connexes en grafs aleatoris | FIB-A

## G08
- BOYANO IVARS, PAULA
- MARQUÉS GODÓ, JORDI
- QUINTANA TORRES, JOSEP
- RUBINSTEIN PÉREZ, FEDERICO

## Contenido

- **doc/**							: _documentacion del proyecto_
	- **Informe_G08.pdf**			: _informe final con los experimentos realizados, los resultados obtenidos y las conclusiones sacadas_
	- **doxygen/**					: _ficheros Doxygen_
		- **index.html**			: _Fichero HTML generado con Doxygen con las especificaciones de las clases y funciones implementadas y sus variables y parametros_
		
- **src/**							: _codigo fuente_
	- **main.cpp**					: _Fichero Main del proyecto_
	- **Graph.{.h, .cpp}**			: _Especificación y Implementacion de la Clase C++ 'Graph' que define un grafo, sus caracteristicas y genera ERGraphs y RGGraphs_
	- **GreatGraph._{.h, .cpp}_**		: _Especificación y Implementacion de la Clase C++ 'GreatGraph' para experimentar sobre la transición de fase del tamaño esperado de la componente conexa más grande_
	- **probConnex.{.h, .cpp}**		: _Especificación y Implementacion de la Clase C++ 'probConnex' para experimentar sobre la transición de fase de la probabilidad de que un grafo sea conexo_
	- **UnionFind.{.h, .cpp}**		: _Especificación y Implementacion de la Clase C++ 'UnionFind' que define el conjunto disyunto Union-Find y sus operaciones_
	- **creaGrafics.py**			: _Fichero Python para generar graficos a partir de los datos obtenidos con los experimentos_
	- **Makefile**					: _Fitchero Makefile para compilar y ejecutar el codigo fuente_
	
- **data/**
	- **dataERG.csv**				: Fichero con los resultados del experimento de la transición de fase de la probabilidad de ser conexo para un grafo Erdős-Rényi (ERG)
	- **dataGG.csv**				: Fichero con los resultados del experimento de la transición de fase del tamaño esperado de la componente conexa más grande
	- **dataRGG.csv**				: Fichero con los resultados del experimento de la transición de fase de la probabilidad de ser conexo para un grafo Aleatorio Geometrico (RGG)
	- **ERG/**						: Subdirectorio con los graficos referentes al experimento con grafo Erdős-Rényi
	- **GG/**						: Subdirectorio con los graficos referentes al experimento con la componente conexa más grande
	- **RGG/**						: Subdirectorio con los graficos referentes al experimento con grafo Aleatorio Geometrico
	- **URIG/**						: Subdirectorio con los graficos referentes al experimento extra

## Instrucciones

1. Desde el directorio ***src/*** ejecutar `make` para compilar el codigo fuente
2. Para ejecutar el ejecutable generado usar `./main.x`
3. Una vez finalizado, se han generado los arhivos de resultados en el directorio ***data/***
4. Para generar los graficos ejecutar `python creaGrafics.py`
5. Los graficos se han generado en el subdirectorio correspondiente de ***data/***

