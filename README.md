# CheckMate

A simple **CLI-based todo application in C** to manage, track, and complete your tasks efficiently.

## Features

- Add new tasks with automatic ID assignment
- Delete tasks by ID
- Mark tasks as done or undone
- List all tasks
- Cross-platform (Windows, Linux, macOS) with terminal interface

## Installation

1. Clone the repository:
```bash
git clone https://github.com/YourUsername/CheckMate.git
cd CheckMate
```
2.Compile the Project
```bash
gcc main.c utility.c -o checkmate
```
## Usage
```bash
./checkmate <command> [argument]
```
## Commands
 - `add "Task description"` → Adds a new task
 - `delete <task_id>` → Deletes a task by its ID
 - `done <task_id>` → Marks a task as done
 - `undone <task_id>` → Marks a task as not done
 - `list` → Lists all tasks
 - `clear` → Clears all tasks

## Examples
```bash
./checkmate add "Finish Homework"
./checkmate done 1
./checkmate list
```
## Lisence
This project is licensed under the [MIT License](https://github.com/erenyata/CheckMate/blob/main/LICENSE).
