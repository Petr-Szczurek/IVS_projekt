Prostředí
---------

Ubuntu 64bit

Projekt byl testován na staženém IVS Ubunutu 22.04 - 64bit

Autoři
------

☠️Tým xszczu00
- xrybni10 Martin Rybnikář
- xszczu00 Petr Szczurek 
- xhucza02 Matouš Huczala

Licence
-------

Tento program je poskytován pod licencí GNU GPL v. 2.

Instalace projektu - Ubuntu 64bit
---------------------------------

Instalace kalkulačky z instalačního balíčku:
    1. Stažení kalkulacka_04_amd64.deb do volitelného adresáře v počítači s operačním systémem Ubuntu 22.04 - 64bit
    2. otevřeni terminálu
    3. zadání příkazu $sudo apt-get install libqt5widgets5, přihlášení k účtu a potvrzení instalace
    4. Přesunutí se do adresáře kde se nachází instalační balíček kalkulacka_04_amd64.deb
    5. zadání příkazu $sudo dpkg -i kalkulacka_04_amd64.deb
    6. spuštění kalkulačky příkazem: $kalkulacka 

Odinstalace kalkulačky:
    1. otevření terminálu
    2. zadání příkazu $sudo apt-get remove kalkulacka

Instalace a přeložení projektu:
    1. otevření terminálu 
    2. stažení repozitáře: $git clone https://github.com/Petr-Szczurek/IVS_projekt.git
    3. otevření adresáře src v IVS_projekt
    4. spuštění příkazu: $make all
    5. v případě problému je potřeba doinstalovat qmake6: $sudo apt-get isntall qmake6
    6. spuštění kalkulačky pomocí příkazu: $make run 
    7. smazání pomocí příkazu: $make clean