# lem-in
Ant farm manager

## Description
Program `lem-in` reads data from standard output,
generates from this data an ant farm with rooms and connections between them
and finds the quickest way for ants to move from starting room to destination room.

## Rules
• Program receives data describing the ant farm from the standard output
in the following format
```diff
number_of_ants
the_rooms
the_links
```

• The ant farm is defined by the following links:
```diff
3
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```
• Which corresponds to the following representation:
```diff
           ________________
          /                \
  ______[5]----[3]----[1]   |
 /              |      /    |
[6]-----[0]----[4]    /     |
 \    _________/ |   /      |
  \  /           [2]/______/
  [7]___________/
```
• There are two parts:<br />
◦ The rooms, which are defined by: name coord_x coord_y<br />
◦ The links, which are defined by: name1-name2<br />
◦ All of it is broken by comments, which start with #<br />

• Lines that start with ## are commands modifying the properties of the line that
comes right after.<br />
• For example, ##start signals the ant farm’s entrance and ##end its exit.<br />
• Any non compliant or empty lines will automatically stop the ant farm’s reading
as well as the orderly processing of the acquired data.<br />
• If there isn’t enough data to process normally you must display ERROR<br />
• The goal of this project is to find the quickest way to get n ants across the farm.<br />
• Quickest way means the solution with the least number of lines, respecting the
output format requested below.<br />
• Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.<br />
• At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)<br />
• We consider that all the ants are in the room ##start at the beginning of the game.<br />
• At each turn you will only display the ants that moved.<br />
• At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).<br />
• You must to display your results on the standard output in the following format:<br />
```diff
number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...
```
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.<br />
• Example 1 :<br />
[0]-[2]-[3]-[1]<br />
```diff
./lem-in < subject.map
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```

## Flags
Program can be run with two flags:<br />
-m displays information about all rooms and connections in map<br />
-p displays shortest path found in one line
```diff
./lem-in < file.map -m -p
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1

0 [1] [0] start
Depth = 0
Links: 2

1 [5] [0] end
Depth = 3
Links: 3

2 [9] [0]
Depth = 1
Links: 3, 0

3 [13] [0]
Depth = 2
Links: 1, 2

Shortest path: 0->2->3->1

L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```

## The Norm
Project is written in accordance with the Norm (SNAKE_CASE, maximum of 25 lines per function, tabulations before function names etc).

## Installation
Run `make` in project directory to compile executable file called ft_ssl.<br />
Run `make clean` to delete object files.<br />
Run `make fclean` to delete object files and executable.
