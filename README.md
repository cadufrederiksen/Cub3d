# 🕹️ cub3D - Building a 3D Game Engine with Raycasting

![C](https://img.shields.io/badge/Language-C-blue) ![MiniLibX](https://img.shields.io/badge/Graphics-MiniLibX-orange) ![Makefile](https://img.shields.io/badge/Tool-Makefile-yellow) ![Norminette](https://img.shields.io/badge/Style-Norminette-green)

The **cub3D** project challenges students to build a basic 3D game engine using raycasting, similar to classic titles like Wolfenstein 3D. This project offers a practical introduction to graphics programming, 3D rendering techniques, and game engine architecture.

---

## 📋 Project Objective

🔹 Develop a simple 3D game engine that renders a three-dimensional view from a two-dimensional map using raycasting.  
🔹 Parse and validate custom map files to create the game environment.  
🔹 Implement texture mapping to add realism to walls, floors, and ceilings.  
🔹 Enable smooth player movement and interaction within the 3D world.

---

## 📚 Main Concepts

- 🕶️ **Raycasting**: Simulating a 3D perspective by casting rays from the player's viewpoint to detect walls and objects.
- 🖼️ **Texture Mapping**: Applying images to surfaces to create a realistic visual experience.
- 🎮 **Game Engine Architecture**: Understanding the core components of a game engine, including rendering loops and input handling.
- 📂 **Map Parsing and Validation**: Reading and verifying map files (typically with a `.cub` extension) to build the game world.
- 🔄 **Real-Time Rendering**: Efficient techniques for drawing and updating the game scene continuously.

---

## ✨ Implemented Features

### 🔧 Engine Core
- **Raycasting Engine**: Computes the intersection of rays with walls to generate a 3D perspective from a 2D map.
- **Player Movement**: Implements navigation controls, allowing the player to move forward, backward, and sideways.
- **Collision Detection**: Prevents the player from moving through walls and other obstacles.

### 🖼️ Graphics and Textures
- **Texture Mapping**: Applies textures to walls, floors, and ceilings to enhance visual realism.
- **Basic Lighting and Shading**: Uses simple shading techniques to create depth and improve the 3D effect.

### 🛠️ Map Handling
- **Map Parsing**: Reads and validates a map file to construct the game environment.
- **Error Management**: Detects and reports issues such as invalid map configurations or missing assets.

### 🔄 Additional Features
- **MiniLibX Integration**: Utilizes the MiniLibX library for window management and rendering.
- **Optimized Rendering Loop**: Ensures efficient updating of the game scene for a smooth frame rate.
- **User Input Handling**: Captures keyboard inputs to control the player's movement and view direction.

---

## 🛠️ Tools and Standards

| Tool/Standard         | Description                                                        |
|-----------------------|--------------------------------------------------------------------|
| **GIT**               | Version control to manage and track code changes.                  |
| **Makefile**          | Automates the compilation and build process.                       |
| **Norminette**        | Ensures adherence to the 42 coding style standards.                |
| **MiniLibX**          | Lightweight graphics library used for rendering the game environment.|

---
