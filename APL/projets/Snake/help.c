void bodyInit (Body *B, Segment *S) {
   B->s_seg[0] = *S;
}

int main () {
   
   Body snake_body;
   
   snake_body.s_seg = malloc(2 * sizeof(Segment));
   
   snake_body.s_seg[0].x = 3;
   snake_body.s_seg[0].y = 1;
   
   snake_body.s_seg[1].x = 2;
   snake_body.s_seg[1].y = 5;
   
   printf("Body \tSeg1: %d & %d | Seg2: %d & %d \n", snake_body.s_seg[0].x, snake_body.s_seg[0].y, snake_body.s_seg[1].x, snake_body.s_seg[1].y);
   printf("Body direction: %d\n", DOWN);
   
   Segment ex;
   ex.x = 10;
   ex.y = 12;
   
   bodyInit(&snake_body, &ex);
   
	printf("\nInit \tSeg1: %d & %d \n", snake_body.s_seg[0].x, snake_body.s_seg[0].y);
   
   return 0;
}
