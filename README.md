# miniRT 

It is a project of ray tracing using MiniLibX graphical library. 

<br>

## How to Use

Get the project from git

```bash
git clone <URL> miniRT  
```

Compile the project using make. Both macOS and Linux versions of MiniLibX are supported.

```bash
cd miniRT && make
```

Run the program by passing a .rt scene file as input:

```bash  

./miniRT scenes/example.rt
```

Basic controls change the angle of camera, mainly for debugging purposes.

<br>

## Features

- Ray projection based on the right-hand rule

- Supports rendering of the following object types: **sphere**, **plane** and **cylinder**

- Lighting and shading effects

- Input handled through .rt scene files

- Uses MiniLibX (provided for both macOS and Linux)

## Notes

This project was developed under strict constraints defined by the 42 school curriculum. 
It complies with Norminette formatting rules and function limitations, which may prevent the use of more efficient or flexible approaches. 
Any implemented movement or interaction is primarily for debugging and does not aim to support complete scene manipulation.

