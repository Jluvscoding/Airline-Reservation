#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100
#define MAX_BOOKINGS 200
#define MAX_SEATS 150
#define STRING_SIZE 50


typedef struct {
    char flight_number[STRING_SIZE];
    char origin[STRING_SIZE];
    char destination[STRING_SIZE];
    char departure_time[STRING_SIZE];
    char arrival_time[STRING_SIZE];
    int capacity;
    int available_seats;
    float price;
} Flight;

typedef struct {
    int passenger_id;
    char name[STRING_SIZE];
    char contact_info[STRING_SIZE];
} Passenger;


typedef struct {
    int passenger_id;
    char flight_number[STRING_SIZE];
    // Add other booking details if needed (e.g., booking date, seat number)
} Booking;

// Global arrays to store data (in a real system, you'd use databases)
Flight flights[MAX_FLIGHTS];
int num_flights = 0;

Passenger passengers[MAX_PASSENGERS];
int num_passengers = 0;

Booking bookings[MAX_BOOKINGS];
int num_bookings = 0;

// Function prototypes
void add_flight();
void display_flight(Flight *flight);
Flight* find_flight(const char *flight_number);
void search_flights(const char *origin, const char *destination);
void add_passenger();
Passenger* find_passenger(int passenger_id);
void book_flight();
void cancel_flight();
void view_passenger_bookings(int passenger_id);
void save_data(); // Placeholder for saving data to a file
void load_data(); // Placeholder for loading data from a file

int main() {
    load_data(); // Load data at the start

    int choice;
    do {
        printf("\nAirline Reservation System Menu:\n");
        printf("1. Add Flight\n");
        printf("2. Search Flights\n");
        printf("3. Add Passenger\n");
        printf("4. Book Flight\n");
        printf("5. Cancel Flight\n");
        printf("6. View Passenger Bookings\n");
        printf("7. Save Data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_flight();
                break;
            case 2: {
                char origin[STRING_SIZE], destination[STRING_SIZE];
                printf("Enter origin: ");
                fgets(origin, STRING_SIZE, stdin);
                origin[strcspn(origin, "\n")] = 0; // Remove trailing newline
                printf("Enter destination: ");
                fgets(destination, STRING_SIZE, stdin);
                destination[strcspn(destination, "\n")] = 0;
                search_flights(origin, destination);
                break;
            }
            case 3:
                add_passenger();
                break;
            case 4:
                book_flight();
                break;
            case 5:
                cancel_flight();
                break;
            case 6: {
                int passenger_id;
                printf("Enter passenger ID to view bookings: ");
                scanf("%d", &passenger_id);
                getchar(); // Consume newline
                view_passenger_bookings(passenger_id);
                break;
            }
            case 7:
                save_data();
                break;
            case 0:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void add_flight() {
    if (num_flights < MAX_FLIGHTS) {
        Flight new_flight;
        printf("Enter Flight Number: ");
        fgets(new_flight.flight_number, STRING_SIZE, stdin);
        new_flight.flight_number[strcspn(new_flight.flight_number, "\n")] = 0;
        printf("Enter Origin: ");
        fgets(new_flight.origin, STRING_SIZE, stdin);
        new_flight.origin[strcspn(new_flight.origin, "\n")] = 0;
        printf("Enter Destination: ");
        fgets(new_flight.destination, STRING_SIZE, stdin);
        new_flight.destination[strcspn(new_flight.destination, "\n")] = 0;
        printf("Enter Departure Time: ");
        fgets(new_flight.departure_time, STRING_SIZE, stdin);
        new_flight.departure_time[strcspn(new_flight.departure_time, "\n")] = 0;
        printf("Enter Arrival Time: ");
        fgets(new_flight.arrival_time, STRING_SIZE, stdin);
        new_flight.arrival_time[strcspn(new_flight.arrival_time, "\n")] = 0;
        printf("Enter Capacity: ");
        scanf("%d", &new_flight.capacity);
        new_flight.available_seats = new_flight.capacity;
        printf("Enter Price: ");
        scanf("%f", &new_flight.price);
        getchar(); // Consume newline

        flights[num_flights++] = new_flight;
        printf("Flight added successfully.\n");
    } else {
        printf("Maximum number of flights reached.\n");
    }
}

void display_flight(Flight *flight) {
    printf("Flight Number: %s\n", flight->flight_number);
    printf("Origin: %s\n", flight->origin);
    printf("Destination: %s\n", flight->destination);
    printf("Departure Time: %s\n", flight->departure_time);
    printf("Arrival Time: %s\n", flight->arrival_time);
    printf("Capacity: %d\n", flight->capacity);
    printf("Available Seats: %d\n", flight->available_seats);
    printf("Price: %.2f\n", flight->price);
}

Flight* find_flight(const char *flight_number) {
    for (int i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].flight_number, flight_number) == 0) {
            return &flights[i];
        }
    }
    return NULL;
}

void search_flights(const char *origin, const char *destination) {
    printf("\nSearch Results for flights from %s to %s:\n", origin, destination);
    bool found = false;
    for (int i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].origin, origin) == 0 && strcmp(flights[i].destination, destination) == 0 && flights[i].available_seats > 0) {
            display_flight(&flights[i]);
            found = true;
            printf("--------------------\n");
        }
    }
    if (!found) {
        printf("No available flights found for the given route.\n");
    }
}

void add_passenger() {
    if (num_passengers < MAX_PASSENGERS) {
        Passenger new_passenger;
        printf("Enter Passenger ID: ");
        scanf("%d", &new_passenger.passenger_id);
        getchar(); // Consume newline
        printf("Enter Passenger Name: ");
        fgets(new_passenger.name, STRING_SIZE, stdin);
        new_passenger.name[strcspn(new_passenger.name, "\n")] = 0;
        printf("Enter Contact Information: ");
        fgets(new_passenger.contact_info, STRING_SIZE, stdin);
        new_passenger.contact_info[strcspn(new_passenger.contact_info, "\n")] = 0;

        passengers[num_passengers++] = new_passenger;
        printf("Passenger added successfully.\n");
    } else {
        printf("Maximum number of passengers reached.\n");
    }
}

Passenger* find_passenger(int passenger_id) {
    for (int i = 0; i < num_passengers; i++) {
        if (passengers[i].passenger_id == passenger_id) {
            return &passengers[i];
        }
    }
    return NULL;
}

void book_flight() {
    int passenger_id;
    char flight_number[STRING_SIZE];

    printf("Enter Passenger ID for booking: ");
    scanf("%d", &passenger_id);
    getchar(); // Consume newline
    printf("Enter Flight Number to book: ");
    fgets(flight_number, STRING_SIZE, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;

    Passenger *passenger = find_passenger(passenger_id);
    Flight *flight = find_flight(flight_number);

    if (passenger && flight) {
        if (flight->available_seats > 0) {
            bookings[num_bookings].passenger_id = passenger_id;
            strcpy(bookings[num_bookings].flight_number, flight_number);
            num_bookings++;
            flight->available_seats--;
            printf("Flight booked successfully for Passenger ID %d on Flight %s.\n", passenger_id, flight_number);
        } else {
            printf("No available seats on Flight %s.\n", flight_number);
        }
    } else {
        printf("Passenger ID or Flight Number not found.\n");
    }
}

void cancel_flight() {
    int passenger_id;
    char flight_number[STRING_SIZE];
    bool booking_found = false;

    printf("Enter Passenger ID to cancel booking: ");
    scanf("%d", &passenger_id);
    getchar(); // Consume newline
    printf("Enter Flight Number to cancel: ");
    fgets(flight_number, STRING_SIZE, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;

    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].passenger_id == passenger_id && strcmp(bookings[i].flight_number, flight_number) == 0) {
            // Shift remaining bookings to overwrite the cancelled one
            for (int j = i; j < num_bookings - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            num_bookings--;

            Flight *flight = find_flight(flight_number);
            if (flight) {
                flight->available_seats++;
            }

            printf("Booking cancelled successfully for Passenger ID %d on Flight %s.\n", passenger_id, flight_number);
            booking_found = true;
            break;
        }
    }

    if (!booking_found) {
        printf("No booking found for Passenger ID %d on Flight %s.\n", passenger_id, flight_number);
    }
}

void view_passenger_bookings(int passenger_id) {
    printf("\nBookings for Passenger ID %d:\n", passenger_id);
    bool found_booking = false;
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].passenger_id == passenger_id) {
            Flight *flight = find_flight(bookings[i].flight_number);
            if (flight) {
                display_flight(flight);
                printf("--------------------\n");
                found_booking = true;
            }
        }
    }
    if (!found_booking) {
        printf("No bookings found for Passenger ID %d.\n", passenger_id);
    }
}

void save_data() {
    // In a real system, you would implement file I/O or database interaction here
    printf("Saving data (not fully implemented in this example).\n");
}

void load_data() {
    // In a real system, you would implement file I/O or database interaction here
    printf("Loading data (not fully implemented in this example).\n");
}
