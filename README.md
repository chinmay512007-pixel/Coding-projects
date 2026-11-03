# RailCast – Train Information and ETA Calculator

## 1. Overview

RailCast is a C-based train information and Estimated Time of Arrival (ETA) calculator. It allows users to search for train details using a unique train ID and estimate the remaining journey time using the distance to the destination and the train's average speed.

The project demonstrates modular programming in C, structures, enumerations, file handling, input validation, and unit testing.

## 2. Problem Statement

Passengers often need a simple way to access train information and estimate how much time remains before reaching their destination.

RailCast addresses this by:
- Storing train information in a text file.
- Allowing users to search for trains using their train ID.
- Displaying train details and current status.
- Calculating estimated travel time based on distance and average speed.
- Including the existing train delay in the final estimate.

## 3. Features

- **Train lookup:** Search for a train using its unique ID.
- **Train information:** Display train name, current station, destination, delay, and status.
- **ETA calculation:** Calculate estimated travel time using distance and average speed.
- **Delay consideration:** Add the recorded delay to the estimated travel duration.
- **File handling:** Load train records from a pipe-separated text file.
- **Input validation:** Handle invalid train IDs, negative distances, invalid speeds, and incorrect inputs.
- **Duplicate detection:** Skip train records with duplicate IDs.
- **Unit testing:** Test important functions using Google Test.

## 4. Technologies Used

- Programming language: C
- Testing framework: Google Test (C++)
- Compiler: GCC
- Build system: GNU Make
- Version control: Git and GitHub

## 5. Project Structure

```
Railcast/
│
├── Data/
│   └── Train.txt
│
├── docs/
│   ├── Detailed_design.md
│   └── Project_proposal.md
│── ETA.c
├── ETA.h
├── Trains.c
├── Trains.h
├── file_handler.c
├── file_handler.h
├── main.c
├── gtest.cpp
├── makefile
└── README.md
```
Module Description

Module

Responsibility

main.c

Controls program execution and user interaction.

Trains.c/.h

Defines train structures, status enumeration, display, and train lookup functions.

ETA.c/.h

Performs travel-time and arrival-time calculations.

file_handler.c/.h

Reads train records from the data file and validates them.

gtest.cpp

Contains unit tests for the core functions.

Data/Train.txt

Stores train records.

docs/

Contains project proposal and detailed design documentation.

6. How ETA Is Calculated

RailCast uses the following calculations:

Step 1: Calculate estimated travel time

[
\text{Travel Time (hours)} =
\frac{\text{Distance (km)}}{\text{Average Speed (km/h)}}
]

Step 2: Include the recorded delay

[
\text{Estimated Duration (minutes)} =
(\text{Travel Time} \times 60) + \text{Delay}
]

For example:

Train ID: 17613

Distance: 75 km

Average speed: 25 km/h

Recorded delay: 0 minutes

Travel time = 75 / 25 = 3 hours.

Estimated duration = 180 + 0 = 180 minutes.

7. Train Data Format

Train records are stored in Data/Train.txt using the following format:

ID|Train Name|Current Station|Destination Station|Delay|Status

Example:

11008|Deccan Express|Pune|Mumbai|15|1
17613|Panvel Nanded Express|Parbhani|Nanded|0|0
12124|Deccan Queen|Pune|Mumbai|0|2
12025|Pune-HBD Shatabdi Express|Pune|Hyderabad|0|1

Train status values:

Value Status

0     ON_TIME

1     DELAYED

2     CANCELLED

8. Installation and Execution

Prerequisites

Make sure the following are installed:

GCC compiler

GNU Make

Google Test

pkg-config

Compile the project

Open a terminal in the project directory and execute:

make

Run the application

make run

Run unit tests

make test

Clean generated files

make clean

9. Testing

Google Test is used to verify the correctness of the core functions.

The current test suite contains 20 unit tests covering:

Normal travel-time calculations.

Zero and negative values.

Invalid speeds and distances.

Very large values and infinity.

Arrival-time calculations with different delays.

Train lookup using valid and invalid IDs.

All 20 tests passed in the latest test run.

10. Current Limitations

Train information is loaded from a locally stored text file.

Train locations and delays are not updated in real time.

ETA calculations depend on user-provided distance and average speed.

The calculation does not currently account for weather, traffic, route conditions, or intermediate station delays.

11. Future Improvements

Integrate live train location and status data.

Incorporate real-time train speed and route information.

Improve ETA accuracy using multiple influencing factors.

Add a graphical user interface.

Introduce a database for train records.

Expand automated testing to include file-handling functionality.

12. Author

Project: RailCast
Language: C
Repository: Coding-projects – GitHub

