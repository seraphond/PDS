#!/bin/bash



echo'#test de fichier inexistant'&>>Maccess_log.txt
./Maccess.exe -x -v makefaile &>> Maccess_log.txt
echo'#test de  droit refusé'&>>Maccess_log.txt
./Maccess.exe -x makefile -v &>> Maccess_log.txt
echo'#option de mode inconnu'&>>Maccess_log.txt
./Maccess.exe -E makefile  -v &>> Maccess_log.txt
echo'#Trop d argument'&>>Maccess_log.txt
./Maccess.exe -x makefile -v -E &>>Maccess_log.txt
echo'#argument manquant'&>>Maccess_log.txt
./Maccess.exe -v &>> Maccess_log.txt
echo'#trop de liens symboliques'&>>Maccess_log.txt
ln -s l1 l2
ln -s l2 l1
./Maccess.exe -x l1 -v

#je n'est pas testé le cas ou le nom de fichier est trop long
