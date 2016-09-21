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

