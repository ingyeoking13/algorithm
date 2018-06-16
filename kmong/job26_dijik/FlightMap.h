#ifndef ASSIGNMENT5_FLIGHTMAP_H
#define ASSIGNMENT5_FLIGHTMAP_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <list>
#include <vector>
#include "AdjacencyListDirectedGraph.h"

using namespace std;

class FlightMap {

  typedef AdjacencyListDirectedGraph<string,double> FlightGraph;

   // AirportDB is the type of the airport database.
  typedef map<string, FlightGraph::Vertex> AirportDB;

  // This class should contain two member variables only: flight_graph and airport_db.
  // You should not declare any other member variables.

  /*
   */
  FlightGraph flight_graph;

  /*
   * airport_db is a mapping from the names of airports to the corresponding vertices
   * in flight_graph.  There should be a one-to-one corresponding between the entries
   * in this database and the set of vertices in flight_graph.
   */
  AirportDB airport_db;

  /*
   * Find and return the vertex of an airport. If the airport name
   * does not appear in the vertex database, create a new vertex and return it.
   *
   * airport - the name of an airport
   * return the vertex of the airport
   */
  FlightGraph::Vertex findOrCreateAirport(const string &airport);

  /*
   * Find and return the vertex of an airport by reference.
   * If the airport name does not appear in the vertex database,
   * do not create a new vertex. Instead, it returns false.
   *
   * vertex - the return variable holding the vertex found.
   * airport - the name of an airport
   * return true if the vertex is found; otherwise, return false
   */
  bool findAirport(FlightGraph::Vertex &vertex, const string &airport);

  /*
   * Print a connection as "origin -> destination  (distance)".
   *
   * edge - a connection
   */
  void printConnection(const FlightGraph::Edge &edge);

public:

  /*
   * Check whether an airport exists in the airport database.
   *
   * airport - the name of an airport
   * return true if the airport is found; otherwise, return false
   */
  bool isAirportExist(const string &airport);

  /*
   * Check whether a connection exists in the flight_graph.
   *
   * airport1 - the origin of a connection
   * airport2 - the destination of a connection
   * return true if the connection is found; otherwise, return false
   */
  bool isConnectionExist(const string &airport1, const string &airport2);

  /*
   * Read a list of connections from a file and create the vertices and edges in flight_graph.
   * The file should contain a list of triples: (origin, destination, distance)
   * Throw an exception if the data file is corrupted or some connections
   * are duplicated or exists in flight_graph
   *
   * filename - the file name of the file.
   */
  void readFromFile(const string &filename);

  /*
   * Add an airport to the airport database and flight_graph.
   * Throw an exception if the airport exists.
   *
   * airport - the name of an airport
   */
  void addAirport(const string &airport);

  /*
   * Remove an airport from the airport database and flight_graph.
   * Also, remove all connections related to the airport from flight_graph.
   * Throw an exception if the airport does not exist.
   *
   * airport - the name of an airport
   */
  void removeAirport(const string &airport);

  /*
   * Add a connection to flight_graph.
   * Throw an exception if 1) the airports of the connection do not exist
   * 2) the connection exists, or 3) the distance is not a positive number.
   *
   * airport1 - the name of an airport at the origin
   * airport2 - the name of an airport at the destination
   * dist - the distance of the connection between airport1 and airport2
   */
  void addConnection(const string &airport1, const string &airport2, double dist);

  /*
   * Add two connections to flight_graph, one from airport1 to airport2,
   * and the other from airport2 to airport1.
   * Throw an exception if 1) the airports of the connections do not exist
   * 2) some of the connections exist, or 3) the distance is not a positive number.
   *
   * airport1 - the name of an airport
   * airport2 - the name of an airport
   * dist - the distance of the connection between airport1 and airport2 (both ways)
   */
  void addRoundTripConnection(const string &airport1, const string &airport2, double dist);

  /*
   * Remove a connection from airport1 to airport2
   * Throw an exception if the connection or the airports of the connection
   * do not exist.
   *
   * airport1 - the name of an airport
   * airport2 - the name of an airport
   */
  void removeConnection(const string &airport1, const string &airport2);

  /*
   * Print the information stored in flight_graph.
   */
  void printFlightMap();

  /*
   * Print the information of an airport.
   * Throw an exception if the airport do not exist or
   * data corruption occurs related to the airport.
   *
   * airport - the name of an airport
   */
  void printAirportInfo(const string &airport);

  /*
   * Print the information of a connection.
   * Throw an exception if the connection or the airports of the connection
   * do not exist or data corruption occurs related to the connection.
   *
   * airport1 - the name of an airport at the origin
   * airport2 - the name of an airport at the destination
   */
  void printConnectionInfo(const string &airport1, const string &airport2);

  /*
   * Print a route, which is a list of airport names including
   * both the origin and the destination.
   *
   * route - a route
   */
  void printRoute(const list<string> route);


  // -------------------------------------------------------------------------
  // You will implement the following public member functions in assignment4.cpp.
  // -------------------------------------------------------------------------


  /*
   * Calculate the total distance of a route, which is a list of airport names
   * including both the origin and the destination.
   * Throw an exception if any airport in the route does not exist.
   * Throw an exception if some edges on the route do not exist.
   *
   * route - a route
   * Return the total distance of the route
   */
  double calcRouteDistance(const list<string> route);

  /*
   * Find a route between two airports. The route must be
   * a simple path that contains no cycle. The route does not have
   * to be the shortest route. If there is no route connecting
   * the airports, return an empty list.
   * Throw an exception if some of the given airports does not exist.
   *
   * airport1 - the name of an airport at the origin
   * airport2 - the name of an airport at the destination
   * Return a route connecting airport1 to airport2; return an empty list
   * if no route exists.
   */
  list<string> findRoute(const string &airport1, const string &airport2);

  /*
   * Find the set of all airports reachable from an airport (i.e.,
   * all airports that have routes to connect from the given airport to them).
   * The set should *exclude* the given airport.
   * Throw an exception if the airport do not exist.
   *
   * airport - the name of an airport
   * Return a set of all reachable airport (in any order).
   */
  list<string> findReachableAirports(const string &airport);

  /*
   * Find the shortest route between two airports.  If there exist
   * more than one shortest routes, return any one of them.
   * If there is no route connecting the airports, return an empty list.
   * Throw an exception if some of the given airports does not exist.
   *
   * airport1 - the name of an airport at the origin
   * airport2 - the name of an airport at the destination
   * Return the shortest route connecting airport1 to airport2;
   * return an empty list if no route exists.
   */
  list<string> findShortestRoute(const string &airport1, const string &airport2);

  /*
   * Print all shortest routes to all airports reachable from a given airport
   * between two airports. This function should print one route per line to
   * stdout using printRoute(). At the end of each line, print
   * the distance of the route in the format "(Distance = XXX)",
   * where XXX is the distance returned by calcRouteDistance().
   * If there exist more than one shortest routes of an airport, print any one of them.
   * If there is no route to any other airport, just print nothing.
   * Do not print anything for unreachable airport.
   * Do not print the route to the given airport *itself*.
   * Throw an exception if the given airport do not exist.
   *
   * airport - the name of an airport
   */
  void printAllShortestRoutes(const string &airport);

private:

  // -------------------------------------------------------------------------
  // You can declare any number of private member functions below,
  // and implement them in assignment4.cpp.
  // Notice that you should not any public member functions in this class.
  // You should also not add any public or private member variables in this class.
  // -------------------------------------------------------------------------

  // -------------------------------------------------------------------------
  // You should not modify anything above this line in this class.
  // -------------------------------------------------------------------------




};

#endif //ASSIGNMENT5_FLIGHTMAP_H
