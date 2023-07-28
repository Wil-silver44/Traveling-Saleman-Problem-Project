# P3-Traveling-Saleman-Problem

## Background

A very famous graph/permutation problem is the Traveling Salesman Problem: 

*given n cities with different distances among them and a designated first city, what is the least cost to visit all cities and return to the first one?* 
Unfortunately, the brute-force method of solving this problem requires that we assess (n - 1)! permutations of the cities. How feasible is this?

However, not all is lost. For computationally "hard" problems such as this one, we may employ any of several means to find good if not strictly optimal solutions - say within 5-10%  of optimal. (Note that "computationally hard" problems are formalized as "np-complete" or "np-hard.").
One way to address this problem might be based upon a simplified approach to the permutation form of genetic algorithms. Wikipedia has some good information on this technique.

Wikipedia link: https://en.wikipedia.org/wiki/Genetic_algorithm

Here is a basic approach (based upon an algorithm presented at Wikipedia) to solve our problem:

1. Choose the initial [population](http://en.wikipedia.org/wiki/Population) of tours (generate a set of permutations of the orderings of the cities)
2. Evaluate the [fitness](https://en.wikipedia.org/wiki/Fitness_(biology)) (cost) o)f each [individual](http://en.wikipedia.org/wiki/Individual) tour
3. Repeat

   - Select best-ranking individuals ([see Wikipedia link on "Reproduce"](http://en.wikipedia.org/wiki/Reproduce)) as elites (see below)  
   - Create additional tours through crossover, mutation or both (genetic operations) and give birth to offspring  
     - See Wikipedia links on [Breed](http://en.wikipedia.org/wiki/Breed), [Generation](http://en.wikipedia.org/wiki/Generation), [Crossover genetic algorithm](https://en.wikipedia.org/wiki/Crossover_(genetic_algorithm)), [Mutation genetic algorithm](https://en.wikipedia.org/wiki/Mutation_(genetic_algorithm)), [Offspring](http://en.wikipedia.org/wiki/Offspring)  
   - Add new permutations to fill out the current generation
   - Evaluate the fitness of each individual tour
   
Until termination criteria are met

**Subsequent Generations** might be made up of:

*Mutations:*

Make a minor change (for instance, randomly swap two, three, or four cities) to make a different version of an already good order.

*Crossovers:*

Splice the end of one ordering to the end of another. This is not simple to realize with permutation problems (why?)

*Elites*

Keep the few best tours as-is.  
Make copies of them and mutate the copies.

 

### Termination of the Algorithm:

You will repeat the process of creating a generation of tours, checking for the best, determining elites and creating mutations, until the program reaches a terminating condition. Typical ways to terminate this type of algorithm include:
- A solution is found that satisfies minimum criteria (found a tour that is less than some maximum acceptable cost)
- A fixed number of generations is reached. We will use this approach for this project.
- More iterations do not produce better results  
We will use the fixed number of generations approach.

 

### Program Description

Your task in this assignment will be to write **two solutions** to the TSP problem, both of which will run in one program:

- A brute-force permutation program that systematically tries all possible permutations, ultimately computing the optimal answer.

- A genetic algorithm-inspired solution.

### Program Inputs

The program will utilize an input file named *distances.txt* which contains the weights of the edges between cities.  
You will read distances.txt. For simplicity, we will deal with a problem in which all cities connect to all other  
- in other words, with a complete graph.  
We will set up a single graph that can be used for 20 cities, more than we will need for this project.  
You will ALWAYS just read all values of the distances into **a 20 X 20 adjacency matrix.**

*distances.txt* will contain the appropriate number of distances between cities (380), one per line.  
Note - the number of items in the file is 380 rather than 400 because no cities connect to themselves. Read them as doubles.


When your program runs, it will interactively get the following information from the user:  
1. the number of cities to run
2. how many individual tours are in a given generation
3. how many generations to run
4. what percentage of a generation should be comprised of mutated tours

Your program will always keep one elite. The program reads the distances.txt file, gets the input from the user and then the two algorithms will grind away until output is produced.

A graphical representation of how the generations should work is available in the PDF below, along with this file, and *distances.txt* on this assignment page. 

[Project3TSPGraphic.pdf](https://uwf.instructure.com/courses/38127/files/8791967?wrap=1)

### Getting tours to try.

You can generate permutations using an iterative permutation algorithm as follows:

```c++
  void perm1(int permsThisCall) 
  {
      int m, k, p , q, i;
      printS();
      for(i = 1; i < permsThisCall; i++)
      {
          m = NUMELEMENTS-2;
          while(s[m]>s[m+1])
          {
              m = m - 1;
          }
          k = NUMELEMENTS-1;
          while(s[m] > s[k])
          {
              k = k - 1;
          }
          swap(m,k);
          p = m + 1;
          q = NUMELEMENTS-1;
          while( p < q)
          {
            swap(p,q);
            p++;
            q--;
          }
          printS();
       }
   }
```
#### Notes on the algorithm:

The algorithm as presented will produce all permutations of *NUMELEMENTS* ints in the s array if the following is met
- int s[] // an int array external to the function
- NUMELEMENTS is the number of ints in the s array that you are permuting
- the parameter permsThisCall is NUMELEMENTS
- you must implement swap so that the state of s is maintained
- function printS() prints the s array, thereby displaying the next permutation.

If permsThisCall is fewer that NUMELEMENTS you will get just that amount of permutations, for instance when you are filling out a generation in the GA.

### Experiments:

You will experiment with various values for these parameters to see which provide the best results for a given number of generations. You will incorporate timer capabilities into the programs so that you know how long runs with various parameters took. You will compare performance of the two approaches for different numbers of cities.

Start at 10 cities and go up by 1 from there until you see a runtime of greater than 5 minutes on the brute force solution. You will not have to go far to get there. Create a table that compares the time results from the approximation compared to the brute force from 10 cities up until the brute force method requires more than 5 minutes. Show what percentage of the optimal solution (eg: 120% of optimal) your approximation solution provides at each run.

### A Timer:

Here is a link to the file: [time.c](https://uwf.instructure.com/courses/38127/files/8791961?wrap=1)

### Output:

When the progam runs, it will display as output:

The number of cities run  
optimal cost from brute force  
time the brute force algorithm took  
cost from the ga  
time the ga took to run  
percent of optimal (eg: 120%) that the ga produced  
