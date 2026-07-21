# cg-billboard-rain

# 🌧️ Simulación de lluvia con billboards

Simulación de lluvia en tiempo real desarrollada en **C++** usando **OpenGL 3.3**. El proyecto implementa un entorno climático completo con renderizado mediante billboards, cámara en primera persona, partículas dinámicas, audio ambiental e interfaz gráfica configurable con Dear ImGui.

![Demo](docs/demo.gif)

---

# Características

- 🌧️ Sistema de partículas de lluvia usando billboards
- 🌲 Árboles dinámicos con billboards
- 🌍 Ilusión de suelo infinito
- 🎮 Cámara en primera persona (FPS)
- ⚡ Sistema aleatorio de relámpagos
- 🔊 Audio ambiental de lluvia
- 🌩️ Efectos aleatorios de trueno
- 💨 Simulación de viento
- 🎛️ Controles GUI en tiempo real
- 📈 FPS y estadísticas de rendimiento

---

# Tecnologías

| Tecnología | Propósito |
|------------|----------|
| C++20 | Lenguaje principal de programación |
| OpenGL 3.3 | Renderizado gráfico |
| GLFW | Gestión de ventana e input |
| GLAD | Cargador de OpenGL |
| GLM | Biblioteca de matemáticas |
| stb_image | Carga de texturas |
| Dear ImGui | Interfaz gráfica de usuario |
| miniaudio | Motor de audio |
| CMake | Sistema de compilación |

---

# Estructura del proyecto

```
cg-billboard-rain
│
├── assets
│   ├── audio
│   ├── shaders
│   └── textures
│
├── docs
│   └── demo.png
│
├── external
│
├── src
│   ├── audio
│   ├── core
│   ├── graphics
│   ├── gui
│   ├── math
│   ├── particles
│   ├── resources
│   ├── scene
│   └── utils
│   ├── weather
│
├── CMakeLists.txt
└── README.md
```

---

# Arquitectura del sistema

```
Aplicación
│
├── Camera
├── Renderer
├── Scene
├── GuiManager
├── RainSystem
├── TreeSystem
├── WeatherSystem
└── AudioManager
```

---

# Sistema de lluvia

La lluvia está implementada usando un emisor de partículas. Cada partícula se representa como un billboard, lo que permite renderizar miles de gotas de forma eficiente mientras siempre miran hacia la cámara.

Características principales:

- Reciclaje de partículas
- Soporte para viento
- Velocidad de caída variable
- Cantidad de partículas configurable
- Renderizado con billboards

---

# Suelo infinito

En lugar de generar un terreno enorme, el suelo sigue la posición de la cámara sobre el plano XZ, creando la ilusión de una superficie infinita.

Ventajas:

- Uso constante de memoria
- No se requiere generación de terreno
- Rendimiento estable

---

# Árboles dinámicos

Los árboles se renderizan como billboards con textura.

Características:

- Posiciones iniciales aleatorias
- Escala aleatoria
- Distancia mínima entre árboles
- Reciclaje automático alrededor del jugador
- Siempre apuntan hacia la cámara

---

# Sistema climático

WeatherSystem controla:

- Relámpagos aleatorios
- Intensidad del destello del relámpago
- Activación del trueno

Cada evento de relámpago:

- Produce un destello en pantalla
- Reproduce un sonido de trueno aleatorio

---

# Sistema de audio

El audio se gestiona usando **miniaudio**.

Sonidos implementados:

- Bucle continuo de lluvia
- Sonidos aleatorios de trueno

El volumen de la lluvia cambia automáticamente según la cantidad de partículas seleccionada por el usuario.

---

# Controles de la GUI

Dear ImGui permite modificar la simulación en tiempo real.

Controles disponibles:

- Número de partículas
- Intensidad del viento
- Velocidad de la lluvia

Información adicional:

- FPS
- Delta Time
- Posición de la cámara

---

# Controles de la cámara

| Tecla | Acción |
|------|--------|
| W | Mover hacia adelante |
| S | Mover hacia atrás |
| A | Mover a la izquierda |
| D | Mover a la derecha |
| Mouse | Rotar cámara |

---

# Optimizaciones de rendimiento

Se implementaron varias optimizaciones:

- Renderizado con billboards
- Reciclaje de partículas
- Reciclaje de árboles
- Recursos compartidos
- Shaders compartidos
- Texturas compartidas
- Audio en streaming
- Suelo infinito

Estas optimizaciones permiten renderizar miles de partículas manteniendo un rendimiento fluido.

---

# Mejoras futuras

Posibles extensiones:

- Niebla volumétrica
- Sonido de viento
- Skybox dinámico
- Efectos de salpicadura de lluvia
- Iluminación HDR
- Generación de terreno
- Vegetación 3D
- Sombras dinámicas
- Simulación de nieve
- Múltiples presets climáticos
- Entornos estacionales
- Charcos de agua
- Reflejos en superficies mojadas

---

# Compilación

Clona el repositorio

```bash
git clone https://github.com/your-user/cg-billboard-rain.git
```

Crear el directorio de compilación

```bash
mkdir build
cd build
```

Generar los archivos del proyecto

```bash
cmake ..
```

Compilar

```bash
cmake --build .
```

Ejecutar

```bash
./cg_billboard_rain
```

---

# Demo

Coloca la siguiente imagen dentro de:

```
docs/demo.png
```

Aparecerá automáticamente al inicio de este README.

---

# Autores

Proyecto de Computación Gráfica

Universidad Nacional de San Agustín

2026

---

# Licencia

Este proyecto fue desarrollado con fines educativos.
