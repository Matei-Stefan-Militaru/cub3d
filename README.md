# cub3d

Estructura del proyecto cub3D
Archivos principales
cub3D/
├── Makefile
├── includes/
│   ├── cub3d.h          # Header principal que incluye todos
│   ├── parsing.h        # Parsing y validación
│   ├── render.h         # Renderizado y raycasting
│   ├── player.h         # Movimiento del jugador
│   ├── window.h         # Gestión de ventana
│   └── utils.h          # Utilidades generales
├── src/
│   ├── main.c
│   ├── parsing/
│   ├── render/
│   ├── player/
│   ├── window/
│   └── utils/
├── maps/
└── textures/
Módulos detallados
1. PARSING (src/parsing/)
Responsabilidad: Leer, validar y procesar el archivo .cub
parsing/
├── parse_file.c         # Función principal de parsing
├── parse_textures.c     # Procesar texturas (NO, SO, WE, EA)
├── parse_colors.c       # Procesar colores (F, C)
├── parse_map.c          # Procesar y validar mapa
├── validate_map.c       # Validar que el mapa esté cerrado
└── parse_utils.c        # Utilidades de parsing (split, trim, etc.)
Funciones clave:

parse_cub_file() - Función principal
parse_texture_line() - Procesar líneas de texturas
parse_color_line() - Procesar líneas de colores
parse_map_section() - Extraer el mapa
validate_map_walls() - Verificar que esté cerrado
find_player_position() - Encontrar posición inicial del jugador

2. RENDER (src/render/)
Responsabilidad: Raycasting y renderizado de la escena 3D
render/
├── render.c             # Función principal de renderizado
├── raycasting.c         # Algoritmo de raycasting
├── draw_walls.c         # Dibujar paredes con texturas
├── draw_floor_ceiling.c # Dibujar suelo y techo
├── textures.c           # Gestión de texturas
└── render_utils.c       # Utilidades de renderizado
Funciones clave:

render_frame() - Renderizar un frame completo
cast_rays() - Lanzar rayos desde el jugador
calculate_wall_distance() - Calcular distancia a la pared
draw_wall_slice() - Dibujar una columna de pared
get_texture_pixel() - Obtener pixel de textura
draw_floor_ceiling() - Rellenar suelo y techo

3. PLAYER (src/player/)
Responsabilidad: Movimiento y rotación del jugador
player/
├── player.c             # Gestión general del jugador
├── movement.c           # Movimiento (W, A, S, D)
├── rotation.c           # Rotación (flechas izq/der)
└── collision.c          # Detección de colisiones
Funciones clave:

init_player() - Inicializar jugador
move_player_forward() - Mover hacia adelante
move_player_backward() - Mover hacia atrás
strafe_left() - Moverse lateralmente
strafe_right() - Moverse lateralmente
rotate_left() - Girar a la izquierda
rotate_right() - Girar a la derecha
check_collision() - Verificar colisiones con paredes

4. WINDOW (src/window/)
Responsabilidad: Gestión de ventana y eventos
window/
├── window.c             # Inicialización y gestión de ventana
├── events.c             # Manejo de eventos del teclado/ratón
└── hooks.c              # Hooks de minilibX
Funciones clave:

init_window() - Crear ventana
setup_hooks() - Configurar eventos
key_press_handler() - Manejar teclas presionadas
key_release_handler() - Manejar teclas soltadas
close_window() - Cerrar ventana limpiamente
loop_hook() - Hook del bucle principal

5. UTILS (src/utils/)
Responsabilidad: Utilidades generales
utils/
├── error.c              # Gestión de errores
├── memory.c             # Gestión de memoria
├── math_utils.c         # Funciones matemáticas
└── string_utils.c       # Utilidades de strings
Funciones clave:

error_exit() - Salir con error
free_all() - Liberar toda la memoria
ft_split_whitespace() - Split por espacios
deg_to_rad() - Conversión de grados a radianes
normalize_angle() - Normalizar ángulos

Estructura de datos principal
ctypedef struct s_game {
    // Ventana y renderizado
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    
    // Jugador
    t_player    player;
    
    // Mapa y texturas
    t_map       map;
    t_textures  textures;
    
    // Colores
    int         floor_color;
    int         ceiling_color;
    
    // Estado del juego
    int         keys[256];
} t_game;
Flujo principal del programa

main.c:

Validar argumentos
Parsear archivo .cub
Inicializar MLX y ventana
Configurar hooks
Iniciar bucle principal


Bucle principal:

Procesar input del usuario
Actualizar posición del jugador
Renderizar frame
Mostrar en pantalla



Ventajas de esta estructura

Separación de responsabilidades: Cada módulo tiene una función específica
Mantenibilidad: Fácil de debuggear y modificar
Escalabilidad: Fácil añadir nuevas características
Testabilidad: Cada módulo se puede testear independientemente
Legibilidad: Código organizado y fácil de entender

Headers organization

cub3d.h: Include principal que importa todos los demás headers
parsing.h: Estructuras y funciones de parsing
render.h: Estructuras y funciones de renderizado
player.h: Estructuras y funciones del jugador
window.h: Funciones de ventana y eventos
utils.h: Utilidades generales

Esta estructura te permitirá tener un código limpio, modular y fácil de mantener.
