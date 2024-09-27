i: 1 1 0 1 1 1
j: 1 0 1 1 0 1

mco: {
 g: _[;x] where not (=) prior x; / group consecutive equals
 max sum each g                  / count 1 in each group and return max
 }
