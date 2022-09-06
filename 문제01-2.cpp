#include <iostream>
void swap(int *x,int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void swap(double *x, double *y) {
	double tmp = *x;
	*x = *y;
	*y = tmp;
}
void swap(char *x, char *y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
void main() {
	int num1 = 10, num2 = 20;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;
}