#include<iostream>
#include<stdlib.h>
using namespace std;


// Calculates the amount of bits needed to represent the number
int Dimension(int number) {
	int bits = 0;
	while(number != 0){
		number /= 2;
		bits++;
	}
	return bits + 1;
}


// Saves the remainder of the division (2's complement) in an array,
// this array will contain our binary number
void Positive(int number, int binary[], int dimension){
    for(int i = dimension - 1; i >= 0; i--){
        binary[i] = number % 2;
        number /= 2;
    }
}


// Flips the array created by the "Positive" function, then
// makes the 1's complement and adds 1
void Negative(int number, int binary[], int dimension){
	for(int i = 0; i < dimension; i++){
		if(binary[i] == 0){
			binary[i] = 1;
		}else{
			binary[i] = 0;
		}
	}
	
	int j = dimension - 1;
	while(binary[j] != 0){
		binary[j] = 0;
		j--;
	}
	binary[j] = 1;
}


// Prints an array using the for statement
void Print(int number, int binary[], int dimension){
	cout<<"The binary code of "<<number<<" is: ";
    for(int i = 0; i < dimension; i++){
        cout<<binary[i];
    }
    cout<<endl;
}


int main() {

    int number;

    cout<<"Enter the number that you want to convert to binary: ";
    cin>>number;

    int dimension = Dimension(number);
    int binary[dimension];

    if(number < 0){
        number = abs(number);
        Positive(number, binary, dimension);
        Negative(number, binary, dimension);
	Print(-number, binary, dimension);
    }else{
        Positive(number, binary, dimension);
	Print(number, binary, dimension);
    }


}
