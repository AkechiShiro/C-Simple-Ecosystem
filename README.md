# Simple model in C for an ecosystem of one prey/predator

This simple model is printed as a two dimensional grid in the terminal.

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

Make sure you have all the following requirements :

- git : the git command line utility
- gcc : the GNU gcc compiler is used for this project (recommended: 9.2.1 or higher) 
- make : the GNU make utility (recommended : version 4.2.1 or higher)

### Requirements

To install the [git command line utility](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) follow the instructions at the given link.

Make sure you have the [gcc](https://gcc.gnu.org/) compiler, if not please install following the instructions specific for your system.

Make sure you have the GNU `make` utility.

#### How can I make sure I have everything ?

You can run either `command -v my_required_command` or `which my_required_command`, as an example you could run `command -v make`, if a path is returned, then you can proceed to the next section.

The same commands can be done to test if you have the `gcc` compiler.

These two softwares usually are by default installed on most Linux distributions.

### Run the simulation

Open your favorite terminal, run: 

```
git clone https://github.com/AkechiShiro/C-simple-ecosystem
cd C-simple-ecosystem
make
```
If no errors are shown, you can test the simulation by running `./ecosys` in the project folder.

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
