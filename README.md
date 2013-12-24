pathfinding
===========

Small tool suit to implement pathfinding algorithms and visualize them on a 2d square based board.

In fact it is a personal playground to experiment with pathfinding algorithms. If you look for a poweful implementation you should probably continue your search elsewhere ;)

Reqirements
---

- SFML >= 2.0
- C++11 compatible compiler
- CMake >= 2.8

Build instructions
---

If all dependencies are satisfied pathfinding can be easily built by executing ```cmake .```

If anything goes wrong please feel free to contact me :)

Pathfinding algorithms
---

At the moment only an implementation of the A* algorithm is provided which uses manhattan directions and is limited to horizontal and vertical movement. This fits the needs for my other project [qrwar](https://github.com/namelessvoid/qrwar/).

Implementing your own algorithms
---

You just have to extend the ```pathfinding::AlgorithmInterface``` class and exchange the algorithm in ```main.cpp```.
