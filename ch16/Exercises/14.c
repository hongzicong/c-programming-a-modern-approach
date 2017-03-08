#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE 1
#define PI 3.14159


struct point{
	int x,y;
};

struct shape{
	int shape_kind;
	struct point center;
	union{
		struct{
			double height,width;
		}rectangle;
		struct{
			double radius;
		}circle;
	}u;
}s;

double compute_area(struct shape s);
struct shape move(struct shape s,int x,int y);
struct shape small_big(struct shape s,double c);

int main(void){
	
	struct shape s={RECTANGLE,{1,1},5,5};
	s=move(s,1,1);
	s=small_big(s,0.5);
	
	printf("%g\n",compute_area(s));
	printf("%d %d",s.center.x,s.center.y);
	
	return 0;
}

double compute_area(struct shape s){
	if(s.shape_kind==RECTANGLE){
		return s.u.rectangle.height*s.u.rectangle.width/2.0;
	}else if(s.shape_kind==CIRCLE){
		return s.u.circle.radius*s.u.circle.radius*PI;
	}else{
		printf("shape_kind go wrong!");
		return 0;
	}
}

struct shape move(struct shape s,int x,int y){
	s.center.x+=x;
	s.center.y+=y;
	return s;
}

struct shape small_big(struct shape s,double c){
	if(s.shape_kind==RECTANGLE){
		s.u.rectangle.height*=c;
		s.u.rectangle.width*=c;
	}else if(s.shape_kind==CIRCLE){
		s.u.circle.radius*=c;
	}else{
		printf("shape_kind go wrong!");
		return s;
	}
	return s;
}
