# Quick and dirty O(n) automaton based string matcher
## compile
```
make
```

## run/test
```
make test  
./testMatcher
```  

Expected Input:  
`+` for adding to dictionary  
`-` for removing from dictionary  
`?` for matching  

## time/space complexity
adding a word, removing a word and matching take O(len) where len is the length of the word  
transition to the next symbol is based on char width and thereby uses 255*sizeof(void*)  
in general the upper bound for space is the sum of all dictionary words
