# Fract-ol

<div align=center>

![Banner](./assets/banner.png)

![C Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
[![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-blue)](https://github.com/42Paris/minilibx-linux)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## Description

**Fract-ol** is a graphical application written in C that renders complex mathematical fractals such as the **Mandelbrot set**, **Julia sets**, and optionally the **Lotus** fractal.  
This project explores topics such as complex numbers, graphical rendering, event-driven programming, and performance optimization.

It was developed as part of the 42 curriculum using [**MiniLibX**](https://github.com/42Paris/minilibx-linux), a lightweight graphics library.

## Features

- 🧠 Render multiple fractals:
  - Mandelbrot
  - Julia
  - Lotus (bonus)
- 🖱️ Mouse interaction:
  - Scroll to zoom in/out
- ⌨️ Keyboard shortcuts:
  - Move, zoom, reset, change iterations, switch colors
- Multithreaded rendering for performance

## Controls

| Input                     | Action                                   |
|---------------------------|------------------------------------------|
| `P` / `M` or Mouse Scroll | Zoom in/out                              |
| Arrows                    | Move across the fractal                  |
| `W` / `Q`                 | Increase or decrease iterations          |
| `C`                       | Cycle through color palettes             |
| `R`                       | Reset view to default                    |
| `ESC`                     | Quit the application                     |

## Demo

Here’s a screenshot of a rendered fractal after running `./fractol_bonus mandelbrot`:

![Fractal Screenshot](./assets/demo.png)

## Installation

### Requirements

- Unix-based OS (macOS/Linux)
- MiniLibX installed (usually available in 42 projects)

### Build

For the mandatory version, run:
```bash
make
./fractol ...
```
or for the bonus version, run:
```bash
make bonus
./fractol_bonus ...
```

To use multithreading, run:
```bash
./fractol_bonus -mt ...
```
