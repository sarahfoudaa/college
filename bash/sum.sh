#!/bin/sh
cd Home 
cd combined
paste -sd+ osmarkes.txt | bc
paste -sd+ hcimarkes.txt | bc
paste -sd+ numarkes.txt | bc
paste -sd+ algomarkes.txt | bc
filename=$(ls -td -- *"o"* | head -n 1)
cat "$filename"

