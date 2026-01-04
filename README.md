# Hybrid-Bag-DSA: Self-Balancing Multiset Indexer

## Overview
This project implements a **Hybrid Data Structure** that combines the flexibility of a Singly Linked List (Bag) with the search efficiency of an **AVL Tree**. It is designed to store non-unique elements and provide $O(\log n)$ frequency lookups.

## Technical Implementation
- **Linked List (The Bag):** Used as the primary storage layer to allow $O(1)$ insertions and handle duplicate elements.
- **AVL Tree (The Indexer):** A self balancing Binary Search Tree that tracks item frequencies.
- **Self-Balancing Logic:** Implemented **Left/Right Rotations** and **Balance Factor** checks to maintain a strict height limit, ensuring $O(\log n)$ search performance.
- **Frequency Mapping:** Unlike standard BSTs, each node in this AVL tree stores an `item` and a `freq` counter, optimizing memory for duplicate-heavy datasets.

## 📊 Performance Comparison
| Operation | Linked List (Standard) | Hybrid AVL Index |
| :--- | :--- | :--- |
| **Insertion** | $O(1)$ | $O(1)$ |
| **Search/Frequency** | $O(n)$ | $O(\log n)$ |

## 🎮 How to Run
1. Compile: `gcc main.c Project.c -o hybrid_dsa`
2. Run: `./hybrid_dsa`

A few screenshots of an example run:

<img width="413" height="670" alt="image" src="https://github.com/user-attachments/assets/a9a966cf-fe0e-49c0-9e11-ad14f0747262" />
<img width="397" height="673" alt="image" src="https://github.com/user-attachments/assets/cd8adecf-84ae-4c53-8739-1b60f80eb264" />
<img width="391" height="674" alt="image" src="https://github.com/user-attachments/assets/d5020cc9-07b6-435e-858a-0fa65457ee97" />
<img width="359" height="665" alt="image" src="https://github.com/user-attachments/assets/01c187fc-73be-4df2-bbfa-e8c002ec66a0" />



