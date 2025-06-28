# VoidShell 👁️‍🗨️
![image](https://github.com/user-attachments/assets/f60883ba-a33c-4417-ab2e-6637e776cd1b)
![image](https://github.com/user-attachments/assets/e6b8fed9-5f0d-4578-b810-e14e328044a7)

VoidShell es una herramienta diseñada para generar malware de acceso remoto (RAT) a través de dos métodos: utilizando Metasploit o mediante archivos personalizados que yo mismo he creado y preconfigurado, es decir, código original y fácilmente adaptable.

# Desarrollado en C++ 🖥️
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white)
![Java](https://img.shields.io/badge/Java-007396?style=flat-square&logo=Java&logoColor=white)

Este proyecto es uno de los primeros que realizo principalmente en C++, ademas de algunas funcionalidades más complejas que seran en Python (añadiendo el codigo de malware, sera Python, C++ y Java). Elegí este lenguaje porque quiero dominarlo, y qué mejor forma de aprender que desarrollando un script real y funcional, ¿no?  
El proyecto actualmente está en desarrollo. Espero terminarlo en al menos 6 meses (olvidenlo, la escuela me esta golpeando como esclavo, probablemente en 1 año 😿). Incluirá herramientas de ofuscación, empaquetado y edición de código.

## 🛠️ Requisitos

| Requisitos                   | Funcion dentro del programa                                                                   |
|------------------------------|-----------------------------------------------------------------------------------------------|
| **g++**                      | Compilar el codigo fuente del proyecto, permite tener mayor compatibilidad                    |
| **python3**                  | Para ejecutar herramientas auxiliares, como el editor de codigo fuente de los malwares        |
| **Java Runtime Environment** | Necesario para que funcione `apktool`, y creacion de las muestras de malware para Android.    |
| **apktool**                  | Para descompilar y modificar los archivos APK Maliciosos para Android                         |
| **metasploit-framework**     | Para generar los payloads maliciosos mediante `meterpreter` y crear los archivos maliciosos.  |


# Instalacion 🔰
El script actual unicamente puede ejecutarse en distribuciones de Linux.

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Debian](https://img.shields.io/badge/Debian-D70A53?style=for-the-badge&logo=debian&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Kali](https://img.shields.io/badge/Kali-268BEE?style=for-the-badge&logo=kalilinux&logoColor=white)
![Arch](https://img.shields.io/badge/Arch%20Linux-1793D1?logo=arch-linux&logoColor=fff&style=for-the-badge)

### Instalacion manual
```bash
git clone https://github.com/74lg0/VoidShell
cd VoidShell
cd main
g++ -I ../include main.cpp -o voidshell #Esto creara el ejecutable de la herramienta
```

Una vez se haya creado el ejecutable se puede ejecutar el programa de la siguiente forma
```bash
./voidshell
```
Esto deberia permitirte ejecutar el script en tu sistema

# Ofuscación 👾
El código incluirá un script de ofuscación para los malwares generados, tanto para Linux, Windows como Android, mediante la implementación de una herramienta externa, como podría ser [Obfuscapk](https://github.com/ClaudiuGeorgiu/Obfuscapk). Aunque esto aún está en evaluación.
