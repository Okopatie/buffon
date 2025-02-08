# buffon
A simple, interactive implementation of using [Buffon's needle
problem](https://en.wikipedia.org/wiki/Buffon's_needle_problem) to
calculate π.
<br>
Built using [raylib](https://github.com/raysan5/raylib/tree/master)
and
[raylib-game-template](https://github.com/raysan5/raylib-game-template).

## Building

To build buffon, run the following commands from the root of the
repository:
`cmake -S . -B build
cmake --build build`

To run the program run the following command:
`./build/buffon/buffon`

## Explanation

This uses a [Monte Carlo
method](https://en.wikipedia.org/wiki/Monte_Carlo_method) to
experimentally determine the value of π.

Buffon's needle asks for the probability that a randomly thrown stick
of length 1 will land across straight lines with a distance of 1
between them. The only important random variables for this problem
that will be used are the y-coordinate of the bottom of the stick from
0 to 1,
$y$, and the angle that the stick makes with the horizontal from 0
to π radians,$\theta$. The stick will cross one of the lines if and
only if $y$ +
\sin(\theta) > 1$. This reformulates the problem as one of finding
the probability that $y > 1 - \sin(\theta)$. A graph of $y$
against $1 - \sin(\theta)$ can be plotted. The probability can then
be found by dividing the area above the curve on the graph by the
total area of the region. Therefore the probability is
$\frac{\int_0^{\pi} \sin(\theta) d\theta}{\pi \times 1} =
\frac{2}{\pi\}$. This means that π can be found by experimentally
determining the probability, $p$ that a stick will cross one of the
lines, and calculating $\frac{2}{p}$.
