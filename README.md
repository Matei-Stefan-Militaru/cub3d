# cub3d

# cub3D - My first RayCaster with miniLibX

A 3D maze game built using raycasting techniques and the miniLibX graphics library. This project creates a realistic first-person perspective view of a maze, similar to classic games like Wolfenstein 3D.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Map Format](#map-format)
- [Controls](#controls)
- [Technical Details](#technical-details)
- [Screenshots](#screenshots)

## 🎯 Overview

cub3D is a project from the 42 School curriculum that introduces students to raycasting, a rendering technique used to create 3D-like graphics in 2D environments. The program reads a scene description file (.cub) and renders a first-person view of a maze with textured walls, colored floors, and ceilings.

## ✨ Features

- **3D Raycasting Engine**: Real-time 3D rendering using raycasting algorithms
- **Textured Walls**: Different textures for each wall direction (North, South, East, West)
- **Colored Surfaces**: Customizable floor and ceiling colors
- **Smooth Movement**: Fluid player movement and rotation
- **Collision Detection**: Prevents walking through walls
- **Window Management**: Proper window handling with clean exit options

## 📁 Project Structure

```
cub3D/
├── Makefile
├── README.md
├── includes/
│   ├── cub3d.h          # Main header file
│   ├── parsing.h        # Parsing and validation
│   ├── render.h         # Rendering and raycasting
│   ├── player.h         # Player movement
│   ├── window.h         # Window management
│   └── utils.h          # General utilities
├── src/
│   ├── main.c           # Entry point
│   ├── parsing/         # File parsing and validation
│   │   ├── parse_file.c
│   │   ├── parse_textures.c
│   │   ├── parse_colors.c
│   │   ├── parse_map.c
│   │   ├── validate_map.c
│   │   └── parse_utils.c
│   ├── render/          # Raycasting and rendering
│   │   ├── render.c
│   │   ├── raycasting.c
│   │   ├── draw_walls.c
│   │   ├── draw_floor_ceiling.c
│   │   ├── textures.c
│   │   └── render_utils.c
│   ├── player/          # Player movement and rotation
│   │   ├── player.c
│   │   ├── movement.c
│   │   ├── rotation.c
│   │   └── collision.c
│   ├── window/          # Window and event management
│   │   ├── window.c
│   │   ├── events.c
│   │   └── hooks.c
│   └── utils/           # General utilities
│       ├── error.c
│       ├── memory.c
│       ├── math_utils.c
│       └── string_utils.c
├── maps/                # Example map files
│   ├── basic.cub
│   ├── complex.cub
│   └── test.cub
├── textures/            # Wall texture files
│   ├── north_wall.xpm
│   ├── south_wall.xpm
│   ├── east_wall.xpm
│   └── west_wall.xpm
└── libft/               # Custom C library (if used)
```

## 🚀 Installation

### Prerequisites

- GCC compiler
- Make
- miniLibX library
- Math library (-lm)

### Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/yourusername/cub3D.git
cd cub3D
```

2. Compile the project:
```bash
make
```

3. For bonus features (if implemented):
```bash
make bonus
```

## 🎮 Usage

Run the program with a valid .cub map file:

```bash
./cub3D maps/basic.cub
```

### Example .cub file format:

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm  
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## 🗺️ Map Format

### Texture Identifiers:
- `NO` - North wall texture path
- `SO` - South wall texture path  
- `WE` - West wall texture path
- `EA` - East wall texture path

### Color Identifiers:
- `F` - Floor color (R,G,B format, range 0-255)
- `C` - Ceiling color (R,G,B format, range 0-255)

### Map Characters:
- `0` - Empty space (walkable)
- `1` - Wall
- `N`, `S`, `E`, `W` - Player starting position and orientation

### Map Rules:
- Map must be surrounded by walls
- Only one player starting position allowed
- Map must be the last element in the file
- Spaces are valid and handled as empty areas

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Look left |
| `→` | Look right |
| `ESC` | Exit game |

## 🔧 Technical Details

### Raycasting Algorithm
The raycasting engine works by:
1. Casting rays from the player's position in the viewing direction
2. Calculating intersections with walls using DDA (Digital Differential Analyzer)
3. Determining wall height based on distance
4. Applying appropriate textures based on wall orientation
5. Rendering floor and ceiling colors

### Key Data Structures

```c
typedef struct s_game {
    void        *mlx;           // MinilibX instance
    void        *win;           // Window pointer
    void        *img;           // Image buffer
    t_player    player;         // Player data
    t_map       map;            // Map data
    t_textures  textures;       // Wall textures
    int         floor_color;    // Floor RGB color
    int         ceiling_color;  // Ceiling RGB color
    int         keys[256];      // Key states
} t_game;
```

### Performance Optimizations
- Efficient DDA algorithm for ray-wall intersections
- Texture mapping with proper scaling
- Minimal memory allocations during runtime
- Optimized rendering loop

## 🖼️ Screenshots

*Add screenshots of your game in action here*

## 🧪 Testing

The project includes comprehensive error handling for:
- Invalid map configurations
- Missing texture files
- Malformed .cub files
- Memory allocation failures
- Invalid color values

## 📚 Learning Outcomes

This project teaches:
- **Computer Graphics**: Understanding of 2D to 3D projection
- **Raycasting**: Implementation of classic rendering techniques
- **Event Handling**: Real-time input processing
- **Memory Management**: Proper allocation and deallocation
- **File Parsing**: Robust input validation and processing
- **Modular Programming**: Clean code organization and architecture

## 🤝 Contributing

This project is part of the 42 School curriculum. If you're a fellow student, feel free to discuss approaches and share insights, but remember to follow your school's collaboration policies.

## 📄 License

This project is for educational purposes as part of the 42 School curriculum.

## 🙏 Acknowledgments

- 42 School for the project specifications
- The creators of miniLibX library
- Classic games like Wolfenstein 3D for inspiration

---

**Note**: This project was developed as part of the 42 School curriculum. The goal is to understand fundamental computer graphics concepts through hands-on implementation.
