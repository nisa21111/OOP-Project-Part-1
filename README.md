# Matchup Analyzer

The first part of my project. A **C++** console application that simulates a 1v1 duel between two **champions**.
Create your own champions and items, assign them to two players, equip items and fight.

## Features

| Option | What it does |
|--------|--------------|
| **1** | Create a champion (name, HP, Armor, MR, AP, AD) and add it to the available list |
| **2** | Create an item (name + bonus HP / Armor / MR / AD / AP) |
| **3** | Enter two usernames and pick a champion for each (at least **2 champions** must exist) |
| **4** | Equip an item on Player 1 or Player 2 (max 6 items per player) |
| **5** | Simulate the duel and print the winner |
| **0** | Exit |

---

## How the duel works

The fight is simulated round by round. In every round both champions attack at the same time.

**Damage reduction**:

```
physical reduction = 100 / (100 + Armor)
magic reduction    = 100 / (100 + Magic Resist)
```

**Damage per round:**

- Every round: `AD × physical reduction of the target`
- Every **3rd round**, an ability hits too: `AP × 1.5 × magic reduction of the target`

## Project structure

| Class | Role |
|-------|------|
| `champion` | Stores name and stats (HP, Armor, MR, AD, AP) |
| `item` | Stores name and bonus stats |
| `player` | Has a username, a selected champion and an inventory (`std::vector<item>`); computes the champion's stats **with items** |
| `matchupCalculator` | Static utility class that runs the duel simulation |
| `menu` | Console UI: lists, creation, setup and the main loop |

## OOP concepts used

- **Encapsulation** – private data members with getters and setters
- **Rule of Three** – copy constructor, copy assignment operator and destructor for classes that own dynamic memory (`char*`)
- **Dynamic memory** – names stored as `char*`, players allocated with `new` / `delete`
- **Static members** – `nrInstances` counters; static `matchupCalculator::predictWinner`
- **Const members** – unique `const int id` for every champion, item and player
- **Operator overloading** – `operator<<`, `operator>>` (friend functions) and `operator=`
- **Composition** – `player` contains a `champion` and a `std::vector<item>`
- **STL** – `std::vector` for available champions, items and inventories
