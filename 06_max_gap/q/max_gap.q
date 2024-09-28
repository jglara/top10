i: 3 6 9 1
j: 10


/ Sol 1. no linear time
mg: {
 $[2 > count x; 0;
  max 1 _ deltas asc x]
 }


mg i / 3
mg j / 0
