
typedef struct{
	double real;
	double imaginary;
}Complex;

Complex make_complex(double a,double b);
Complex add_complex(Complex a,Complex b);

int main(void){
	Complex c1,c2,c3;
	
	return 0;
} 

Complex make_complex(double a,double b){
	return (Complex){a,b};
}

Complex add_complex(Complex a,Complex b){
	return (Complex){a.real+b.real,a.imaginary+b.imaginary};
}
