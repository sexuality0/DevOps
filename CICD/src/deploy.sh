#!/bin/bash

sshpass -p "septimak" scp cat/s21_cat septimak@192.168.0.22:/usr/local/bin/
sshpass -p "septimak" scp grep/s21_grep septimak@192.168.0.22:/usr/local/bin/
sshpass -p "septimak" ssh septimak@192.168.0.22 ls /usr/local/bin/ >> log.txt 