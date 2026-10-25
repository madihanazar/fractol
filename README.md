# fractol

<img width="752" height="681" alt="Screenshot 2026-10-25 141827" src="https://github.com/user-attachments/assets/3f1a796b-83d9-462d-811b-1807a1d5b6ae" />


An interactive fractal viewer written in C using MiniLibX. It renders the Mandelbrot and Julia sets in an 800×800 window.

## Build

Requires macOS (links against OpenGL and AppKit). MiniLibX is included in `minilibx/`.

```sh
make          # builds ./fractol
make clean    # removes object files
make fclean   # removes object files and the binary
make re       # rebuilds from scratch
```

## Usage

```sh
./fractol mandelbrot
./fractol julia              # Julia set with c = 0 + 0i
./fractol julia -0.8         # c = -0.8 + 0i
./fractol julia -0.8 0.156   # c = -0.8 + 0.156i
```

## Controls

| Input         | Action                      |
| ------------- | --------------------------- |
| Mouse scroll  | Zoom in / out               |
| Arrow keys    | Move around                 |
| `+` / `-`     | Increase / decrease detail (iterations) |
| `Esc` / close | Quit                        |
