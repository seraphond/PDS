#!/bin/bash


echo '#commande origininale' &>>mdu_log.txt

du -B 512 -L mdu.c &>> mdu_log.txt

echo '#commande mdu' &>> mdu_log.txt

./mdu.beta -L mdu.c &>> mdu_log.txt

echo '#commande originale avec option -b' &>>mdu_log.txt

du -b mdu.c &>> mdu_log.txt

echo '#commande mdu avec option -b ' &>>mdu_log.txt

./mdu.beta -b mdu.c &>> mdu_log.txt


#les commandes sont bien identiques
