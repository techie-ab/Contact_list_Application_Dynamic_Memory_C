# 📒 Contact List Application

A lightweight contact management system in C using dynamic memory allocation. This program allows users to store, search, delete, and display contacts entirely in memory. It's a simple but elegant example of dynamic array resizing and interactive command-line design.

---

## ✨ Features

- **Add Contact**: Enter a name and phone number. List expands dynamically with `realloc`.
- **Delete Contact**: Remove a contact by name.
- **Search Contact**: Locate and display contact details.
- **Display All Contacts**: View all saved contacts.
- **Memory Efficient**: Automatically resizes based on usage.

---

## 🔧 How It Works

- Contacts are stored in a dynamically growing array (`Contact *list`) managed via pointers.
- Memory is allocated and resized using `malloc` and `realloc`.
- Deletion and searching are handled with `strcmp`.
- Designed to keep everything in RAM — no file storage included.

---

## 🧪 Compile & Run

1. **Compile** using a C compiler:
   ```bash
   gcc contact_list.c -o contact_list
