#define POSX 50
#define POSY 70

typedef enum {
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
} Direction;

typedef struct {
	int x;
	int y;
} Segment;

typedef struct {
	Segment *s_seg;
	Direction s_dir;
} Body;
