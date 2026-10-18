# Banking Management System in C++

## Project Overview
A console-based banking application developed using C++ to demonstrate the four pillars of Object-Oriented Programming (OOP).

## Features
- Deposit and withdraw money with validation.
- Calculate interest for savings accounts.
- Support overdraft limits for current accounts.
- Display account details using runtime polymorphism.

## OOP Concepts Used

**1. Encapsulation**
- Keeps account details private and provides controlled access through member functions.

**2. Inheritance**
- `SavingsAccount` and `CurrentAccount` inherit from `BankAccount`.

**3. Abstraction**
- Uses an abstract `BankAccount` class with a pure virtual `displayDetails()` function.

**4. Polymorphism**
- Uses virtual functions and overriding to implement account-specific behaviour.

## Technologies Used
- C++
- Object-Oriented Programming
- Git and GitHub

## How to Compile
Make sure a C++ compiler such as GCC is installed.

```bash
g++ main.cpp -o banking
```

## How to Run

On Windows:

```bash
.\banking.exe
```

On Linux/macOS:

```bash
./banking
```

## Learning Objective
Built as a learning project to strengthen C++ OOP concepts and prepare for technical interviews.
