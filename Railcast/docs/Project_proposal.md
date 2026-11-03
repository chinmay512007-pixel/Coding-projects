# RailCast — Train Journey and Estimated Arrival Management System

## 1. Student Information

- **Student Name:** Chinmay Pradeep Mudgalkar
- **Roll Number:** 612507038
- **Division/Batch:** 1
- **Project Title:** RailCast — Train Journey and Estimated Arrival Management System
- **GitHub Repository:** https://github.com/chinmay512007-pixel/Coding-projects.git

## 2. Engineering Scenario

RailCast belongs to the transportation and railway-information domain. Railway passengers often need to understand a train's current journey status, its delay, and the approximate time remaining before arrival at a destination.

For a small software prototype, train information can be maintained as structured records containing train identifiers, station names, journey status, remaining distance, average speed, and recorded delay. This information can be processed to produce an estimated remaining travel time and arrival estimate.

A modular software application can organize these records, validate information, perform calculations, and generate useful reports. This project demonstrates how fundamental C programming and software engineering practices can be applied to a realistic transportation problem.

## 3. Problem Statement

Train journey information must be organized and processed consistently to support basic journey-status and arrival-time estimates. A manually maintained collection of records can make searching, updating, validating, and calculating information inconvenient and error-prone.

RailCast aims to provide a small, modular C application that maintains train records, retrieves them by identifier, calculates estimated travel time, incorporates recorded delay, and stores information for subsequent use.

The initial implementation will use sample or manually maintained data. It will not claim to provide live railway tracking or guaranteed arrival predictions.

## 4. Proposed Solution

RailCast will provide a menu-driven C application for managing train journey records.

The application will support train-record creation and modification, searching by train identifier, displaying train information, estimating remaining travel time, calculating an arrival estimate, saving and loading records, and generating reports.

The software will use structures and enumerations to represent train information and status. Separate modules will handle train management, ETA calculations, validation, file storage, and report generation.

The application will be designed so that another developer can build, run, test, understand, and extend it.

## 5. Target Users

1. **Student or demonstration user:** Enters sample train data and demonstrates the application's functions.
2. **Train-information operator (simulated):** Maintains journey records and updates recorded delays or status.
3. **Developer or evaluator:** Builds the application, runs automated tests, inspects the architecture, and verifies its behaviour.

These are intended users of the prototype, not claims that RailCast is already deployed for actual railway operations.

## 6. Project Scope

### In scope

- Create, display, search, and modify train records.
- Represent train status using an enumeration.
- Validate identifiers, numerical values, and text fields.
- Calculate travel time from remaining distance and average speed.
- Incorporate recorded delay into an estimated remaining time.
- Calculate an estimated arrival clock time when a suitable reference time is available.
- Load and save train records using a file.
- Generate reports such as delayed-train lists and ETA summaries.
- Handle missing records, invalid inputs, and file-operation failures.
- Use modular C source and header files, a Makefile, Google Test, Git, and GitHub.
- Provide proposal, detailed design, diagrams, testing documentation, README, and reflection.

### Out of scope

- Live train-position tracking.
- Direct integration with railway APIs or restricted railway systems.
- Guaranteed or operationally authoritative arrival predictions.
- Production deployment, user accounts, and authentication.
- A public website or mobile application in the college submission.
- Advanced machine-learning predictions, weather integration, and network-wide congestion analysis.

These features may be considered after the academic submission.

## 7. Functional Requirements

- **FR-01:** The system shall create a train record using validated input.
- **FR-02:** The system shall reject invalid or duplicate train identifiers.
- **FR-03:** The system shall search for a train using its identifier.
- **FR-04:** The system shall display the details and status of a selected train.
- **FR-05:** The system shall allow supported fields of an existing train record to be modified.
- **FR-06:** The system shall validate distances, speeds, delays, text fields, and status values.
- **FR-07:** The system shall calculate estimated remaining travel time from distance and average speed.
- **FR-08:** The system shall calculate a total remaining-time estimate that incorporates recorded delay.
- **FR-09:** The system shall load stored train records from a data file.
- **FR-10:** The system shall save train records and report storage errors.
- **FR-11:** The system shall generate a report of train status and estimated journey information.
- **FR-12:** The system shall report invalid input, missing records, capacity limits, and file errors without uncontrolled termination.
- **FR-13:** The system shall provide a menu through which users can select application operations and exit safely.

## 8. Non-Functional Requirements

- **NFR-01 — Readability:** Source code shall use meaningful names, consistent indentation, and appropriate comments.
- **NFR-02 — Modularity:** Train management, calculations, validation, storage, and reporting shall have clear responsibilities.
- **NFR-03 — Reliability:** Invalid inputs and failed file operations shall be handled explicitly.
- **NFR-04 — Build quality:** The C application shall compile without warnings using `-Wall -Wextra -Wpedantic`.
- **NFR-05 — Testability:** At least three important functions shall be tested through at least ten meaningful, repeatable Google Test cases.
- **NFR-06 — Build automation:** The Makefile shall provide `all`, `run`, `test`, and `clean` targets.
- **NFR-07 — Maintainability:** Public interfaces shall be declared in guarded header files.
- **NFR-08 — Portability:** The project shall avoid machine-specific absolute paths and document its required build tools.
- **NFR-09 — Documentation:** A developer shall be able to understand and build the project using the repository documentation.
- **NFR-10 — Version control:** Changes shall be maintained through meaningful Git commits.

## 9. Initial Modules

| Module | Responsibility |
|---|---|
| `main.c` | Initialise the application, control the menu, and coordinate modules |
| `trains.c/.h` | Define and manage train records; search and modify records |
| `eta.c/.h` | Calculate travel time and estimated remaining time |
| `validation.c/.h` | Validate fields and input values |
| `file_handler.c/.h` | Load and save train records |
| `report.c/.h` | Generate status and ETA reports |

## 10. Initial Architecture

**User → Menu interface (`main.c`) → Application modules**

The application modules coordinate with train management, validation, ETA calculations, file storage, and reporting. Train records are loaded from a data file at startup and saved after relevant modifications. Results and errors are displayed to the user.

## 11. High-Level Workflow

1. Start the application.
2. Initialise the train-record collection.
3. Load existing records and handle any file errors.
4. Display the main menu.
5. Read and validate the user's choice.
6. Call the appropriate module.
7. Display results or error messages.
8. Save modifications when required.
9. Return to the menu or exit cleanly.

## 12. Planned C Concepts

- **Structures:** Group the fields belonging to a train.
- **Enumerations:** Represent train status and, where useful, operation results.
- **Arrays:** Store a bounded collection of train records.
- **Functions:** Separate calculations, validation, searching, storage, and reporting.
- **Pointers:** Pass records and collections to functions.
- **Strings:** Store train names and station names.
- **Named constants:** Define array capacity and text-size limits.
- **File handling:** Persist records across application runs.
- **Header files:** Define public interfaces and prevent duplicate declarations.
- **Return codes:** Communicate success and failure to calling functions.
- **Automated testing:** Verify important functions using Google Test.

## 13. Limitations

The initial application will use sample or manually entered information rather than live railway data. Its estimates will depend on the accuracy of the entered distance, average speed, reference time, and recorded delay. The model will not automatically account for changing speed, new delays, or actual railway operating conditions.

## 14. Expected Outcome

The expected outcome is a modular, menu-driven C application that manages train records, calculates basic ETA estimates, stores and retrieves data, produces reports, and demonstrates input validation, error handling, automated testing, build automation, version control, and technical documentation.
