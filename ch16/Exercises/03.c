
struct complex{
	double real;
	double imaginary;
};

struct complex make_complex(double a,double b);
struct complex add_complex(struct complex a,struct complex b);

int main(void){
	struct complex c1,c2,c3;
	
	return 0;
} 

struct complex make_complex(double a,double b){
	return (struct complex){a,b};
}

struct complex add_complex(struct complex a,struct complex b){
	return (struct complex){a.real+b.real,a.imaginary+b.imaginary};
}

