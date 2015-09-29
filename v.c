#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Guess key length
getKeyLen(char *encrypt) {
  int x, y;
  //int spacing[];
  char *substr, *match;
  // x=length of pattern
  for (x=10; x>3; x--) {
    // Grab space for a string of x characters (plus NULL term)
    substr = malloc(x+1);
    // Add NULL terminator
    substr[x] = '\0';
    // Iterate through x-char substrings of 'encrypt'
    // y=starting point
    for (y=0; y<strlen(encrypt)-2*x; y++) { //Might want <= here
      // Copy 'x' characters from 'encrypt[y]' to 'substr'
      // ie: Record an x-char pattern
      memcpy(substr, &encrypt[y], x);
      //printf("Searching for %s in %s\n", substr, &encrypt[y+x]);
      // Search for 'substr' in 'encrypt[y+x]'
      if (match = strstr(&encrypt[y+x], substr)) {
        printf("Found %d-char pattern '%s' repeated at interval %d\n", x, substr, (int)(match-(encrypt+y)) );
        // Record interval & pattern length in a linked-list struct
        
      }
    } //End y loop
    free(substr);
  } //End x loop

  // Evaluate struct, discard small matches within larger matches
  // Figure out which intervals seem legit, somehow?
  // Calculate GCF of all "legit" intervals

  return 10;
}


main() {
  int keylen;

  // Hard-coded constant.
  // In the future, read this from file.
  char *encrypt="FVHQZPSOGSQQNICBSUJZDAVEFFCPEEUQYICUTLGLFWRRZRGDJPFMDRONCXROQROMGQBHWDBFRTPDHLIDUHWEVQGDWTZDXXLZSWAZDYRJEUAHHLGHRQLFODROMTRVXGZDXSQJHVTRWHVNMBDPDAPHYDQRLREQFDGEUJHPJFCHBLYWQIDQJHVLXDUSAQFWMPECIEDKGWIXUBFEDQHKIGQFLJTOOWMZZCIEAMFWMNGZDVCQOOXTYSVCDFSPJLUZVASUQKLLBDHRDYCUIZRHHRETOQRZFOGMLSBRWEUQWVLOSLWLGHRQLFWFEWXMUIAAFWIOUBRVOQFWSQMQLPTFOWIOQPXKRUBJMEUGSSDEWEPPFCLRDFFXGEFVHZPDWIMPDHRSAFWPMDQHKEEUGWVJFCUIOGQHXSQJHVTRWFEEUCQXTYSZLPZGHZPDOOTCADHVEUSVSQMGBWEQADVPQLDQTZSGMYESTYPZQHEDUALPLDCSXTABISCEDDGPADWMXUGDXTABDPDASAMDFGA";

  printf("Source string:\n%s\n", encrypt);

  keylen = getKeyLen(encrypt);

  printf("Key length: %d\n", keylen);
}

