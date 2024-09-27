i: 2 2 2 1 1 2 2
j: 1 2 1 2 1 2
k: 2 2 1 1 1 2 2 2 2

ge: { // group equals
 _[;x] where not (=) prior x
 }

sushi: {
 c: count each ge x; / count elements in equal groups
 2*max 1_ (&) prior c  
 }
