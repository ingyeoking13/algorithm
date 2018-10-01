// DON'T EDIT THIS FILE!
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <map>
#include <list>
#include "AdjacencyListDirectedGraph.h"
#include "FlightMap.h"

using namespace std;

void printMenu() {
  cout << "Please select one of the following option:" << endl;
  cout << " a) Print the flight map." << endl;
  cout << " b) Load a flight map from a file." << endl;

  cout << " c) Add an airport." << endl;
  cout << " d) Add a flight connection." << endl;
  cout << " e) Add a round-trip flight connection." << endl;

  cout << " f) Remove an airport." << endl;
  cout << " g) Remove a flight connection." << endl;

  cout << " h) Show information about an airport." << endl;
  cout << " i) Show information about a flight connection." << endl;

  cout << " j) Find a route (a simple path) connecting two airports." << endl;
  cout << " k) List all airports that are reachable from an airport." << endl;

  cout << " l) Find the shortest route connecting two airports." << endl;
  cout << " m) Show the shortest routes to all reachable airports from an airport." << endl;

  cout << " z) Quit this program." << endl;
}


int main(int argc, char *argv[]) {

  bool isVerbose = true;

  // the -q option turns off some outputs to help grading

  if (argc == 2) {
    if (strcmp(argv[1], "-q") == 0) {
      isVerbose = false;
    }
  }

  try {

    FlightMap flight_map;

    bool isExit = false;

    while (!isExit) {  // loop until the user choose to quit

      if (isVerbose) printMenu();
      if (isVerbose) cout << "Your choice: ";
      char choice;
      cin >> choice;
      if (isVerbose) cout << endl;

      switch(choice) {
        case 'a': {   // printFlightMap flight graph
          flight_map.printFlightMap();
          break;
        }
        case 'b': {   // read from file and add to the existing flight graph
          try {
            if (isVerbose) cout << "Please enter the filename: ";
            string filename;
            cin >> filename;
            flight_map.readFromFile(filename);
            cout << "Data read." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'c': { // add an airport
          try {
            if (isVerbose) cout << "Please enter the name of an airport (no white space): ";
            string airport_name;
            cin >> airport_name;
            flight_map.addAirport(airport_name);
            cout << "Airport added." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'd': { // add a connection
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport_origin;
            cin >> airport_origin;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport_dest;
            cin >> airport_dest;
            if (isVerbose) cout << "Please enter the distance between the airport: ";
            double dist;
            cin >> dist;
            flight_map.addConnection(airport_origin, airport_dest, dist);
            cout << "Connection added." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'e': { // add a round-trip connection
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport1;
            cin >> airport1;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport2;
            cin >> airport2;
            if (isVerbose) cout << "Please enter the distance between the airport: ";
            double dist;
            cin >> dist;
            flight_map.addRoundTripConnection(airport1, airport2, dist);
            cout << "Round-trip connection added." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'f': {  // delete an airport
          try {
            if (isVerbose) cout << "Please enter the name of an existing airport: ";
            string airport;
            cin >> airport;
            flight_map.removeAirport(airport);
            cout << "Airport removed." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'g': {  // delete a connection
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport_origin;
            cin >> airport_origin;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport_dest;
            cin >> airport_dest;
            flight_map.removeConnection(airport_origin, airport_dest);
            cout << "Connection removed." << endl;
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'h': {  // show info of an airport
          try {
            if (isVerbose) cout << "Please enter the name of an existing airport: ";
            string airport;
            cin >> airport;
            if (isVerbose) cout << endl;
            flight_map.printAirportInfo(airport);
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'i': {  // show info of a connection
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport_origin;
            cin >> airport_origin;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport_dest;
            cin >> airport_dest;
            if (isVerbose) cout << endl;
            flight_map.printConnectionInfo(airport_origin, airport_dest);
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'j': {  // check connectivity
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport_origin;
            cin >> airport_origin;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport_dest;
            cin >> airport_dest;
            if (isVerbose) cout << endl;
            list<string> route = flight_map.findRoute(airport_origin, airport_dest);
            if (route.size() > 0) {
              cout << airport_origin << " can be connected to " << airport_dest << ":" << endl;
              cout << "  ";
              flight_map.printRoute(route);
              cout << "  (Distance = " << flight_map.calcRouteDistance(route) << ")" << endl;
              cout << endl;
            } else {
              cout << "No route connecting " << airport_origin << " to " << airport_dest << "." << endl;
            }
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'k': {  // print connected component
          try {
            if (isVerbose) cout << "Please enter an airport: ";
            string airport;
            cin >> airport;
            if (isVerbose) cout << endl;
            list<string> connected_airport = flight_map.findReachableAirports(airport);
            if (connected_airport.size() == 0) {
              cout << airport << " cannot reach any other airport." << endl;
            } else {
              cout << airport << " can connect to these airports:" << endl;
              for (list<string>::const_iterator iter = connected_airport.begin();
                   iter != connected_airport.end(); ++iter) {
                cout << "  " << *iter;
              }
              cout << endl;
            }
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'l': {  // find the shortest path
          try {
            if (isVerbose) cout << "Please enter the airport at the origin: ";
            string airport_origin;
            cin >> airport_origin;
            if (isVerbose) cout << "Please enter the airport at the destination: ";
            string airport_dest;
            cin >> airport_dest;
            if (isVerbose) cout << endl;
            list<string> route = flight_map.findShortestRoute(airport_origin, airport_dest);
            if (route.size() > 0) {
              cout << "One of the shortest routes connecting " << airport_origin << " to " << airport_dest << " is:" << endl;
              cout << "  ";
              flight_map.printRoute(route);
              cout << "  (Distance = " << flight_map.calcRouteDistance(route) << ")" << endl;
            } else {
              cout << "No route connecting " << airport_origin << " to " << airport_dest << "." << endl;
            }
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'm': {  // print all shortest paths
          try {
            if (isVerbose) cout << "Please enter an airport: ";
            string airport;
            cin >> airport;
            if (isVerbose) cout << endl;
            cout << "All shortest routes from " << airport << ":" << endl;
            flight_map.printAllShortestRoutes(airport);
          } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
          }
          break;
        }
        case 'z':  // Exit the program
          if (isVerbose) cout << "Bye!" << endl;
          isExit = true;
          break;
        default:
          cout << "Error: Unknown option." << endl;
      }

      if (isVerbose) cout << endl;
    }

    return 0;

  } catch (const exception &e) {
    // The error message should be printed to cerr,
    // but for grading purpose, we send it to cout.
    cout << "Error: " << e.what() << endl;
  }

}
