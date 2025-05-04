# CLI Herramientas Rápidas

Este es un pequeño proyecto en C++ que proporciona varias herramientas útiles desde la línea de comandos (CLI):

- ✅ Evaluar el **nivel de seguridad de una contraseña**.
- ✅ **Cifrar una palabra o contraseña** a hexadecimal.
- ✅ Usar un **temporizador** (cuenta regresiva en segundos).
- ✅ **Generar contraseñas aleatorias** seguras.

## 📂 Estructura

El programa contiene las siguientes funciones principales:

1. **Nivel de seguridad de contraseña:** Evalúa la fortaleza de una contraseña en base a ciertos criterios.
2. **Cifrado de palabra:** Convierte cada carácter en su representación hexadecimal.
3. **Temporizador:** Cuenta regresiva en segundos mostrando el tiempo restante.
4. **Generador de contraseñas:** Crea una contraseña segura con longitud definida por el usuario.

## 🚀 ¿Cómo ejecutarlo?

### 1️⃣ **Compilar el programa**

Necesitas tener instalado un compilador de C++. Por ejemplo, si estás en Linux o tienes MinGW en Windows, puedes compilarlo así:

```bash
g++ mian.cpp -o cli_herramientas.exe


2️⃣ Ejecutar el programa

Después de compilar, simplemente ejecútalo:

./cli_herramientas

En Windows:

cli_herramientas.exe

🛠️ Requisitos

    C++11 o superior.

    Un compilador de C++ (g++, clang, Visual Studio, etc.).

🎨 Ejemplo de uso

Ingresa tu nombre: Juan
¡Hola, Juan! Bienvenido al CLI.

=== MENU CLI ===
1. Nivel de seguridad de contraseña
2. Cifrar palabra
3. Temporizador
4. Generador de contraseñas
5. Salir
Selecciona una opción (1-5): 1
Ingresa la contraseña para evaluar su nivel de seguridad: Contraseña123!
Nivel de seguridad: Muy fuerte

📝 Notas

    El programa utiliza códigos de color ANSI para mejorar la visualización en la terminal. Si usas Windows, asegúrate de que la terminal soporte estos códigos (puedes usar Windows Terminal o activar el soporte de VT100).

    Si llegas a tener problemas con la codificación o la locale (setlocale), puedes eliminar esa línea si tu entorno ya soporta correctamente los caracteres en español.