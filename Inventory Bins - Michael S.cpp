#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struct for inventory bins
struct Bin
{
    string description;
    int partCount;
};

// Function to add to bin
void addToBin(Bin& bin, int count)
{
    if (bin.partCount + count <= 30 && count > 0)
    {
        bin.partCount += count;
        cout << count << " parts added to the bin." << endl;
    }
    else
    {
        cout << "Error: Invalid number of parts, or bin cannot hold more than 30 parts." << endl;
    }
}

// Function to subtract from bin
void subFromBin(Bin& bin, int count)
{
    if (bin.partCount - count >= 0 && count > 0)
    {
        bin.partCount -= count;
        cout << count << " parts removed from the bin. Parts remaining are " << bin.partCount << endl;
    }
    else
    {
        cout << "Error: Invalid number of parts or bin cannot have a negative part count." << endl;
    }
}

int main()
{
    cout << "This program keeps track of 10 bins of parts. The user can view the bins, add/remove parts to/from bins, and exit the program.\n";

    // Initialize array of bins
    Bin bins[10] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 10},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12} };

    // Display bins
    while (true)
    {
        // Display the current state of bins
        cout << "Current Inventory:\n";
        for (int i = 0; i < 10; ++i)
        {
            cout << bins[i].description << ": " << bins[i].partCount << " parts\n";
        }

        // Ask the user to choose a bin or quit
        cout << "\nEnter the bin number to select (1-10), or enter 0 to quit: ";
        int choice;
        cin >> choice;

        if (choice == 0)
        {
            // Allow the user to quit the program
            break;
        }
        else if (choice >= 1 && choice <= 10)
        {
            cout << "Selected Bin: " << bins[choice - 1].description << "\n";

            // Ask the user if they want to add or remove parts
            cout << "Do you want to:\n";
            cout << "1. Add parts\n";
            cout << "2. Remove parts\n";
            cout << "Enter your choice (1 or 2): ";
            int operation;
            cin >> operation;

            // If loops checking what to do
            if (operation == 1)
            {
                // Chose to add parts
                cout << "Enter # of parts you wish to add: ";
                int addCount;
                cin >> addCount;
                addToBin(bins[choice - 1], addCount);
            }
            else if (operation == 2)
            {
                // Chose to subtract parts
                cout << "Enter # of parts you wish to subtract: ";
                int subCount;
                cin >> subCount;
                subFromBin(bins[choice - 1], subCount);
            }
            else
            {
                cout << "Invalid Choice. Please enter 1 or 2.\n";
            }
        }
        else
        {
            cout << "Invalid bin number. Please enter a number between 1 and 10.\n";
        }
    }

    cout << "Program Terminated.\n";

    return 0;
}

