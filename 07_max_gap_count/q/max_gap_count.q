i: 2 5 8 1
j: enlist 3

mgc: {
 if[2 > count x; :0];
 t: count each group 1_ deltas asc x;
 t[max key t]
 }

mgc i / 2, Since the sorted list (1,2,5,8) has 2 such pairs (2,5) and (5,8)
mgc j / 0
