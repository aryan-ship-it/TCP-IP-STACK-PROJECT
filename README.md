This README provides an overview of Object oriented TCP/IP message stack encapsulation, including its Object-oriented design principle, purpose, components, and how it works

**Purpose**

Encapsulating TCP/IP message stacks is a technique for ensuring dependable networked device communication. It divides data into tiny packets that may be sent over the network and put back together at the other end. Each packet gains headers during the encapsulation process, which contain data required for delivery and routing. This project uses the SOLID Object Oriented Design Principle which consists of Single-Responsibility, Open-Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion.

**Components**

Library used:

-  `iostream`: This library provides basic input/output operations in C++. It defines objects such as `cin` and `cout`, which can be used to read and write data to and from the console.

-  `fstream`: This library provides classes for reading from and writing to files in C++. It defines objects such as `ifstream` and `ofstream`, which can be used to read from and write to files, respectively.

-  `string`: This library provides a class for working with strings in C++. It defines functions for manipulating strings, such as `substr()`, `find()`, and `replace()`.
   
- `vector`: This library provides a class for working with dynamic arrays in C++. It defines functions for adding, removing, and accessing elements in a vector, such as `push_back()`, `pop_back()`, and `at()`.
  
-  `queue`: This library provides a class for working with queues in C++. It defines functions for  adding and removing elements from the front and back of a queue, such as `push()`, `pop()`, and `front()`.

-  `map`: This library provides a class for working with associative arrays (also known as maps or dictionaries) in C++. It defines functions for adding, removing, and accessing key-value pairs, such as `insert()`, `erase()`, and `find()`.

-  `cstdlib`: This library provides functions for performing common operations in C++. It defines functions such as `rand()` and `srand()` for generating random numbers, as well as functions for working with memory allocation and program termination.

-  `ctime`: This library provides functions for working with time and dates in C++. It defines functions such as `time()` and `ctime()` for working with timestamps, as well as functions for working with date and time values.

-  `sstream`: This library provides a class for working with string streams in C++. It defines objects such as `stringstream`, which can be used to convert between strings and other data types.

-  `iomanip`: This library provides functions for formatting output in C++. It defines functions for setting the precision and width of output, as well as functions for working with special characters such as tabs and newlines.

-  `bitset`: This library provides a bitset class in C++, which is a container that holds a sequence of bits. It provides several member functions for bit manipulation, such as bitwise AND and OR operations. It changes string to binary.

Relationship shown:

The program showcases the Dependency relationship existing between the following pairs of classes:

-   `IPAddress and NetworkLayer`: The NetworkLayer class uses the IPAddress class to generate random source and destination IP addresses for each message. The NetworkLayer class creates an instance of the IPAddress class and calls its getSourceIPAddress() and getDestIPAddress() methods to get random IP addresses. The NetworkLayer class then sets these IP addresses as the source and destination IP addresses for the message being transmitted. Without the IPAddress class, the NetworkLayer class cannot generate valid source and destination IP addresses, and network communication will not be possible. Therefore, the NetworkLayer class depends on the IPAddress class.

-   `PhysicalLayer and Serializer`:  PhysicalLayer class uses an instance of the Serializer class to write data to a file. Specifically, in the PhysicalLayer class constructor, the Request message is passed to the PhysicalLayer class as a reference and converted to a binary string using the stringToBinary() function. This binary string is then passed to the Serializer class via the serializeFile function to be written to a file. Thus, the PhysicalLayer class is dependent on the Serializer class to handle the serialization of the data. Without the Serializer class, the PhysicalLayer class would not be able to write data to a file.


Main program: The main program takes GET and POST requests through HttpRequest object request and request2 respectively. Then each of the requests is pushed into the Queue and a singleton pattern is used to handle each request at a time. While doing so the object of the previous class is encapsulated to the next object of the class.

Application Layer:

The application layer reads the getRequest and postRequest text and data the application generates. The data is passed down to the transport layer for further processing. This layer is named as HTTPRequest Class and has four private members consisting of maps, vectors, and strings. It has a public constructor which takes two strings as a parameter.

The private member does the following:
-   `map<string, string> Message`: This map stores the key-value pairs of the message. The keys represent the headers, and the values represent the values of the headers. The constructor initializes this map by parsing a file.
-   `vector<string> Headers`: This vector stores the headers of the HTTP request message.
-   `string Method`: This string stores the HTTP method (either "GET" or "POST") used in the request.


The constructor of the Application Layer takes two parameters: Method and fileName. The constructor first sets the Method member to the passed-in Method parameter and then calls the parseMessage function passing the fileName parameter to it. The parseMessage function reads an HTTP request message from the file named fileName and returns a map data structure containing the key-value pairs parsed from the message. The constructor sets the Message member to the returned map data structure

Transport layer:
The transport layer encapsulates the data from the application layer and creates a source port and destination port for the data to transfer and is responsible for breaking down data into smaller packets and ensuring that they are reliably delivered. The two main protocols used at this layer are TCP and UDP. TCP protocol is used for this project as it is more reliable. This layer consists of 2 private data members and 3 private functions. The constructor of this class points to the same memory location of the HTTP request object. The private function generatePort() generates the random port numbers, and the other 2 private functions destPortGenerator() and sourcePortGenerator() use the generatePort() function to receive a randomly generated port that doesn't share the same port number.

The private data member does the following:
-   `Message`: a map that stores the key-value pairs of the message to be transmitted.
-   `SourcePort`: an unsigned 16-bit integer that represents the port number used by the source device for communication.
-   `DestinationPort`: an unsigned 16-bit integer that represents the port number used by the destination device for communication.

The constructor of the TransportLayer generates random port numbers for the source and destination ports, except for some reserved port numbers, and sets the message by using the getMessage() method of the HTTPRequest object passed to it. It then fills in the SourcePort and DestPort fields of the message with the generated port numbers

Network layer:
The Network layer encapsulates the data from the Transport layer and adds an IP header to each packet, which contains information such as the source and destination addresses. This layer is responsible for routing packets across different networks. This layer consists of 3 private data members consisting of a map that stores the key as a "Source IP" or "Destination IP" and value as an IP address and two string variables. This class has a helper IPAddress class that generates a random IP address and stores it in a map with a key-value pair. 

Private Data Members does the following:

-   `Message`: A map that holds the message data of the network layer.
-   `SourceIP`: A string that represents the IP address of the source device.
-   `DestIP`: A string that represents the IP address of the destination device.

The constructor of the Network layer takes a reference to a `TransportLayer` object as input. It sets the source and destination IP addresses and message data of the network layer by calling the corresponding `TransportLayer` functions and then adds the IP address data to the `Message` map.

Data link layer: 
The Data link layer encapsulates the data from the Network layer and uses a MAC to generate the frames that will be transmitted. When transmitting data, this layer adds a header containing the source and destination MAC addresses to the packet received from the Network layer. This layer consists of 3 private data members, a map, two strings, and one private function. The private function randomDataLinkLayer() generates a random Mac Address and stores it in a map as a key-value pair.

The Private Members does the following:

-   `map <string, string> Message`: a map of key-value pairs that stores the data link layer message.
-   `string sourceMAC`: a string that stores the source MAC address.
-   `string destMAC`: a string that stores the destination MAC address.
-   `string randomDataLinkLayer()`: a private function that generates a random MAC address in the form of a string.

The constructor of the DataLinkLayer class takes a NetworkLayer object as an input parameter. It initializes the sourceMAC and destMAC private members with random MAC addresses and sets the Message map with the getMessage() function of the NetworkLayer object. Finally, it adds the sourceMAC and destMAC values to the Message map with the keys "SourceMAC" and "DestMAC", respectively.

Physical layer:
The Physical layer encapsulates the data from the Data link layer and sends and receives signals on the physical wire or antenna to transmit the bits found in frames. It uses a bitset library that changes strings into binary. This consists of 3 private data members and 3 private functions.

The private member does the following:

-  `MapString`: a string variable that stores a map of string key-value pairs.
-  `Message`: a map variable that stores a message as key-value pairs.
-  `Response`: a string variable that stores the serialized message.
-  `stringToBinary(const string& input)`: a private function that takes a string input and returns its binary representation.
-  `binaryToString(const string& binary)`: a private function that takes a binary string input and returns its original string representation.
-  `mapTostring(map<string, string>& myMap)`: a private function that takes a map of string key-value pairs and returns its string representation.

The constructor of the PhysicalLayer class takes a DataLinkLayer object as a reference and initializes the MapString and Response private members. It calls the mapToString and stringToBinary functions to serialize the Request message and set the Response string. It then calls the serializeFile function to write the serialized message to a file.

Helper Class:
IPAddress Class: This class is a helper class for the NetworkLayer class and consist of 2 private data member and 1 member function. 

The private member does the following:

-   `sourceIP` and `destIP` are private string data members which store the source and destination IP addresses.
-   `randomIPAddress()` is a private function that generates a random IP address and returns it as a string.

The constructor of IPAddress Class generates random source and destination IP addresses using the randomIPAddress() function.

Serializer Class: This class is a helper class that serializes the message, both string and binary, and appends it into a file.

The private member does the following:
-   `fileName` is a private member variable that stores the name of the file where the message will be serialized.
-   `Message` is a private member variable that stores the message to be serialized.
-   `serializeFile` is a private function that takes a file name and a message and writes the message to the file. If the file already exists, it appends the message to the end of the file. If the file does not exist, it creates the file and writes the message to it.

The constructor of the Serializer class takes a file name and a message as parameters. It sets the private member variables `fileName` and `Message` using the `setfileName` and `setMessage` functions respectively. It then calls the private `serializeFile` function to serialize the message.

**Contributors**

aryan-ship-it

Willie1416

Asal2
