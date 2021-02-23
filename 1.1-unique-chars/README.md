# Question

p. 73: Implement an algorithm to determine if a string has all unique
characters. What if you cannot use additional data structures?

# Implementation Notes

## `allCharsUniqueSet`:

This is probably the implementation I would use in an actual
project.

**Time complexity**: `O(n log(n))` (O(n) from for loop and O(log(n)) from set
insertion)

**Space complexity**: `O(n)` additional space

## `allCharsUniqueDoubleFor`:

Probably never actually useful, written because the book challenged me to solve
this without extra data structures.

**Time complexity**: `O(n^2)`

**Space complexity**: `O(1)` additional space - just the storage needed for two
`size_t` objects for indexing.
