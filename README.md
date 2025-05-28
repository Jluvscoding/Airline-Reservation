



```markdown...
 ✈️ Airline Reservation System in C

 🧠 Project Overview

This is a **simple console-based Airline Reservation System** developed in C. It allows users (via terminal input) to:
- Add and search for flights
- Add passengers
- Book or cancel flight reservations
- View passenger bookings

This project simulates a basic version of an airline reservation system — **ideal for beginners** in C who want to learn how to manage structures, arrays, and simple logic-based flows.



  Features

- ✅ Add flights with details (origin, destination, times, price, capacity)
- 🔍 Search for available flights by route
- 👤 Register passengers with ID, name, and contact
- 🎟 Book flights for registered passengers
- ❌ Cancel flight bookings
- 📄 View all bookings by passenger ID



 🚀 How to Run

1. **Compile the code**:
   bash
   gcc airline_reservation.c -o airline_reservation
   ```

2. **Run the executable**:
   ```bash
   ./airline_reservation
   ```



 🗂 Menu Structure

You'll see a menu like this:
```
Airline Reservation System Menu:
1. Add Flight
2. Search Flights
3. Add Passenger
4. Book Flight
5. Cancel Flight
6. View Passenger Bookings
7. Save Data
0. Exit
```

Use the number keys to interact with the system.



 📦 Project Structure

- `Flight`: Struct storing all flight-related data.
- `Passenger`: Struct for storing each passenger's details.
- `Booking`: Struct linking a passenger to a flight.

These are stored in global arrays (`flights[]`, `passengers[]`, `bookings[]`), simulating basic in-memory data storage.



 How to Approach the Code

1. **Start at `main()`**: This gives you an overview of the system's menu.
2. **Each menu option** corresponds to a function (e.g., `add_flight()`, `book_flight()`).
3. **Understand the structs**: Knowing what data each struct holds helps you understand data flow.
4. **Observe global variables**: Like `num_flights` or `num_bookings`, they help track the state.

If you're looking to extend the project, consider:
- Adding seat number or booking date
- Integrating file I/O for actual data persistence
- Implementing admin authentication



 💡 Efficiency and Limitations

This system is lightweight and efficient for **small-scale simulation** and learning:
- ✅ Uses basic data structures (arrays and structs)
- ✅ Simple logic for booking and cancellation
- ❌ Does **not** use file persistence (no save/load from disk yet)
- ❌ Limited to fixed-size arrays (e.g., 100 flights max)

> For larger real-world systems, a database and dynamic memory handling would be necessary.



 🙌 Credits

Developed for educational purposes to demonstrate **structs, functions, user input, and modular C programming**. A great base project for students or those exploring systems development in C.





