Algorithm list
==============

1. 3 Sum

   Given an array of N integers, find pairs of three elements with the sum of X.

2. Merge 2 sorted linked lists

3. Given a paragraph and a list of words, find the word that occurs the most
   times in the paragraph and is not in the list of words

4. Implement Min Stack (push, pop, top, and min)

5. Reorder logs

   You have an array of logs. Each log is a space-delimited string of words. For each log, the first word in each log is an alphanumeric identifier.

   Then, either:

   * Each word after the identifier will consist only of lowercase letters, or;
   * Each word after the identifier will consist only of digits.

   We will call these two varieties of logs letter-logs and digit-logs.
   It is guaranteed that each log has at least one word after its identifier.

   Reorder the logs so that all of the letter-logs come before any digit-log.

   * The letter-logs are ordered lexicographically ignoring identifiers, with the identifier used in case of ties.
   * The digit-logs should be put in their original order.

6. Kth largest element in a stream in linear time.

7. Spiral matrix

   Given an N generate a square matrix with value 1..n²

   ::

     N=4
     1   2  3 4
     12 13 14 5
     11 16 15 6
     10  9  8 7

8. Roman Numbers to Integer and Vice Versa

9. Maximum sum sub array

   Given an array on N integers find the span with the greatest sum and return this sum.

10. Prison cell after N days

    There are eight(8) cells in a row and each is either occupied(true) or empty(false).
    If a cell has two empty or occupied neighbors it becomes occupied.
    Otherwise it becomes empty.
    First and last cell don't have two neighbors.
    
11. Deep copy a linked list with an extra random pointer

12. Number of islands

    Given an map of land(1) and water(0) count all the islands. Any two pieces of land form an
    island vertically or horizontally.

13. Merge intervals

    Given a set of intervals, merge them if possible.

14. K closest points to origin

    Given a list of coordinates(x,y) find the closest from (0,0) using euclidean
    distance.

15. Unique paths

    Given a 2d matrix count how many paths exist from start(0,0) to end(n,n) if
    there are obstacles in the way.

16. Minimum cost to connect all ropes

    Two ropes can be connected and the cost to connect them is the sum of their lengths.
    Given an array of ropes of different lengths what is the minimum cost to connect all?

    
17. Generate parantheses

    N pairs of parantheses, generate all valid combinations

18. Autosuggestions

    given a list of strings and a searchword we want to suggest at most
    three strings based on the searched word from the list. the suggested
    words must have a common prefix with the searched. if there are more
    than three available return the minimums.

19. Find min in rotated sorted array

    given a sorted array and considering that at some pivot it has been rotated
    find the minimum

20. Coin change

    Fewest number of coins to make up a particular amount

21. Word break

    Given a word S and a dictionary containing non-empty words determine if
    S can be segmented in one or more dictionary words.

22. Subtree of another tree

    Given two non-empty binary trees check if the first is an identical
    subtree of the second.

23. Longest palindrome substring

24. Queue using stacks

    Implement a queue using stacks.

25. Group anagrams

    Given a list of strings group anagrams together.

26. Longest path in a binary tree

    Given a binary tree find the longest path from root to leaf. If more than one exist return the leftmost.

27. Is a number duodecimal

    Given any number asses if it has more than two different decimals.

28. Find next greater item

    Given an array of N elements output the next greater element to the right
    of the current one.

29. Reverse a linked list in k-sized slots

30. Nodes from leaf

    Print all unique nodes at K-distance from leaves.

31. Adding big numbers

    Sum two strings representing positive integrals that can be very large.

32. Sum of intervals

    Given an array of intervals [) compute the sum of all interval lengths.
    Overlapping intervals must be counted once.

33. Snakes and Ladders

    You have a board from 0,100 filled with ladders and snakes.

    Two players starting at 0. Every player throws two dice and moves forward.

    If both dice are identical you roll again.

    If you land on a ladder you advance to its end even on double roll.

    If you land on a snake you go back to its tail even on double roll.

    To reach the end you need to roll exactly to land on 100, otherwise you bounce back.
    (e.g. player on 97 rolls 5, reached 100, goes back to 98: 100-((97+5) % 100).

    Return:

    * 'Player <n> Wins!'
    * 'Game over!' when a players wants to roll but a player has already won.
    * 'Player <n> is on square <x>.' otherwise.

34. Infix to postfix converter

    | to_postfix("2+7*5")					// "275*+"
    | to_postfix("3*3/(7+1)")				// "33*71+/"
    | to_postfix("5+(6-2)*9+3^(7-1)")		// "562-9*+371-^+"
    | to_postfix("1^2^3")					// "123^^"
    | to_postfix("3*3/(7+1*(5+5/(9-4))-2)") // "33*715594-/+*+2-/"

35. Shortest knight path

    Given two positions on a chess board find least no of valid knight
    moves from start to destination.
