# Food Item Management System

A simple menu-driven C program to manage a list of food items — built as my first semester C programming project.

## Features

- Add a food item (name, price, quantity)
- Edit an existing food item
- Delete a food item
- View all food items in a table
- Calculate the total cost of all items
- Save the food item list to a file
- Load a previously saved list from a file

## How it works

The program stores food items using simple arrays (name, price, quantity) and uses a menu loop with `switch-case` to let the user choose what to do. Data is saved to and loaded from a plain text file.

## How to run

```bash
gcc -o foodItemManagement foodItemManagement.c
./foodItemManagement
```

## Menu

## Tech used

- C
- File handling (fopen, fprintf, fscanf)

## Author

Md.Bellal Mollah (Nobab)
