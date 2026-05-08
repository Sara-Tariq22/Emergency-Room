# Emergency-Room
## Project Title
ER-PRIORITY: Emergency Room Triage & Patient Management System
## Research Problem
In high-stress medical environments, a standard "First-In, First-Out" (FIFO) queue is insufficient because it treats a minor injury and a life-threatening emergency with the same urgency. Manual tracking of patient priority can lead to human error, delays in critical care, and disorganized waiting rooms.
## Motivation
This project provides an automated, logic-based solution for medical sorting. By using a Priority Queue, the system ensures that patients are ranked by the severity of their condition rather than their arrival time. It offers a clear, real-time visualization of the waiting room, allowing medical staff to focus on care rather than logistics.
## Control Flow

   1. Launch: The application starts and initializes an empty Emergency Room (Linked List).
   2. Dashboard: Displays a menu with options to Admit, Treat, or View the current patient queue.
   3. Admit Patient: The user enters the patient's name and a priority level (1–5).
   4. Priority Sorting: The system automatically traverses the Linked List and "inserts" the new patient into the correct position based on their medical urgency.
   5. Treat Patient: The doctor selects "Treat Next." The system removes the person at the very front (the highest priority) and frees the memory.
   6. Real-Time Update: The dashboard refreshes to show the new order of remaining patients.

## Implementation Strategy

* Tech Stack: Built using C++ to leverage manual memory management and high-performance logic.
* Data Structures:
* Linked List: Used for the underlying structure to allow for O(1) removals and dynamic growth.
   * Priority Queue Logic: Custom-built insertion sort algorithm to maintain the list in priority order.
* Data Models: Uses a struct Patient (Node) containing the patient's name (string), priority (integer), and a pointer (next) to the next patient in line.
* Memory Management: Utilizes dynamic memory allocation (new and delete) to ensure the app only uses as much RAM as there are patients in the room.
* Encapsulation: All logic is contained within an Emergency Room class to keep the code modular and protect the patient data from unauthorized outside modification.



