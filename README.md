## rotatex

This simple program rotates your display every 3 seconds. It cycles through the following orientations:

1. Right (90 degrees)
2. Inverted (180 degrees)
3. Left (270 degrees)
4. Normal (0 degrees)

### Requirements

- X11 and xrandr must be installed on your system.

### Installation

1. Clone the repository:
```bash
git clone https://github.com/MickFurax/rotatex.git
```
2. Navigate to the project directory:
```bash
cd rotatex
```
3. Build the program:
```bash
make
```

### Usage

Run the program with:
```bash
./rotatex
```

### How It Works

The program uses the `xrandr` command-line utility to control the display orientation. It forks a child process to execute `xrandr` with the appropriate arguments for each rotation. A 3-second delay is introduced between each rotation.

### Notes

- The program requires the `DISPLAY` environment variable to be set.
- You can stop the program by pressing Ctrl+C.

### Contributing

Feel free to open issues or pull requests for any suggestions or improvements. 
