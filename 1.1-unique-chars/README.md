# Question

p. 73: Implement an algorithm to determine if a string has all unique
characters. What if you cannot use additional data structures?

# Implementation Notes

Characters are assumed to be ASCII. If they are unicode, this would probably
behave unexpectedly, as multi-byte characters would be split and read as
multiple characters. Honestly, I'm not even sure how to get a single unicode
character with C++.

## `allCharsUniqueSet`:

This is probably the implementation I would use in an actual
project. Replacing `std::set` (backed by a binary search tree) with
`std::unordered_set` (backed by a hashmap) would result in better average-case,
but worse worst-case complexity

**Time complexity**: `O(n log(n))` (O(n) from for loop and O(log(n)) from set
insertion)

**Space complexity**: `O(k)` additional space, where k is the number of
possible characters.

## `allCharsUniqueDoubleFor`:

Probably never actually useful, written because the book challenged me to solve
this without extra data structures.

**Time complexity**: `O(n^2)`

**Space complexity**: `O(1)` additional space - just the storage needed for two
`size_t` objects for indexing.

## `allCharsUniqueSimpleHashMap`:

Disappointingly slow. This is an implementation that demonstrates the benefit
of more complicated data structures. At first glance this seems like the best
solution, because the complexity says linear time complexity and constant space
complexity, but in practice this will likely be slower than
`allCharsuniqueSet`. Due to the fact that we have to initialize every entry of
our basic hash map, this solution will be slower. Additionally, space is only
constant because we are allocating enough space for all possible characters,
which is inefficient.

**Time complexity**: `O(n)`

**Space complexity**: `O(1)` additional space - needs exactly 256 bytes of
extra space.
