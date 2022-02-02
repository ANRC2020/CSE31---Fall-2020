#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
//void printPuzzle(char** arr, int n);
//void searchPuzzle(char** arr, int n, char** list, int listSize);

void printPuzzle(char** arr, int n) {
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c ", *(*(arr + i) + j) ); 
		}
		printf("\n");
	}	

}

int getlength(char** list, int wordnum, int l) {
	while( (*(*(list + wordnum) + l) >= 65 && *(*(list + wordnum) + l) <= 90) || (*(*(list + wordnum) + l) >= 97 && *(*(list + wordnum) + l) <= 122) ) {
		l++;
	}
	return l;
}

int across(char** arr, int n, char** list, int row, int column, int wordnum) {
	int l = 0;
	int length = getlength(list, wordnum, l);
	int matched = 1;
	int c = column;
	
	for(int i = 0; i < length; i++) {
		if(c <= n) {
			if(*(*(list + wordnum) + i) == *(*(arr + row) + c) - 32 || *(*(list + wordnum) + i) == *(*(arr + row) + c) || *(*(list + wordnum) + i) == *(*(arr + row) + c) + 32) {
				c++;
			} else {
				matched = 0;
				break;
			}
		} else {
			matched = 0;
			break;
		}
	};
	if(matched == 0) {
		return 0;
	}
	c = column;
	for(int i = 0; i < length; i++) {
		if((*(*(arr + row) + c) >= 65 && *(*(arr + row) + c) <= 90)) {
			*(*(arr + row) + c) += 32;
		}
		c++;
	}
	printf("Word found: ");
	for(int i = 0; i < length; i++) {
		printf("%c", *(*(list + wordnum) + i));
	}
	printf("\n");
	return 1;
}

int up(char** arr, int n, char** list, int row, int column, int wordnum) {
	int l = 0;
	int length = getlength(list, wordnum, l);
	int matched = 1;
	int r = row;
	
	for(int i = 0; i < length; i++) {
		if(r >= 0) {
			if(*(*(list + wordnum) + i) == *(*(arr + r) + column) - 32 || *(*(list + wordnum) + i) == *(*(arr + r) + column) || *(*(list + wordnum) + i) == *(*(arr + r) + column) + 32) {
				r--;
			} else {
				matched = 0;
				break;
			}
		} else {
			matched = 0;
			break;
		}
	};
	if(matched == 0) {
		return 0;
	}
	r = row;
	for(int i = 0; i < length; i++) {
		if((*(*(arr + r) + column) >= 65 && *(*(arr + r) + column) <= 90)) {
			*(*(arr + r) + column) += 32;
		}
		r--;
	}
	printf("Word found: ");
	for(int i = 0; i < length; i++) {
		printf("%c", *(*(list + wordnum) + i));
	}
	printf("\n");
	return 1;
}

int down(char** arr, int n, char** list, int row, int column, int wordnum) {
	int l = 0;
	int length = getlength(list, wordnum, l);
	int matched = 1;
	int r = row;
	
	for(int i = 0; i < length; i++) {
		if(r >= 0) {
			if(*(*(list + wordnum) + i) == *(*(arr + r) + column) - 32 || *(*(list + wordnum) + i) == *(*(arr + r) + column) || *(*(list + wordnum) + i) == *(*(arr + r) + column) + 32) {
				r++;
			} else {
				matched = 0;
				break;
			}
		} else {
			matched = 0;
			break;
		}
	};
	if(matched == 0) {
		return 0;
	}
	r = row;
	for(int i = 0; i < length; i++) {
		if((*(*(arr + r) + column) >= 65 && *(*(arr + r) + column) <= 90)) {
			*(*(arr + r) + column) += 32;
		}
		r++;
	}
	printf("Word found: ");
	for(int i = 0; i < length; i++) {
		printf("%c", *(*(list + wordnum) + i));
	}
	printf("\n");
	return 1;
}

int updiag(char** arr, int n, char** list, int row, int column, int wordnum) {
	int l = 0;
	int length = getlength(list, wordnum, l);
	int matched = 1;
	int r = row;
	int c = column;
	
	for(int i = 0; i < length; i++) {
		if(r >= 0 && c < n) {
			if(*(*(list + wordnum) + i) == *(*(arr + r) + c) - 32 || *(*(list + wordnum) + i) == *(*(arr + r) + c) || *(*(list + wordnum) + i) == *(*(arr + r) + c) + 32) {
				r--;
				c++;
			} else {
				matched = 0;
				break;
			}
		} else {
			matched = 0;
			break;
		}
	};
	if(matched == 0) {
		return 0;
	}
	r = row;
	c = column;
	for(int i = 0; i < length; i++) {
		if((*(*(arr + r) + c) >= 65 && *(*(arr + r) + c) <= 90)) {
			*(*(arr + r) + c) += 32;
		}
		r--;
		c++;
	}
	printf("Word found: ");
	for(int i = 0; i < length; i++) {
		printf("%c", *(*(list + wordnum) + i));
	}
	printf("\n");
	return 1;
}

int downdiag(char** arr, int n, char** list, int row, int column, int wordnum) {
	int l = 0;
	int length = getlength(list, wordnum, l);
	int matched = 1;
	int r = row;
	int c = column;
	
	for(int i = 0; i < length; i++) {
		if(r < n && c < n) {
			if(*(*(list + wordnum) + i) == *(*(arr + r) + c) -32 || *(*(list + wordnum) + i) == *(*(arr + r) + c) || *(*(list + wordnum) + i) == *(*(arr + r) + c) + 32) {
				r++;
				c++;
			} else {
				matched = 0;
				break;
			}
		} else {
			matched = 0;
			break;
		}
	};
	if(matched == 0) {
		return 0;
	}
	r = row;
	c = column;
	for(int i = 0; i < length; i++) {
		if((*(*(arr + r) + c) >= 65 && *(*(arr + r) + c) <= 90)) {
			*(*(arr + r) + c) += 32;
		}
		r++;
		c++;
	}
	
	printf("Word found: ");
	for(int i = 0; i < length; i++) {
		printf("%c", *(*(list + wordnum) + i));
	}
	printf("\n");
	return 1;
}

void searchPuzzle(char** arr, int n, char** list, int listSize) {
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	for(int wordnum = 0; wordnum < listSize; wordnum++) {
		int result = 0;
		/*
		int l = 0;
		int length = getlength(list, wordnum, l);
		printf("Looking for: ");
		for(int i = 0; i < length; i++) {
			printf("%c", *(*(list + wordnum) + i));
		}
		printf("\n");
		*/
		for(int row = 0; row < n; row++) {
			for(int column = 0; column < n; column++) {
				if(result == 1) {
					break;
				}
				int firstletter = *(*(list + wordnum) + 0);
				int secondletter = *(*(list + wordnum) + 1);
				
				if(*(*(arr + row) + column) == firstletter || *(*(arr + row) + column) == firstletter + 32) {
					//Across
					if(column + 1 < n) {
						if( *(*(arr + row) + column + 1) == secondletter || *(*(arr + row) + column + 1) + 32 == secondletter ) {
							result = across(arr, n, list, row, column, wordnum);
							if(result == 1) {
								continue;
							}
						}
					}
					//Up
					if(row - 1 >= 0) {
						if(*(*(arr + row - 1) + column) == secondletter || *(*(arr + row - 1) + column) + 32 == secondletter) {
							result = up(arr, n, list, row, column, wordnum);
							if(result == 1) {
								continue;
							}
						}
					}
					//Down
					if(row + 1 < n) {
						if(*(*(arr + row + 1) + column) == secondletter || *(*(arr + row + 1) + column) + 32 == secondletter ) {
							result = down(arr, n, list, row, column, wordnum);
							if(result == 1) {
								continue;
							}
						}
					}
					//Updiag
					if(row - 1 >= 0) {
						if(column + 1 < n) {
							if(*(*(arr + row - 1) + column + 1) == secondletter || *(*(arr + row - 1) + column + 1) + 32 == secondletter) {
								result = updiag(arr, n, list, row, column, wordnum);
								if(result == 1) {
									continue;
								}
							}
						}
					}
					//Downdiag
					if(row + 1 < n) {
						if(column + 1 < n) {
							if(*(*(arr + row + 1) + column + 1) == secondletter || *(*(arr + row + 1) + column + 1) + 32 == secondletter) {
								result = downdiag(arr, n, list, row, column, wordnum);
								if(result == 1) {
									continue;
								}
							}
						}
					}
				}
			}
			
			if(result == 1) {
				break;
			}
		}
	}
}



// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i = 0; i < 50; i++) {
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i = 0; i < 49; i++) {
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i = 0; i < 50; i++) {
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}
