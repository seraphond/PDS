set title "Temps et vitesse d'execution"
set logscale x
set xlabel "taille"
set logscale y
set ylabel "temps en s ou vitesse en octets/s"
set style data linespoints
plot "graph.dat" using 1:4 title "Real", \
     "graph.dat" using 2:4 title "user", \
	"graph.dat" using 3:4 title "sys"
