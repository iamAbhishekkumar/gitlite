# Notes

## New Concepts :

1. Fold Expresssion
2. Variadic Templates

## Imp Points

### Refernce & Default Constructor

* If all your private data members are references, you cannot have a default constructor (unless you initialize the references somehow).
* A parameterized constructor must initialize those reference members using an initializer list.
* You only need to define a default constructor if you have a specific use case where you want objects of the class to be constructed without arguments.
