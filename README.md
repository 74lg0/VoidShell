# VoidShell 👁️‍🗨️
![image](https://github.com/user-attachments/assets/f60883ba-a33c-4417-ab2e-6637e776cd1b)
![image](https://github.com/user-attachments/assets/e6b8fed9-5f0d-4578-b810-e14e328044a7)

VoidShell es una herramienta diseñada para generar malware de acceso remoto (RAT) a través de dos métodos: utilizando Metasploit o mediante archivos personalizados que yo mismo he creado y preconfigurado, es decir, código original y fácilmente adaptable.

# Desarrollado en C++ 🖥️
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white)
![Java]

Este proyecto es uno de los primeros que realizo principalmente en C++, ademas de algunas funcionalidades más complejas que seran en Python (añadiendo el codigo de malware, sera Python, C++ y Java). Elegí este lenguaje porque quiero dominarlo, y qué mejor forma de aprender que desarrollando un script real y funcional, ¿no?  
El proyecto actualmente está en desarrollo. Espero terminarlo en al menos 6 meses (olvidenlo, la escuela me esta golpeando como esclavo, probablemente en 1 año 😿). Incluirá herramientas de ofuscación, empaquetado y edición de código.

# Instalacion

El script actual unicamente puede ejecutarse en sistemas UNIX/Linux.

🐧 Linux Debian, Ubuntu.

🐲 Kali Linux.

🌑 Termux (Con MetaSploit instalado Ⓜ️).

```bash
git clone https://github.com/74lg0/VoidShell
cd VoidShell
cd main
g++ -I ../include main.cpp -o voidshell #Esto creara el ejecutable de la herramienta
```

Una vez se haya creado el ejecutable se puede ejecutar el programa de la siguiente forma


# Ofuscación 👾
El código incluirá un script de ofuscación para los malwares generados, tanto para Linux, Windows como Android, mediante la implementación de una herramienta externa, como podría ser [Obfuscapk](https://github.com/ClaudiuGeorgiu/Obfuscapk). Aunque esto aún está en evaluación.
