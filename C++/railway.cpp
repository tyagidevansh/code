
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket {
protected:
    string passengerName;
    int seatNumber;
    double fare;

public:
    Ticket(const string& name, int seat, double ticketFare)
        : passengerName(name), seatNumber(seat), fare(ticketFare) {}

    virtual void displayDetails() const {
        std::cout << "Passenger: " << passengerName << "\nSeat Number: " << seatNumber
                  << "\nFare: " << fare << "\n";
    }

    virtual double calculateFare() const {
        return fare;
    }
};

class FirstClassTicket : public Ticket {
public:
    FirstClassTicket(const string& name, int seat)
        : Ticket(name, seat, 200.0) {}

    void displayDetails() const override {
        cout << "First Class Ticket\n";
        Ticket::displayDetails();
    }
};

class SecondClassTicket : public Ticket {
public:
    SecondClassTicket(const string& name, int seat)
        : Ticket(name, seat, 100.0) {}

    void displayDetails() const override {
        cout << "Second Class Ticket\n";
        Ticket::displayDetails();
    }
};

class ThirdClassTicket : public Ticket {
public:
    ThirdClassTicket(const string& name, int seat) 
        : Ticket(name, seat, 50.0) {}
    
    void displayDetails(){
        cout << "Third Class Ticket \n";
        Ticket::displayDetails();
    }
};

class BookingSystem {
private:
    std::vector<Ticket*> tickets;

public:
    void bookTicket(Ticket* ticket) {
        tickets.push_back(ticket);
    }

    void displayAllTickets() const {
        for (const auto& ticket : tickets) {
            ticket->displayDetails();
            std::cout << "------------------------\n";
        }
    }

    double calculateTotalRevenue() const {
        double totalRevenue = 0.0;
        for (const auto& ticket : tickets) {
            totalRevenue += ticket->calculateFare();
        }
        return totalRevenue;
    }
};

int main() {
    BookingSystem bookingSystem;

    printf("----------------Railway Ticket Booking System----------------\n");

    FirstClassTicket firstClassTicket1("Ramesh", 1);
    FirstClassTicket firstClassTicket2("Rajesh", 2);

    SecondClassTicket secondClassTicket1("Rahul", 3);
    SecondClassTicket secondClassTicket2("Raj", 4);

    bookingSystem.bookTicket(&firstClassTicket1);
    bookingSystem.bookTicket(&firstClassTicket2);
    bookingSystem.bookTicket(&secondClassTicket1);
    bookingSystem.bookTicket(&secondClassTicket2);

    std::cout << "All Booked Tickets:\n";
    bookingSystem.displayAllTickets();

    std::cout << "Total Revenue: " << bookingSystem.calculateTotalRevenue() << "\n";

    return 0;
}
