# Minimum-Cost-Trip
Input a list of cities, roads, and flights find the minimum cost trip between two cities

#Input
The input consists of a single test case. The first line lists five space-separated integers n, m, f, s, and t, denoting the number of cities n, the number of roads m, the number of flights f, the number s of the city in which your trip starts, and the number t of the city you are trying to travel to. (Cities are numbered from 0 to n-1)

The first line is followed by m lines, each describing one road. A road description contains three space-separated integers i, j, and c indicating there is a road connecting cities i and j that costs c cents to travel. Roads can be used in either direction for the same cost. All road descriptions are unique.

Each of the following f lines contains a description of an available flight, which consists of two space-separated integers u and v denoting that a flight from city u to city v is available (though not from v to u unless listed elsewhere). 

#Output

The minimum number of cents you need to spend to get from one city to another, using at most one flight.

#Sample Input

8 11 1 0 5
0 1 10
0 2 10
1 2 10
2 6 40
6 7 10
5 6 10
3 5 15
3 6 40
3 4 20
1 4 20
1 3 20
4 7

#Sample Output and Explanation

45

There 8 cities, 11 roads and 1 flight. You want to go from city 0 to city 5. We take the road from city 0 to city 1 which costs 10 cents. We then take the road from city 1 to city 3 which costs 20 cents. And finally take the road from city 3 to city 5 which costs 15 cents, giving a total of 45 cents. We did not use the flight from city 4 to city 7.

#Sample Input 2

8 11 1 0 5
0 1 10
0 2 10
1 2 10
2 6 40
6 7 10
5 6 10
3 5 15
3 6 40
3 4 20
1 4 20
1 3 30
4 7

#Sample Output 2 and Explanation 

50

There 8 cities, 11 roads and 1 flight. You want to go from city 0 to city 5. We take the road from city 0 to city 1 which costs 10 cents. We then take the road from city 1 to city 4 which costs 20 cents. We then take the flight from city 4 to city 7 which is free. We then take the road from city 6 to city 7 which costs 10 cents. And finally take the road from city 6 to city 5 which costs 10 cents, giving a total of (10 + 20 +10 + 10) 50 cents. 
