# Four-Basic-Math-Operations-Procfile-Application
[System Programming Course Project] A procfile application that can do basic mathematical operations.

## Compiling

make

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/Compiling.jpg)

## Installing Module to Kernel

insmod four.ko

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/INSMOD.jpg)

## Running and Testing the Module

### Addition

echo 724 + 26 > /proc/proc_odevi/dortislem

cat /proc/proc_odevi/dortislem


grep "724 + 26 = 750" /var/log/syslog

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/Addition.jpg)

### Substraction

echo 2016 - 1881 > /proc/proc_odevi/dortislem

cat /proc/proc_odevi/dortislem


grep "2016 - 1881 = 135" /var/log/syslog

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/Substraction.jpg)

### Multiplication

echo 11 x 41 > /proc/proc_odevi/dortislem

cat /proc/proc_odevi/dortislem


grep "11 x 41 = 451" /var/log/syslog

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/Multiplication.jpg)

### Division

echo "8 / 2" > /proc/proc_odevi/dortislem

cat /proc/proc_odevi/dortislem


grep "8 / 2 = 4" /var/log/syslog

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/Division.jpg)

## Removing Module from Kernel
rmmod four.ko

![alt text](https://github.com/kivanckadir/Four-Basic-Math-Operations-Procfile-Application/blob/master/Documentation/RRMOD.jpg)
