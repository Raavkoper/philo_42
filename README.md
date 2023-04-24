# Philosophers

## Description

This project is about the famous dining philosophers problem. A few rules must be respected:
Philosophers spend their time thinking. When they are hungry, they try to eat. They need two forks to eat.

When a philosopher is done eating, he puts down his forks and starts thinking again.
When running the simulation, you must provide the following arguments.

* <number_of_philosophers> 
* <time_to_die> 
* <time_to_eat>
* <time_to_sleep> 
* optional(<number_of_times_each_philosopher_must_eat>)

Once this is provided, the program will create a thread for each philosopher and the main thread will be in charge of the simulation.

Once a philosopher dies, or all philosophers have eaten at least <number_of_times_each_philosopher_must_eat>, the simulation will stop.

The program will wait for each thread to finish before exiting.

All the mutexes and threads must be properly destroyed when the simulation stops.

The mutexes also need to be properly protected. Locked and unlocked in the right order. This is to prevent any deadlocks and dataraces.
