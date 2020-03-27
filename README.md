# Simple model in C for an ecosystem of one prey/predator

This simple model is printed as two dimensional grid in the terminal.

The following convention is followed to show the different entities :

\+ : corner of the grid

| : border of the grid

O : prey

\* : predator

@ : predator and prey

Predators consumes preys, each move for a predator costs energy.
For each prey consumed, predators gains five energy.

At the beginning, the simulation contains an equal number of preys and predators.
For each iteration, the cpt counter is incremented.


### Requirements

You need to make sure you have the [gcc](https://gcc.gnu.org/) compiler installed, if not please install following the instructions specific for your system.

You also need to make sure you have the GNU `make` utility installed, you can run either `command -v make` or `which make`, if a path is returned, then you already have it.
The same can be done to test if you have the `gcc` compiler.

These two softwares usually are by default installed on most Linux distributions.

## To run this simulation model

Open your favorite terminal and inside the project folder, run `make`.

Then, you can test that the simulation works by running `./ecosys`.

### An example of running it

```
+----------+
|        OO|
| *        |
|   *      |
|          |
|          |
| *      *O|
|      @   |
|* O  O O  |
|  * *     |
|       @ O|
+----------+
Cpt :     0     Nb prey :    10 Nb predators :    10
```
