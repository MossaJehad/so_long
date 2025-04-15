# so_long

## 📌 Project Overview
**so_long** is a 2D game project built using the **MinilibX** graphics library. It is a simple top-down game where the player navigates a map to collect items ('C') and reach the exit ('E'). The game is developed as part of the 42 curriculum and serves as an introduction to graphical programming in C.

## ✨ Features
* **Map Parsing:** Reads map files with the `.ber` extension.
* **Map Validation:**
    * Checks if the map is rectangular.
    * Ensures the map is surrounded by walls ('1').
    * Validates map elements (exactly one 'P'layer, exactly one 'E'xit, at least one 'C'ollectible).
    * Verifies that all collectibles and the exit are reachable from the player's starting position.
* **Graphics:** Renders the map, player, walls, collectibles, and exit using MinilibX.
* **Player Movement:** Allows player movement using W, A, S, D keys.
* **Collectibles:** Player must collect all 'C' items before being able to exit.
* **Exit Condition:** Game ends successfully when the player reaches the exit 'E' after collecting all items.
* **Move Counter:** Displays the number of moves made by the player on the standard output.
* **Clean Exit:** Allows quitting the game using the ESC key or the window close button.

## 🔧 Requirements
* A C compiler (like `gcc` or `clang`)
* `make` utility
* **MinilibX** library installed on your system (specific versions might be required depending on your OS - Linux/macOS).
* Standard C libraries.

## ⚙️ Installation & Compilation
1.  **Clone the repository (if applicable):**
    ```bash
    git clone https://github.com/MossaJehad/so_long.git
    cd so_long-main
    ```
2.  **Compile the project:**
    * The project includes a `Makefile`. Run `make` in the project's root directory:
        ```bash
        make
        ```
    * This should compile the necessary `.c` files (including `libft` and `get_next_line`) and link them with the MinilibX library to create the executable `so_long`.

## ▶️ Usage
* Run the compiled executable, providing the path to a valid map file as a command-line argument:
    ```bash
    ./so_long maps/your_map.ber
    ```
    *(Replace `maps/your_map.ber` with the actual path to your map file.)*

## 🗺️ Map Format
* Map files must have the `.ber` extension.
* Maps must be rectangular and enclosed by walls ('1').
* Valid characters within the map are:
    * `1`: Wall
    * `0`: Empty space (Floor)
    * `P`: Player starting position (exactly one)
    * `E`: Exit (exactly one)
    * `C`: Collectible (at least one)
* All collectibles and the exit must be reachable.

## ⌨️ Controls
* **W:** Move Up
* **A:** Move Left
* **S:** Move Down
* **D:** Move Right
* **ESC:** Quit the game
* **Window Close Button:** Quit the game

## 📚 Libraries Used
* **MinilibX:** A basic graphics library used for window management, image handling, and event processing.
* **libft:** Your custom C library containing utility functions.
* **get_next_line:** Function to read files line by line.

