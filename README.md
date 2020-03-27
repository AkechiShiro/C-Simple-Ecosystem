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

## To run this simulation model

You need to make sure you have the [gcc](https://gcc.gnu.org/) compiler installed, if not please install following the instructions specific for your system.

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
