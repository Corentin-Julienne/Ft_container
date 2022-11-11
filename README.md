# Ft_container_42

Ft_container is a project designed to better understand the functionning of the C++ containers of the STL. The goal is to reproduce at least vector and map in a namespace called ft.

!!! the containers must be congruent with C++98

More information can be found in the PDF.

## useful resources

- those two websites are absolute references about C++ : https://www.cplusplus.com/ and https://cppreference.com/
- the official C++98 norm (ISO format) : https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf 

## utils

### compare.hpp

In this file, we got equal and lexicographical_compare :

- equal compares two ranges of iterators. If the two ranges of iterators contains equal values, returns true, false otherwise.

- lexicographical_compare compares two ranges of iterators. If the first range of iterators is lexicographically less that the second range of tierators, it returns true, false otherwise. Lexicographically less means that its position in alphabetical order is before (i.e. "tree" is lexicographically less than "zulu").

### pair.hpp

In this file, we got the struct pair and the function make_pair

- pair is a struct containing two values (using template, cna be of any type). It is used with map to store a value and the associated key

- make_pair simply creates a pair

### isIntegral.hpp

is_integral is a struct containing only a boolean variable called value. This value is set to true if the template typename is an integral, false otherwise. An integral type is basically an integer. Those integers are : bool, char, .char16_t, char32_t, wchar_t, short, int, long, long long. 

is_integral is implemented using template specialization. If specialization is found, then value is set to true. Otherwise, if no specialization is found, it is set to false.

### enable_if

enable_if is a utility to use boolean conditions to trigger SFINAE (see next paragraph to have a definition of this important concept).

You can check this very good Medium article on this topic : https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe

This Youtube video shows also an enable_if implementation : https://www.youtube.com/watch?v=H-m23Vvzcug&t=19s

Basically, enable_if use template partial specialization. If the template bool B is false, then enable_if struct will be empty. Otherwise, the specialized template struct will have a T type called type inside. When triggering enable_if with false parameter, the compiler will try to find type, which is not present, intentionnaly triggering a SFINAE, preventing a given template specialization to be utilized. 

#### SFINAE

SFINAE (Substitution Failure Is Not An Error) refers to the fact that the compiler will try every template 
possibility (type, including the ones provide by template specialization) in order to find a valid substitution. 
A failure to substitute will not produce a compilation error, but will merely cause the compiler to try another 
template type, until one works. The compilation error will occurs only if no valid template substitution is found

### iteratorTraits.hpp

Iterator Traits in C++98 is a struct used to store the caracteristics of a given iterator. 

It contains several indications constisting of :
- 
-
-
-
-

Contains also specialization for pointers and const pointers

### reverseIterators.hpp

