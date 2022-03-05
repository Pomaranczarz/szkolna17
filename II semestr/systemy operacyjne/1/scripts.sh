#!/bin/bash

# 1.1
# 1
(man printf | grep -v "^$") | tail -3

# 2
man printf

# 3 
man printf | grep "Length modifier"

# 4
man printf | grep "long"

# 5
# po wpisaniu /<slowo>:
#       wcisniecie 'n' spowoduje przejscie do nastepnego wystapienia <slowo>
#       wcisniecie 'Shift + n' spowoduje przejscie do poprzedniego wystapienia <slowo>

#6
man man

# 1.2

# 1
which ls xterm gcc route

# 2
ls /usr/bin | grep 'cups'

# 3
cd ~ 
mkdir cw1 
cw1
echo abc > plik.txt
cat plik.txt
mv plik.txt plik2.txt
mkdir test
cp plik2.txt test/.
cd ~ &&
rm -r cw1

# 5
cd ~
mkdir katalog
ls -l
cat > plik # Jan Kowalski\nKatarzyna Nowak
chmod u-r,o-r,g-r plik
cat katalog/plik

chmod +755 katalog/plik
chmod -rw-r-r-- katalog
chmod +755 katalog
cat katalog/plik
chmod drwxrwxr-x katalog

# 1.7
ps -aef --forest
sleep 10
sleep 10 &