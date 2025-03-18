# Delivery Route Optimization Graph

Welcome to the Delivery Route Optimization Graph repository! This project is designed to assist logistics and delivery companies in optimizing their delivery routes while considering constraints like time windows and vehicle capacity. By utilizing graph-based algorithms, such as Dijkstra’s Algorithm, this tool determines the fastest possible routes between locations and validates them against delivery constraints.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Workflow Description](#workflow-description)
- [Contributing](#contributing)
- [Contact](#contact)
 

## Overview

Efficient route planning is essential for delivery operations to reduce costs, meet time windows, and maximize efficiency. This project provides:

- A graph-based representation of delivery locations and routes.

- Dijkstra’s Algorithm implementation to compute the shortest route based on travel time.

- Route validation, ensuring compliance with time windows and vehicle capacity constraints.

- Error handling, preventing incorrect or infeasible route calculations

## Features

 ## Fastest Route Calculation

- Uses Dijkstra’s Algorithm to find the optimal route between two locations.

- Considers bidirectional roads with travel times as weights.

## Delivery Time Window Constraints

- Each location has a time window (earliest and latest delivery time).

- Vehicles must reach within this window to ensure successful deliveries.

## Vehicle Capacity Validation

- Each location has a demand (number of packages to be delivered).

- Ensures the total demand does not exceed vehicle capacity.

## Graph Representation

- Implements an adjacency list to store delivery locations and routes efficiently.

- Supports dynamic addition of locations and roads.

## Error Handling

- Detects and prevents duplicate locations.

- Ensures valid routes before computing paths.

- Handles scenarios where no valid path exists.


## Tech Stack

- C++ (Standard Library) - Core programming language

- Graph Algorithms - Dijkstra’s Algorithm for shortest path computation

- Data Structures

    - unordered_map (hash map) for fast location lookup

    - vector for adjacency list representation

    - priority_queue for efficient shortest path calculations




## Get started

 **Clone the repository:**

   ```bash
   git clone https://github.com/khpartha/DeliveryGraph.git
 
```


## Project structure
 
   ```bash
 delivery-route-optimizer/
│
├── README.md             <- This readme
├── main.cpp              <- Main program file (execution starts here)
├── Graph.cpp             <- Graph class implementation (Dijkstra’s Algorithm)
├── Graph.h               <- Header file for Graph class
└── Makefile              <- Compilation instructions (optional)
 
```
**key Files**
- main.cpp: Contains the program’s execution logic, including adding locations and edges.

- Graph.cpp: Implements the Graph class with shortest path and validation logic.

- Graph.h: Declares functions and data structures used in the Graph class.
## Usage
- **Adding Delivery Locations**
  
 ```bash

DeliveryGraph graph;
graph.addLocation({"A", 8, 12, 5});
graph.addLocation({"B", 9, 13, 3});

```

- **Defining Roads Between Locations**
  
 ```bash

graph.addEdge("A", "B", 10);
graph.addEdge("B", "C", 5);

```

- **Finding the Fastest Route**
  
 ```bash
vector<string> route = graph.shortestPath("A", "E");
graph.printRoute(route);

```
- **Validating the Route**
  
 ```bash

int startTime = 8;
int vehicleCapacity = 15;
bool isValid = graph.validateRoute(route, startTime, vehicleCapacity);

```





## Workflow Description

- **Graph Creation** Delivery locations and roads are added.
-**Shortest Path Calculation**Dijkstra’s Algorithm finds the optimal path.
  
- **Route Validation**:

   - Ensures deliveries fit within time windows.
 
   - Confirms the vehicle can carry the required load.
     
## Contributing
**If you would like to improve the project by**:

- Enhancing the route optimization logic

- Adding support for alternative algorithms (e.g., A)*

- Implementing real-world data integration
 

## Contact 
For any questions, suggestions, or contributions, please feel free to contact me at 4khundrakpampartha@gmail.com.




