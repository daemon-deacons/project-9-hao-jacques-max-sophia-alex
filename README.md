## Part 1
Below is the code output recieved when running Part 1 minus the prolog.

```
Process 0 sending 10 to 1, tag 201 (4 processes in ring)
Process 0 sent to 1
Process 0 decremented value: 9
Process 0 decremented value: 8
Process 0 decremented value: 7
Process 0 decremented value: 6
Process 0 decremented value: 5
Process 0 decremented value: 4
Process 0 decremented value: 3
Process 0 decremented value: 2
Process 0 decremented value: 1
Process 0 decremented value: 0
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
Execution complete!
```

## Part 2
The execution graph for each of the different message passing methods is shown in the graph below.

// ADD GITHUB IMAGE REFERENCE HERE!

Although the MPI code remains the same, the allowed MPI interface is changed which accounts for differences in the execution time. The slowest MPI interface is tcp, self with an average of 60.2 seconds and a standard deviation of 0.84 seconds. The next fastest MPI interface is tcp, vader, self with an avaerage execution time of 43 seconds and a standard deviation of 0.71 seconds. The fastest MPI interface is usnic, vader, self with an average execution time of just 13.8 seconds and a standard deviation of 0.45 seconds.

## Part 3
The execution graphs for each of the different message passing methods is shown in the graph below.

// ADD GITHUB IMAGE REFERENCE HERE!

Although the MPI code remains the same, the allowed MPI interface is changed which accounts for differences in the execution time. Interestingly, the slowest MPI interface is usnic, vader, self with an average of 480.6 seconds and a standard deviation of 36.72 seconds. The next fastest MPI interface is tcp, self with an avaerage execution time of 424.4 seconds and a standard deviation of 3.65 seconds. The fastest MPI interface is tcp, vader, self with an average execution time of just 416.8 seconds and a standard deviation of 18.01 seconds

Below is the code output recieved when running Part 3 minus the prolog.

```
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 1,1 ran in 429
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 1,2 ran in 424
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 1,3 ran in 419
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 1,4 ran in 424
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 1,5 ran in 426
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 2,1 ran in 388
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 2,2 ran in 421
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 2,3 ran in 413
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 2,4 ran in 435
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 2,5 ran in 427
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 3,1 ran in 487
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 3,2 ran in 515
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 3,3 ran in 494
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 3,4 ran in 489
Process 0 sent to 1
Process 0 exiting
Process 1 exiting
Process 2 exiting
Process 3 exiting
The final value of the double is 816921454521178229047296.000000
Run 3,5 ran in 418
Execution complete!
```
