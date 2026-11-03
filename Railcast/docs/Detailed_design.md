# RailCast — Detailed Software Design

## 1. Software Architecture

RailCast will use a modular, layered design.

- **User interface layer:** `main.c` reads menu choices and displays results.
- **Train-management layer:** `trains.c` creates, searches, retrieves, and modifies train records.
- **Validation layer:** `validation.c` checks input fields and numerical ranges.
- **Calculation layer:** `eta.c` calculates travel time and remaining-time estimates.
- **Storage layer:** `file_handler.c` reads and writes train records.
- **Reporting layer:** `report.c` produces processed summaries.

### Module interaction

User → `main.c` → validation and train-management modules → ETA, storage, or reporting modules → results returned to `main.c` for display.

The application will use a bounded array of train records initially. This avoids unnecessary dynamic-memory complexity for a small, fixed-capacity prototype.

## 2. Module Design

| Module | Public responsibilities | Dependencies |
|---|---|---|
| `main.c` | Initialise, load records, run menu, coordinate operations, save, exit | Other application modules |
| `trains.c/.h` | Initialise, add, search, display, and update records | `validation.h` as needed |
| `eta.c/.h` | Calculate travel time and total ETA | Standard C library |
| `validation.c/.h` | Validate IDs, strings, distances, speeds, delays, and status | Standard C library |
| `file_handler.c/.h` | Load and save the record collection | Train definitions and standard C library |
| `report.c/.h` | Summarise train status and estimated journey information | Train definitions and ETA functions |

Each module will have a corresponding header with include guards and public declarations. Function implementations will remain in `.c` files.

## 3. Data Design

### Train structure

The existing `Train` structure will be extended only as required by the agreed scope.

Proposed fields:

| Field | C type | Validation rule |
|---|---|---|
| `id` | `int` | Positive and unique |
| `name` | `char[50]` | Non-empty, null-terminated text |
| `current_station` | `char[50]` | Non-empty, null-terminated text |
| `destination_station` | `char[50]` | Non-empty, null-terminated text |
| `delay_minutes` | `int` | Non-negative |
| `status` | `enum TrainStatus` | One of the supported status values |
| `remaining_distance_km` | `double` | Finite and non-negative |
| `average_speed_kmph` | `double` | Finite and greater than zero when ETA is requested |

`remaining_distance_km` and `average_speed_kmph` are proposed additions; they must be added to the implementation before the application can use train-specific values.

### Enumerations and constants

The existing `TrainStatus` enumeration will represent `ON_TIME`, `DELAYED`, and `CANCELLED`.

Named constants will define record capacity, text-field sizes, and any chosen validation limits. Exact limits will be selected and documented before implementation.

The data collection will use a fixed maximum capacity. Record insertion must fail safely when that capacity is reached.

## 4. Function Design

### Train-management functions

- `initialize_trains(...)`
  - Purpose: initialise the record collection.
  - Result: a valid initial collection or an explicitly defined initialization outcome.
  - Errors: invalid pointer or unsupported capacity, if applicable.

- `find_train_by_id(...)`
  - Purpose: locate a train using its identifier.
  - Result: matching index or `-1` when no match exists.
  - Preconditions: valid collection and a valid collection size.

- `add_train(...)`
  - Purpose: add a validated record.
  - Result: success or a defined error status.
  - Errors: duplicate ID, invalid fields, null pointers, or full collection.

- `update_train(...)`
  - Purpose: modify an existing train's supported fields.
  - Result: success or a defined error status.
  - Errors: missing ID or invalid updated values.

### ETA functions

- `calculate_travel_time(double distance_km, double speed_kmph)`
  - Purpose: calculate travel time in hours.
  - Formula: `distance_km / speed_kmph`.
  - Invalid arguments must produce a documented failure result.

- `calculate_total_eta(double travel_time_hours, int delay_minutes)`
  - Purpose: convert travel time to minutes and add recorded delay.
  - Formula: `travel_time_hours * 60 + delay_minutes`.
  - The function must reject invalid inputs using the selected error-handling convention.

### Validation functions

- `validate_train_id(...)`: ensure that the identifier is within the documented range.
- `validate_text(...)`: reject empty or overlong text.
- `validate_distance(...)`: reject negative or non-finite distances.
- `validate_speed(...)`: reject non-positive or non-finite speeds.
- `validate_delay(...)`: reject negative delay values.
- `validate_train_status(...)`: reject unsupported enumeration values.

### File-handling functions

- `load_trains_from_file(...)`: read stored records and report success or failure.
- `save_trains_to_file(...)`: write records and check for write and close errors.

The exact signatures and return codes will be finalized in the headers before implementation.

### Reporting functions

- `generate_status_report(...)`: summarise train statuses.
- `generate_eta_report(...)`: produce estimates for records with valid ETA inputs.

Reporting functions should not modify train records unless explicitly required by their contract.

## 5. Input-Validation Plan

- Reject non-numeric menu choices.
- Reject invalid, negative, or duplicate train identifiers.
- Reject empty or overlong names and station fields.
- Reject negative distance or delay values.
- Reject zero or negative speed when calculating ETA.
- Reject non-finite floating-point values such as NaN or infinity.
- Reject unsupported train-status values.
- Handle missing records and full collection capacity.
- Validate file records before adding them to the in-memory collection.
- Handle end-of-file and input-stream errors without entering an uncontrolled loop.

For robust line-based input, the application should use `fgets()` and checked conversion functions rather than relying on unchecked input operations.

## 6. File-Handling Plan

The initial implementation will use a text file such as `data/trains.txt`.

Each record will contain the fields required to reconstruct one train. A documented delimiter-separated format may be used, provided the format safely handles text fields and rejects malformed records.

- **Startup:** attempt to load the existing file.
- **Missing file:** initialise an empty collection or the documented sample collection.
- **Add or update:** validate the modified record before accepting it.
- **Save:** write the current collection and check all relevant file-operation results.
- **Load errors:** report malformed records and apply a documented policy rather than silently treating corrupt data as valid.
- **Write errors:** report failure and do not claim the data was saved successfully.

The selected file format and recovery policy must be documented in the README.

## 7. Error-Handling Strategy

Functions will return meaningful status codes or documented failure values.

The design will cover:

- Invalid function arguments.
- Null pointers.
- Missing train IDs.
- Duplicate train IDs.
- Full record capacity.
- Invalid numerical values.
- Invalid or malformed file data.
- File-open, read, write, and close failures.
- Invalid menu selections.

The application will display understandable error messages and return to the menu when recovery is safe. It will not silently ignore function return values.

## 8. Application Workflow

1. Start and initialise the application.
2. Load train records.
3. Display the menu.
4. Read and validate the user's choice.
5. Call the selected operation.
6. Validate record data where necessary.
7. Perform the operation and report its result.
8. Save changed records when required.
9. Repeat until the user selects exit.
10. Complete cleanup and terminate.

## 9. Unit-Test Plan

Google Test will be used from C++ test files, while the application logic remains in C.

The C functions exposed to C++ tests will use `extern "C"` declarations when required.

The test suite will cover at least three important functions and contain at least ten meaningful test cases. Proposed cases include:

### ETA tests

1. Valid distance and speed.
2. Zero remaining distance.
3. Negative distance.
4. Zero speed.
5. Negative speed.
6. Valid travel time plus a positive delay.
7. Invalid delay or invalid travel-time input.

### Train-management tests

8. Search for an existing train.
9. Search for a missing train.
10. Reject a duplicate train ID.
11. Reject an invalid record.
12. Reject insertion when capacity is reached.

### File and validation tests

Additional tests will cover malformed records, failed file operations where practical, invalid text, and valid boundary values.

Each test will define an expected result, run independently, and avoid dependence on test order. Temporary test files will be cleaned up.

## 10. Makefile Design

The Makefile will provide:

- `make all`: build the application.
- `make run`: build if necessary and run the application.
- `make test`: build and execute the Google Test suite.
- `make clean`: remove generated executables, object files, and build artifacts.

Compiler variables and flags will be defined centrally. Source files will compile into separate object files, and the application will link from those objects.

The test target will compile or link the C modules with the C++ test runner and the installed Google Test libraries. Exact compiler and library commands will depend on the available Windows/MSYS2 toolchain.

## 11. Coding Standards

- Four spaces per indentation level.
- Consistent brace placement and naming.
- One statement per line.
- Header guards in every public header.
- Named constants instead of unexplained numeric limits.
- Functions with a single clear responsibility.
- Checked return values and explicit error handling.
- No unused functions, variables, or commented-out implementation.
- Build using `-Wall -Wextra -Wpedantic` and resolve warnings.

## 12. Verification and Release

Before submission:

1. Run the full build from a clean state.
2. Execute the application with valid and invalid inputs.
3. Run `make test` and verify all tests pass.
4. Verify `make clean` removes generated files.
5. Clone the repository into a fresh directory.
6. Follow the README instructions without relying on the original working directory.
7. Check the repository for missing documents, generated binaries, and accidental temporary files.
8. Rehearse the demonstration and explain the module responsibilities, ETA formula, test cases, and known limitations.
