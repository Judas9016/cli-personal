#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <regex>
#include <iomanip>
#include <stdexcept>

using namespace std;
string nombre;

void saludo_inicial() {
    cout << "\033[33mIngresa tu nombre: \033[0m";
    getline(cin, nombre);
    cout << "\033[32m¡Hola, " << nombre << "! Bienvenido al CLI.\033[0m" << endl;
}

string cifrar_palabra_simple(const string& palabra) {
    ostringstream oss;
    for (char c : palabra) {
        oss << hex << setw(2) << setfill('0') << static_cast<int>(c);
    }
    return oss.str();
}

void cifrar_palabra() {
    cin.ignore(); 
    string palabra;
    cout << "\033[33mIngresa la palabra o contraseña a cifrar: \033[0m";
    getline(cin, palabra);

    string hash = cifrar_palabra_simple(palabra);
    cout << "\033[35mCifrado hexadecimal: " << hash << "\033[0m" << endl;
}

void nivel_seguridad_contrasena() {
    cin.ignore(); 
    string contrasena;
    cout << "\033[33mIngresa la contraseña para evaluar su nivel de seguridad: \033[0m";
    getline(cin, contrasena);

    int puntuacion = 0;

    if (contrasena.length() >= 8) puntuacion++;
    if (any_of(contrasena.begin(), contrasena.end(), ::isdigit)) puntuacion++;
    if (any_of(contrasena.begin(), contrasena.end(), ::isupper)) puntuacion++;
    if (any_of(contrasena.begin(), contrasena.end(), ::islower)) puntuacion++;
    if (any_of(contrasena.begin(), contrasena.end(), [](char c) { return ispunct(c); })) puntuacion++;

    string nivel;
    switch (puntuacion) {
        case 5:
            nivel = "Muy fuerte";
            break;
        case 4:
            nivel = "Fuerte";
            break;
        case 3:
            nivel = "Moderada";
            break;
        case 2:
            nivel = "Débil";
            break;
        default:
            nivel = "Muy débil";
    }

    cout << "\033[34mNivel de seguridad: " << nivel << "\033[0m" << endl;
}

void timer() {
    int seconds;
    cout << "\033[33mIngresa el tiempo en segundos: \033[0m";
    cin >> seconds;

    cout << "\033[32mIniciando el temporizador...\033[0m" << endl;
    while (seconds > 0) {
        cout << "\033[34mTiempo restante: " << seconds << " segundos\033[0m\r";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
        --seconds;
    }
    cout << "\033[32m\n¡Tiempo terminado!\033[0m" << endl;
}

void generar_contrasena() {
    try {
        int longitud;
        cout << "\033[33mIngresa la longitud de la contraseña: \033[0m";
        if (!(cin >> longitud)) {
            throw invalid_argument("La longitud debe ser un número entero.");
        }

        if (longitud <= 0) {
            throw out_of_range("La longitud debe ser mayor que cero.");
        }

        const string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
        srand(time(nullptr));
        string contrasena;

        for (int i = 0; i < longitud; ++i) {
            contrasena += caracteres[rand() % caracteres.size()];
        }

        cout << "\033[35mContraseña generada: " << contrasena << "\033[0m" << endl;
    } catch (const exception& e) {
        cout << "\033[31mError: " << e.what() << "\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    saludo_inicial();

    while (true) {
        cout << "\n\033[36m=== MENU CLI ===\033[0m" << endl;
        cout << "1. Nivel de seguridad de contraseña" << endl;
        cout << "2. Cifrar palabra" << endl;
        cout << "3. Temporizador" << endl;
        cout << "4. Generador de contraseñas" << endl;
        cout << "5. Salir" << endl;

        cout << "\033[33mSelecciona una opción (1-5): \033[0m";
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            nivel_seguridad_contrasena();
        } else if (opcion == 2) {
            cifrar_palabra();
        } else if (opcion == 3) {
            timer();
        } else if (opcion == 4) {
            generar_contrasena();
        } else if (opcion == 5) {
            cout << "\033[32m¡Hasta luego, " << nombre << "!\033[0m" << endl;
            break;
        } else {
            cout << "\033[31mOpción no válida. Intenta de nuevo.\033[0m" << endl;
        }
    }

    return 0;
}
