# CPP (C++ Exercises Collection)

Summary
-------
This directory contains multiple small C++ exercises and projects (organized in subfolders like `CPP0`, `CPP01`, ...). Each subfolder typically corresponds to a single exercise or topic from a C++ training curriculum.

Features
--------
- Small, self-contained C++ exercises
- Practice with core language features, OOP, memory management, and STL

Requirements
------------
- Linux
- `g++` (C++ compiler)
- `make` for subprojects that provide a `Makefile`

Build
-----
Many exercises provide a `Makefile` inside their subdirectory. To build a single exercise:

```
cd CPP/CPP0/ex00
make
```

Most `Makefile`s use the `-std=c++98` flag. Example local compile command (match your exercise `Makefile`):

```
g++ -std=c++98 -Wall -Wextra -Werror -g3 main.cpp -o program
```

If you changed compiler defaults, check each exercise `Makefile` for `CFLAGS`/`FLAGS`/`CXXFLAGS` before compiling.

Usage
-----
- Follow each subfolder's README (if present) for run instructions. Most exercises are small command-line programs.

Project Layout
--------------
- `CPP0/`, `CPP01/`, ... — per-exercise folders
- Each exercise usually contains source files, a `Makefile`, and example inputs/outputs.

Notes
-----
- This collection is for learning and practice. Treat each subfolder as an independent project.
- Many exercise `Makefile`s target the `C++98` standard (`-std=c++98`). Check each subfolder's `Makefile` before compiling if you changed default compiler flags.

Author / Attribution
--------------------
Author: ankammer

License
-------
Unlicensed (add a LICENSE file if needed).
