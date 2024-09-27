i: 0 1 0 2 1 0 1 3 2 1 2 1
j: 4 2 0 3 2 5

rain: {
 lm: maxs x;                    / acum max from left side
 rm: reverse maxs reverse x;    / acum max from right side
 sum (lm & rm) - x              / get min of both
 }


rain i
rain j
