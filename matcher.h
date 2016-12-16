// matches a word based on a dictionary in O(length)
// sacrifices memory for runtime; [255] array should be replaced with hashmap that distributes a-zA-Z_- equally based on their frequency

typedef struct matcher_s {
	int id;
	int use;
	struct matcher_s* next[255];
} matcher_t;

matcher_t* make_matcher();
void destroy_matcher(matcher_t* matcher);
void add_word(matcher_t* matcher, char* str, int id);
int remove_word(matcher_t* matcher, char* str);
int match(matcher_t* matcher, char* str);
