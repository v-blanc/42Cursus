<div align="center">

![Banner](assets/banner.png)  
![Language](https://img.shields.io/badge/-00599C?logo=c&logoColor=white)
![Language](https://img.shields.io/badge/Multithreading-000000?logo=outline&logoColor=white)
![Group](https://img.shields.io/badge/Group-Alone-gainsboro)
![Duration](https://img.shields.io/badge/Estimated%20Hours-70h-A65B23)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

> ⚠️ **Important notice for 42 students**  
> This repository is intended as a reference and for educational purposes **only**.  
> Directly copying, submitting, or presenting this code as your own work in the 42 curriculum is a violation of the school's academic integrity policy and may result in disciplinary action.  
>  
> Feel free to read, learn, and get inspired — but always write your own code.

## 🎓 Grade
![Grade](assets/grade.png)

## 📘 Description

**philosophers** is a concurrency-focused project that challenges you to implement the classic **Dining Philosophers Problem**, a well-known example in concurrency theory.  
Using **POSIX threads and mutexes**, the project requires simulating the behavior of philosophers who must think, eat, and sleep without causing **deadlocks**, **race conditions**, or **starvation**.

## 🧠 Key Concepts

- POSIX threads (`pthread`)
- Mutex synchronization (`pthread_mutex`)
- Deadlock prevention
- Timing accuracy (`gettimeofday`, `usleep`)
- State management and shared data access

## 🚀 Usage

1. Build the project:
```
make
```

2. Run the program:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]

# Exemple
./philo 5 800 200 200
```

3. Clean build files:
```bash
make clean      # Remove object files  
make fclean     # Remove objects and binaries  
make re         # Rebuild everything
```

## 🎥 Demo

First `make` the project, then run `./philo 5 1000 200 100 5`:  

![Demo](assets/demo.gif)

> Visual below generated using [Philosophers Visualizer](https://nafuka11.github.io/philosophers-visualizer/)

![Demo-visualizer](assets/demo-visualizer.png)
