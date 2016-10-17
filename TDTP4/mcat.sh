#! /bin/sh -uf
#
# mcat -- campagne d'appels à mcat-scd
#
# squelette de shell script

# La commande à tester
MCAT=./mcat_scd.beta
# le fichier à lui mettre en entrée
MCAT_INPUT=9MJ3NEJ5VX_1.txt
# Le fichier de temps à générer
TIME_FILE=mcat-tm.dat

# la commande gnu time
TIME_CMD="/usr/bin/time"
# les options de cette commande
TIME_OPT="-f %e:%U:%S"

# initialisation du fichier de résultats
rm -f $TIME_FILE && echo "# real user sys" > $TIME_FILE

# un exemple de boucle
#for str in  foo bar gee ; do
#	 echo $str
#done

# un autre exemple de boucle
for size in `awk 'BEGIN { for( i=1; i<=8388608; i*=2 ) print i }'`; do
    export MCAT_BUFSIZ=$size
	time $TIME_OPT $MCAT $MCAT_INPUT>> /dev/null 2>>$TIME_FILE
    echo '#buf_size:'$MCAT_BUFSIZ >> $TIME_FILE
done

sed -e 's/:/ /g' $TIME_FILE > graph.dat

# un exemple de redirection des sorties standard et d'erreur
$TIME_CMD "$TIME_OPT" ls > /dev/null 2>> $TIME_FILE

# eof
