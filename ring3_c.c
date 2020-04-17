/*
 * Copyright (c) 2004-2006 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2006      Cisco Systems, Inc.  All rights reserved.
 *
 * Simple ring test program in C.
 */

#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rank, size, next, prev, num_times, tag = 201, tagB = 202;
    int num_elements = 1024 * 1024 * 1024; //= 2^30
    int i = 0; // For some reason, mpicc could not compile for loops with for (int i = 0; ...)    

    // Allocate an array of 2^30 doubles.
    double *message = (double *)malloc(num_elements * sizeof(double));

    /* Start up MPI */

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Calculate the rank of the next process in the ring.  Use the
       modulus operator so that the last process "wraps around" to
       rank zero. */

    next = (rank + 1) % size;
    prev = (rank + size - 1) % size;

    /* If we are the "master" process (i.e., MPI_COMM_WORLD rank 0),
       put the number of times to go around the ring in the
       message. */

    if (0 == rank) {
        num_times = 10;
        srand48(0); // It is important to call srand48()
                    // right before the loop initializing the array.
        for (i = 0; i < num_elements; ++i) {
                message[i] = drand48();
        }


        MPI_Send(&num_times, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
        MPI_Send(message, num_elements, MPI_DOUBLE, next, tagB, MPI_COMM_WORLD);
        printf("Process 0 sent to %d\n", next);
    }

    /* Pass the message around the ring.  The exit mechanism works as
       follows: the message (a positive integer) is passed around the
       ring.  Each time it passes rank 0, it is decremented.  When
       each processes receives a message containing a 0 value, it
       passes the message on to the next process and then quits.  By
       passing the 0 message first, every process gets the 0 message
       and can quit normally. */

    while (1) {
        MPI_Recv(&num_times, 1, MPI_DOUBLE, prev, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(message, num_elements, MPI_DOUBLE, prev, tagB, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (i = 0; i < num_elements - 1; ++i) {
            message[i] += rank * message[i + 1];
        }

        if (0 == rank) {
            --num_times;
         }

        MPI_Send(&num_times, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
        MPI_Send(message, num_elements, MPI_DOUBLE, next, tagB, MPI_COMM_WORLD);
        if (0 == num_times) {
            printf("Process %d exiting\n", rank);
            break;
        }
    }

    /* The last process does one extra send to process 0, which needs
       to be received before the program can exit */

    if (0 == rank) {
        MPI_Recv(&num_times, 1, MPI_DOUBLE, prev, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(message, num_elements, MPI_DOUBLE, prev, tagB, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (i = 0; i < num_elements - 1; ++i) {
            message[i] += rank * message[i + 1];
        }

        double value = 0;
        for (i = 0; i < num_elements - 1; ++i) {
            value += message[i];
        }

        printf("The final value of the double is %f\n", value);
    }

    /* All done */

    MPI_Finalize();
    return 0;
}
