# fractol



<img width="321" height="241" alt="Mandelbrot_Animation0" src="https://github.com/user-attachments/assets/2a9cb783-ab20-4b9f-9208-70a32b5ea21d" />



An interactive fractal viewer written in C using MiniLibX. It renders the Mandelbrot and Julia sets in an 800×800 window.

## What's a fractal?

A fractal is a shape that keeps showing detail however far you zoom in. Often smaller copies of the whole shape appear inside it. Both fractals here come from repeating one simple formula on complex numbers:

```
z = z² + c
```

Each pixel stands for a point on the complex plane. The program applies the formula over and over and checks whether `z` stays small or grows to infinity, meaning `|z|` goes past 2.

- **Mandelbrot set:** `z` starts at 0 and `c` is the pixel. Points that never escape are inside the set and drawn black.
- **Julia set:** `z` starts at the pixel and `c` is a fixed value you pass on the command line. Every value of `c` gives a different Julia set.

Points that escape are colored by how many iterations they took, which creates the colored bands around the edge. More iterations give a sharper edge but take longer to draw.

![Mandelbrot set rendered with the default settings](images/mandelbrot.png)

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

Some Julia values worth trying:

| Command                          | Look                 |
| -------------------------------- | -------------------- |
| `./fractol julia -0.8 0.156`     | Swirling spirals     |
| `./fractol julia 0.285 0.01`     | Branching seahorses  |
| `./fractol julia -0.4 0.6`       | Rabbit-like blobs    |
| `./fractol julia -0.70176 -0.3842` | Dense curls        |

## Controls

| Input         | Action                      |
| ------------- | --------------------------- |
| Mouse scroll  | Zoom in / out               |
| Arrow keys    | Move around                 |
| `+` / `-`     | Increase / decrease detail (iterations) |
| `Esc` / close | Quit                        |
