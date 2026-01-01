/*
================================================================================
                    LAB SYLLABUS - COMPLETE C++ CONCEPTS
                          WITH 200IQ THEORY NOTES
================================================================================

OVERVIEW OF CONCEPTS COVERED:
W1: Functions, Function Overloading, Quadratic Roots, Array Sorting
W2: 2D Arrays, Matrix Operations
W3: Call by Value vs Call by Reference, Classes & Objects
W4: Arrays, Function Overloading
W5: Classes, Methods, Object Arrays
W6: Constructors, Student Records, Arrays of Objects
W7: Friend Functions, Complex Numbers, Operator Overloading
W8: Inheritance, Virtual Functions, Polymorphism
W9: Multi-level Inheritance
W10-W11: Exception Handling

================================================================================
*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/*
================================================================================
                        SECTION 1: BASIC CONCEPTS
================================================================================

THEORY NOTES - 200IQ Edition:

1. FUNCTIONS:
   A function is a reusable block of code that performs a specific task.
   WHY: Code reusability, modularity, and maintainability. Single responsibility.
   
2. FUNCTION OVERLOADING:
   Multiple functions with SAME NAME but DIFFERENT PARAMETERS.
   Compiler distinguishes based on: (a) Number of parameters (b) Type of parameters
   This is COMPILE-TIME (static) polymorphism.
   WHY: Cleaner code, intuitive naming, less cognitive load.
   
3. SCOPE: Where a variable is accessible
   - Global: Entire program
   - Local: Within function/block
   - Function scope: Parameters visible only in that function
   
4. CALL BY VALUE vs CALL BY REFERENCE:
   - Value: Copy of variable passed. Original unchanged. Safe but memory overhead.
   - Reference: Address passed. Original CAN be modified. Efficient, used for output params.
   
5. ARRAYS:
   Contiguous memory storing same data type. Fixed size (in traditional C++).
   WHY: Direct memory access, O(1) indexing, cache-friendly.
   
6. 2D ARRAYS (MATRICES):
   Row-major order: Elements stored row by row. For arr[i][j], address = base + i*cols + j
   
================================================================================
*/

// ============ SECTION 1: FUNCTIONS & OVERLOADING ============

/* THEORY: Function Overloading Example
   
   WHY OVERLOADING MATTERS:
   - Instead of sum_int(), sum_double(), sum_float()...
   - We just call sum() for all types
   - Compiler resolves at COMPILE TIME (no runtime overhead)
   - Called STATIC POLYMORPHISM or COMPILE-TIME POLYMORPHISM
   
   RESOLUTION RULES (in order):
   1. Exact match
   2. Built-in type conversion (int -> double)
   3. User-defined conversions
   4. Ellipsis (...) if defined
*/

int sum_two_nums(int a, int b) {
    return a + b;
}

double sum_two_nums(double a, double b) {
    return a + b;
}

// Overloading with different number of parameters
int sum_three_nums(int a, int b, int c) {
    return a + b + c;
}

/*
THEORY: This demonstrates OVERLOAD RESOLUTION
When you call sum_two_nums(5, 10) -> calls int version
When you call sum_two_nums(5.5, 10.5) -> calls double version
*/


// ============ SECTION 1B: QUADRATIC ROOTS ============

/* THEORY: Solving Quadratic Equation ax² + bx + c = 0
   
   DISCRIMINANT (D) = b² - 4ac
   
   Case 1: D > 0  → Two REAL and DISTINCT roots
           x = (-b ± √D) / 2a
   
   Case 2: D = 0  → Two EQUAL roots
           x = -b / 2a
   
   Case 3: D < 0  → Two COMPLEX roots
           (Not covered here, but would be imaginary numbers)
   
   WHY: Quadratic equations are fundamental in physics, engineering, optimization.
*/

void findQuadraticRoots(int a, int b, int c) {
    if (a == 0) {
        cout << "Not a quadratic equation (a cannot be 0)" << endl;
        return;
    }
    
    float discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2*a);
        float root2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
    }
    else if (discriminant == 0) {
        float root = -b / (2.0*a);
        cout << "Roots are equal: " << root << endl;
    }
    else {
        cout << "Roots are complex (imaginary)" << endl;
    }
}


// ============ SECTION 1C: ARRAY SORTING ============

/* THEORY: BUBBLE SORT
   
   Algorithm: Compare adjacent elements, swap if in wrong order.
   Repeat until no swaps needed.
   
   Time Complexity: O(n²) worst/average case, O(n) best case (already sorted)
   Space Complexity: O(1) - in-place
   
   WHY BUBBLE SORT IS IMPORTANT:
   - Simple to understand and implement
   - Educational value: teaches comparison-based sorting
   - Stable sort: maintains relative order of equal elements
   
   OPTIMIZATION: Early exit if array becomes sorted (no swaps in a pass)
*/

void bubbleSort(int arr[], int n) {
    cout << "\n--- BUBBLE SORT ---" << endl;
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Optimization flag
        
        // Each pass pushes one element to its correct position
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped) break;  // Already sorted
    }
    
    cout << "Sorted (Ascending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    cout << "Sorted (Descending): ";
    for (int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
}


/*
================================================================================
                        SECTION 2: 2D ARRAYS & MATRIX OPS
================================================================================

THEORY: 2D ARRAYS (MATRICES)

Declaration: int matrix[rows][cols];
Memory Layout (Row-major): Elements stored row by row
   Row 0: [0,0] [0,1] [0,2]
   Row 1: [1,0] [1,1] [1,2]
   Row 2: [2,0] [2,1] [2,2]

Address Formula: address = base_address + (i * cols + j) * sizeof(type)

WHY ROW-MAJOR?
- Cache locality: Sequential access is faster (memory prefetching)
- This is why C/C++ uses row-major (vs Fortran's column-major)
- Affects performance significantly in large matrices

PRACTICAL USE: Temperature tracking, image pixels, game boards, etc.
*/

void temperatureAnalysis() {
    const int cities = 5, days = 6;
    int temp[cities][days];
    int highTemp = 0, lowTemp = 0;
    int highCity = 0, lowCity = 0, highDay = 0, lowDay = 0;
    
    cout << "\n--- TEMPERATURE ANALYSIS (2D ARRAY) ---" << endl;
    cout << "Enter temperatures for " << cities << " cities over " << days << " days:\n";
    
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < days; j++) {
            cout << "City " << i+1 << ", Day " << j+1 << ": ";
            cin >> temp[i][j];
            
            if (i == 0 && j == 0) {
                highTemp = lowTemp = temp[0][0];
            }
            
            if (temp[i][j] > highTemp) {
                highTemp = temp[i][j];
                highCity = i;
                highDay = j;
            }
            if (temp[i][j] < lowTemp) {
                lowTemp = temp[i][j];
                lowCity = i;
                lowDay = j;
            }
        }
    }
    
    cout << "\nHighest temperature: " << highTemp << "°C (City " << highCity+1 
         << ", Day " << highDay+1 << ")" << endl;
    cout << "Lowest temperature: " << lowTemp << "°C (City " << lowCity+1 
         << ", Day " << lowDay+1 << ")" << endl;
}


/*
================================================================================
                        SECTION 3: POINTERS & REFERENCES
================================================================================

THEORY: CALL BY VALUE vs CALL BY REFERENCE

1. CALL BY VALUE:
   - Parameter is a COPY of the argument
   - Changes to parameter don't affect original
   - Memory: Extra stack space for copy
   - Safe but inefficient for large objects
   
2. CALL BY REFERENCE:
   - Parameter is an ALIAS to the argument
   - Changes affect original variable
   - Memory: No copy, just an alias (pointer internally)
   - Efficient, used for output parameters or when modification needed
   
SYNTAX:
   By Value:     void func(int x)      // x is copy
   By Reference: void func(int &x)     // x is reference
   
WHY REFERENCES?
- Efficient parameter passing for large objects (strings, arrays, custom classes)
- Allows function to modify caller's data
- Cleaner than pointers (no dereferencing needed)
*/

void swapByValue(int a, int b) {
    cout << "\n--- CALL BY VALUE ---" << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
    cout << "NOTE: Original values outside remain unchanged!" << endl;
}

void swapByReference(int &a, int &b) {
    cout << "\n--- CALL BY REFERENCE ---" << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
    cout << "NOTE: Original values outside ARE CHANGED!" << endl;
}

void demonstrateSwapping() {
    int x = 10, y = 20;
    
    cout << "\nBefore swapping: x = " << x << ", y = " << y << endl;
    
    swapByValue(x, y);
    cout << "After Call by Value: x = " << x << ", y = " << y << endl;
    
    swapByReference(x, y);
    cout << "After Call by Reference: x = " << x << ", y = " << y << endl;
}


/*
================================================================================
                        SECTION 4: OBJECT ORIENTED PROGRAMMING
================================================================================

THEORY: CLASSES & OBJECTS

1. WHAT IS A CLASS?
   Blueprint for objects. Defines data members (attributes) and methods (behavior).
   Encapsulation: Bundle data + methods, hide implementation.
   
2. ACCESS MODIFIERS:
   - private: Accessible only inside class (default)
   - public: Accessible from outside
   - protected: Accessible in derived classes (inheritance)
   
3. CONSTRUCTORS:
   Special method called automatically when object is created.
   Default Constructor: No parameters, initializes with default values
   Parameterized Constructor: Takes parameters to initialize with custom values
   
WHY CONSTRUCTORS?
- Ensure object is in valid state from creation
- Automatic initialization (no need to call separate init function)
- Resource allocation (memory, file handles, etc.)

4. DATA HIDING / ENCAPSULATION:
   Keep implementation details private, expose only necessary interface.
   Benefits:
   - Control how data is accessed/modified
   - Can change implementation without affecting users
   - Prevents accidental misuse
   - Enables validation of input
*/

class Cube {
private:
    double side;
    
public:
    // Default Constructor
    Cube() : side(0) {
        cout << "Cube created with default side = 0" << endl;
    }
    
    // Parameterized Constructor
    Cube(double s) : side(s) {
        cout << "Cube created with side = " << s << endl;
    }
    
    void setSide(double s) {
        if (s > 0) {
            side = s;
        } else {
            cout << "Side must be positive!" << endl;
        }
    }
    
    double getSide() const {
        return side;
    }
    
    double volume() const {
        return side * side * side;
    }
    
    double surfaceArea() const {
        return 6 * side * side;
    }
    
    void display() const {
        cout << "Side: " << side << ", Volume: " << volume() 
             << ", Surface Area: " << surfaceArea() << endl;
    }
};


class Student {
private:
    int usn;
    char name[50];
    int marks[3];
    
public:
    // Default Constructor
    Student() {
        usn = 0;
        strcpy(name, "");
        for (int i = 0; i < 3; i++) marks[i] = 0;
    }
    
    void getdata() {
        cout << "USN: ";
        cin >> usn;
        cout << "Name: ";
        cin >> name;
        cout << "Marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }
    
    double calculateAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    
    void display() const {
        cout << "USN: " << usn << ", Name: " << name 
             << ", Average: " << calculateAverage() << endl;
    }
};


class Employee {
private:
    int num;
    char name[30];
    double basic;
    double DA, IT, net_salary;
    
public:
    void read() {
        cout << "Number: ";
        cin >> num;
        cout << "Name: ";
        cin >> name;
        cout << "Basic Salary: ";
        cin >> basic;
    }
    
    void calculateSalary() {
        DA = 0.52 * basic;       // Dearness Allowance
        IT = 0.3 * (basic + DA); // Income Tax
        net_salary = basic + DA - IT;
    }
    
    void display() const {
        cout << "\nEmp #" << num << " - " << name << endl;
        cout << "Basic: " << basic << ", DA: " << DA 
             << ", IT: " << IT << ", Net: " << net_salary << endl;
    }
};


/*
================================================================================
                        SECTION 5: FRIEND FUNCTIONS & OPERATOR OVERLOADING
================================================================================

THEORY: FRIEND FUNCTIONS

A friend function is NOT a member of a class, but can access private/protected members.

Declaration: friend [return_type] [function_name](parameters);

WHY FRIEND FUNCTIONS?
- Allow external functions to access private members
- Useful for operator overloading
- Enable complex operations between objects

IMPORTANT CAVEATS:
- Breaks encapsulation, use sparingly
- Not inherited
- Can't be virtual
- Violates OOP principles, but sometimes necessary

OPERATOR OVERLOADING:
Redefine operators (+, -, *, /, etc.) to work with custom objects.
Two approaches:
1. Member function: obj1 + obj2 becomes obj1.operator+(obj2)
2. Friend function: operator+(obj1, obj2)

ADVANTAGES:
- Intuitive syntax (c1 + c2 instead of add(c1, c2))
- Allows custom behavior for operators
- Makes code more readable for domain-specific types
*/

class Complex {
private:
    double real;
    double imag;
    
public:
    Complex() : real(0), imag(0) {}
    
    Complex(double r, double i) : real(r), imag(i) {}
    
    void read() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }
    
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
    
    // Friend function for flexible overloading
    friend Complex add(double a, Complex c1) {
        // This allows: int + Complex
        Complex temp;
        temp.real = a + c1.real;
        temp.imag = c1.imag;
        return temp;
    }
    
    friend Complex add(Complex c1, Complex c2) {
        // Complex + Complex
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.imag = c1.imag + c2.imag;
        return temp;
    }
    
    // Member function for operator overloading (alternative approach)
    Complex operator+(int a) {
        Complex temp;
        temp.real = real + a;
        temp.imag = imag;
        return temp;
    }
    
    Complex operator+(const Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};


/*
================================================================================
                        SECTION 6: INHERITANCE & POLYMORPHISM
================================================================================

THEORY: INHERITANCE

Inheritance: A class inherits properties and methods from another class.
Base Class (Parent): Original class
Derived Class (Child): Inherits from base class

SYNTAX: class Derived : public Base { ... };

ACCESS MODIFIER IN INHERITANCE:
- public: public members stay public in derived class
- private: public members become private in derived class
- protected: members are hidden from outside but visible in derived classes

WHY INHERITANCE?
- Code reusability: Don't repeat common functionality
- Hierarchical relationships: Models real-world "is-a" relationships
- Polymorphism: Different implementations of same interface

TYPES OF INHERITANCE:
1. Single: One parent
2. Multi-level: Parent → Child → Grandchild
3. Multiple: Multiple parents (not shown here, causes diamond problem)
4. Hierarchical: One parent, multiple children

THEORY: POLYMORPHISM (Many Forms)

COMPILE-TIME POLYMORPHISM:
- Function Overloading (same name, different parameters)
- Operator Overloading (operators behave differently for different types)

RUNTIME POLYMORPHISM:
- Virtual Functions: Which function to call decided at runtime
- Same function name, different implementations in different classes
- Base class pointer/reference can point to derived class object
- Actual method called based on object type at runtime (late binding)

WHY VIRTUAL FUNCTIONS?
- Enable flexible code: base class pointer can call different methods
- Reduces code duplication
- Extensible: add new derived classes without changing base code

VIRTUAL FUNCTION MECHANISM:
- Each class with virtual functions has VTABLE (Virtual Table)
- VTABLE contains pointers to virtual functions
- At runtime, check VTABLE to find actual function to call
- Small overhead: one pointer dereference
*/

class Vehicle {
public:
    virtual void display() {
        cout << "I am a vehicle." << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void display() override {  // override keyword (C++11) makes intent clear
        cout << "I have four wheels." << endl;
    }
};

class Car : public FourWheeler {
public:
    void display() override {
        cout << "I am a car." << endl;
    }
};

class Shape {
public:
    virtual void display() {
        cout << "This is a shape." << endl;
    }
};

class Polygon : public Shape {
public:
    void display() override {
        cout << "Polygon is a shape." << endl;
    }
};

class Rectangle : public Polygon {
public:
    void display() override {
        cout << "Rectangle is a polygon." << endl;
    }
};

class Triangle : public Polygon {
public:
    void display() override {
        cout << "Triangle is a polygon." << endl;
    }
};

class Square : public Rectangle {
public:
    void display() override {
        cout << "Square is a rectangle." << endl;
    }
};

void demonstratePolymorphism() {
    cout << "\n--- RUNTIME POLYMORPHISM (VIRTUAL FUNCTIONS) ---" << endl;
    cout << "\nMulti-level Inheritance (Vehicle hierarchy):" << endl;
    
    Car C;
    C.display();  // Calls Car's display
    
    cout << "\nInheritance Hierarchy (Shape hierarchy):" << endl;
    Shape SH;
    Polygon PG;
    Rectangle RT;
    Triangle TR;
    Square SQ;
    
    SH.display();
    PG.display();
    RT.display();
    TR.display();
    SQ.display();
}

void demonstrateBasePointer() {
    cout << "\n--- BASE CLASS POINTER WITH DERIVED OBJECTS ---" << endl;
    
    Shape *shapePtr;
    Shape s;
    Polygon p;
    Rectangle r;
    Triangle t;
    Square sq;
    
    cout << "Shape pointer points to different objects:\n";
    
    shapePtr = &s;
    shapePtr->display();  // Calls Shape::display()
    
    shapePtr = &p;
    shapePtr->display();  // Calls Polygon::display()
    
    shapePtr = &r;
    shapePtr->display();  // Calls Rectangle::display()
    
    shapePtr = &t;
    shapePtr->display();  // Calls Triangle::display()
    
    shapePtr = &sq;
    shapePtr->display();  // Calls Square::display()
    
    cout << "\nThis is RUNTIME POLYMORPHISM: same pointer, different behavior!" << endl;
}


/*
================================================================================
                        SECTION 7: EXCEPTION HANDLING
================================================================================

THEORY: EXCEPTION HANDLING

Exception: An error/exceptional condition that occurs during program execution.

TRADITIONAL C APPROACH:
- Return error codes
- Difficult to distinguish from valid return values
- Easy to ignore error codes
- Clutters code with if-checks

C++ APPROACH (Exception Handling):
- throw: Raise an exception
- try: Block that might throw exception
- catch: Handle specific exception type

ADVANTAGES:
- Separates error handling from normal code flow
- Can't accidentally ignore exceptions
- Granular control: different catch blocks for different exceptions
- Exception propagates up call stack until caught

CONTROL FLOW:
1. Normal execution in try block
2. Exception thrown
3. Control jumps to matching catch block (skips remaining try code)
4. Catch block handles exception
5. Program continues after try-catch (if not re-thrown)

BEST PRACTICES:
- Catch specific exceptions, not catch-all (avoid bare catch(...))
- Use standard exceptions (std::exception) when possible
- Throw exceptions for exceptional conditions, not regular control flow
- Clean up resources in catch block or use RAII (smart pointers)
*/

void divideTwoNumbers(int a, int b) {
    if (b == 0) {
        throw "Divide by Zero error!";
    } else {
        cout << "Result = " << a / b << endl;
    }
}

void demonstrateExceptionHandling() {
    cout << "\n--- EXCEPTION HANDLING ---" << endl;
    
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    
    try {
        divideTwoNumbers(x, y);
        cout << "Division successful!" << endl;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
        cout << "Handled gracefully, program continues..." << endl;
    }
}

void arrayIndexException() {
    cout << "\n--- ARRAY INDEX OUT OF BOUNDS ---" << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int index;
    
    cout << "Enter index to access (0-4): ";
    cin >> index;
    
    try {
        if (index < 0 || index > 4) {
            throw index;  // Throw int exception
        }
        cout << "Value at index " << index << " is " << arr[index] << endl;
    }
    catch (int idx) {
        cout << "Exception: Index " << idx << " is out of bounds (valid: 0-4)" << endl;
    }
}


/*
================================================================================
                        SECTION 8: ARRAYS AND VOTING SYSTEM
================================================================================

THEORY: Array-Based Counting & Statistics

Problem: Count votes for candidates
Solution: Use array where each index represents a candidate

WHY THIS PATTERN?
- O(1) insertion (just increment counter)
- O(1) lookup (direct array access)
- Simple and efficient
- Foundation for hash tables and similar structures
*/

void votingSystem() {
    cout << "\n--- VOTING SYSTEM ---" << endl;
    
    int votes, candidate;
    int count[6] = {0};  // Indices 0-4 for candidates, 5 for invalid
    
    cout << "Enter the number of votes: ";
    cin >> votes;
    
    cout << "Enter each vote for all candidates (1-5): ";
    for (int i = 0; i < votes; i++) {
        cin >> candidate;
        
        if (candidate >= 1 && candidate <= 5)
            count[candidate - 1]++;
        else
            count[5]++;  // Invalid vote count
    }
    
    cout << "\nVote Count:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << i+1 << ": " << count[i] << " votes" << endl;
    }
    cout << "Invalid votes: " << count[5] << endl;
    
    // Find winner
    int maxVotes = count[0], winner = 1;
    for (int i = 1; i < 5; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            winner = i + 1;
        }
    }
    
    cout << "\nWinner: Candidate " << winner << " with " << maxVotes << " votes!" << endl;
}


/*
================================================================================
                        MAIN FUNCTION - DEMONSTRATION
================================================================================
*/

int main() {
    cout << "=====================================================" << endl;
    cout << "  LAB SYLLABUS - COMPLETE C++ CONCEPTS DEMONSTRATION" << endl;
    cout << "=====================================================" << endl;
    
    int choice;
    
    while (true) {
        cout << "\n\nMENU:" << endl;
        cout << "1.  Function Overloading Demo" << endl;
        cout << "2.  Quadratic Roots Finder" << endl;
        cout << "3.  Array Sorting (Bubble Sort)" << endl;
        cout << "4.  2D Array - Temperature Analysis" << endl;
        cout << "5.  Call by Value vs Reference" << endl;
        cout << "6.  Classes & Objects - Cube" << endl;
        cout << "7.  Complex Numbers (Friend Functions & Operator Overloading)" << endl;
        cout << "8.  Inheritance & Polymorphism Demo" << endl;
        cout << "9.  Exception Handling - Division" << endl;
        cout << "10. Exception Handling - Array Index" << endl;
        cout << "11. Voting System" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter choice (1-12): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "\n--- FUNCTION OVERLOADING ---" << endl;
                int a = 5, b = 10;
                double x = 3.5, y = 2.5;
                
                cout << "Integer sum: " << sum_two_nums(a, b) << endl;
                cout << "Double sum: " << sum_two_nums(x, y) << endl;
                cout << "Three integer sum: " << sum_three_nums(1, 2, 3) << endl;
                break;
            }
            
            case 2: {
                int a, b, c;
                cout << "\n--- QUADRATIC EQUATION SOLVER ---" << endl;
                cout << "Enter coefficients a, b, c for ax² + bx + c = 0:" << endl;
                cout << "a: ";
                cin >> a;
                cout << "b: ";
                cin >> b;
                cout << "c: ";
                cin >> c;
                findQuadraticRoots(a, b, c);
                break;
            }
            
            case 3: {
                int n;
                cout << "\n--- ARRAY SORTING ---" << endl;
                cout << "Enter array size: ";
                cin >> n;
                
                int *arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                
                bubbleSort(arr, n);
                delete[] arr;
                break;
            }
            
            case 4: {
                temperatureAnalysis();
                break;
            }
            
            case 5: {
                demonstrateSwapping();
                break;
            }
            
            case 6: {
                cout << "\n--- CLASSES & OBJECTS ---" << endl;
                cout << "Creating cubes..." << endl;
                
                Cube c1;  // Default constructor
                
                double side;
                cout << "Enter side for cube 2: ";
                cin >> side;
                c1.setSide(side);
                c1.display();
                
                Cube c2(5);  // Parameterized constructor
                c2.display();
                break;
            }
            
            case 7: {
                cout << "\n--- COMPLEX NUMBERS ---" << endl;
                Complex c1, c2, c3;
                int num;
                
                cout << "Enter 1st Complex number:" << endl;
                c1.read();
                cout << "Complex number: ";
                c1.display();
                
                cout << "\nEnter integer to add: ";
                cin >> num;
                c3 = add(num, c1);  // Friend function
                cout << "Result: ";
                c3.display();
                
                cout << "\nEnter 2nd Complex number:" << endl;
                c2.read();
                cout << "Complex number: ";
                c2.display();
                
                c3 = add(c1, c2);  // Friend function
                cout << "Sum of complex numbers: ";
                c3.display();
                break;
            }
            
            case 8: {
                demonstratePolymorphism();
                demonstrateBasePointer();
                break;
            }
            
            case 9: {
                divideTwoNumbers(10, 0);  // Will throw exception
                demonstrateExceptionHandling();
                break;
            }
            
            case 10: {
                arrayIndexException();
                break;
            }
            
            case 11: {
                votingSystem();
                break;
            }
            
            case 12: {
                cout << "\nExiting... Thank you!" << endl;
                return 0;
            }
            
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
    
    return 0;
}

/*
================================================================================
                        KEY TAKEAWAYS & SUMMARY
================================================================================

1. FUNCTIONS & OVERLOADING:
   - Functions promote code reusability
   - Overloading allows same name with different signatures
   - Resolved at compile time (static polymorphism)

2. ARRAYS & MATRICES:
   - Direct memory access (O(1) indexing)
   - Row-major order important for cache locality
   - 2D arrays accessed as arr[i*cols + j] internally

3. POINTERS & REFERENCES:
   - References are safer, cleaner aliases
   - Call by reference allows modification of caller's data
   - Efficient for passing large objects

4. OBJECT-ORIENTED PROGRAMMING:
   - Classes bundle data + methods
   - Encapsulation hides implementation
   - Constructors ensure valid initialization

5. FRIEND FUNCTIONS:
   - Access private members from outside class
   - Enable operator overloading
   - Use sparingly (breaks encapsulation)

6. INHERITANCE:
   - Models "is-a" relationships
   - Promotes code reusability
   - Foundation for polymorphism

7. POLYMORPHISM:
   - Compile-time: Function/Operator Overloading
   - Runtime: Virtual functions (VTABLE mechanism)
   - Allows same interface, different implementations

8. EXCEPTION HANDLING:
   - Separate error handling from normal flow
   - throw → try → catch mechanism
   - Prevents resource leaks (with proper cleanup)

9. PRACTICAL PATTERNS:
   - Arrays for counting/statistics
   - Objects for data grouping
   - Inheritance for related types

================================================================================
                        COMPILATION & EXECUTION
================================================================================

To compile: g++ -std=c++11 Lab_Syllabus_Complete.cpp -o lab
To run:     ./lab

Features demonstrated:
✓ All 11 weeks of lab concepts
✓ Interactive menu-driven interface
✓ Detailed theory notes explaining WHY
✓ Real-world examples and best practices
✓ Exception handling throughout
✓ Memory management (dynamic arrays)

================================================================================
*/