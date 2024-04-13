#!/bin/sh
mkdir Home
cd Home/
mkdir name
cd name/
mkdir fouda
cd fouda/
mkdir tarek
cd tarek/
mkdir sarah
cd ..
cd ..
cd ..
mkdir courses
cd courses/
mkdir os
touch markes.txt
echo "20" >>markes.txt
echo "10" >>markes.txt
echo "7" >>markes.txt
cd os/
mkdir hci
touch markes.txt
echo "30" >> markes.txt
echo "16" >>markes.txt
echo "8" >>markes.txt
cd hci/
mkdir numerical
touch markes.txt
echo "25" >> markes.txt
echo "10" >>markes.txt
echo "5" >>markes.txt
cd numerical
mkdir algorithms 
touch markes.txt
echo "28" >> markes.txt
echo "10" >>markes.txt
echo "3" >>markes.txt
cd ..
cd ..
cd ..
cd ..
mkdir combined
cp courses/markes.txt combined/osmarkes.txt
cp courses/os/markes.txt combined/hcimarkes.txt
cp courses/os/hci/markes.txt combined/numarkes.txt
cp courses/os/hci/numerical/markes.txt combined/algomarkes.txt
cd combined
cat osmarkes.txt hcimarkes.txt numarkes.txt algomarkes.txt > ./merge.txt
cd ..
rm -r courses/markes.txt
rm -r courses/os/markes.txt
rm -r courses/os/hci/markes.txt
rm -r courses/os/hci/numerical/markes.txt
cd combined

