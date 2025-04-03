#include <random>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std::chrono;
struct Data {
	long long int sum = 0;
	long long int sumMult = 0;
	long long int sumSub = 0;
	long long int sumBit = 0;
	static const int AMOUNT = 1000000;
	long long int* A = new long long[AMOUNT];
	long long int* B = new long long[AMOUNT];
	~Data() {
		delete A;
		delete B;
	}
	
};
void Part1(Data* data) {
	for (int i = 0; i < data->AMOUNT; i++)
	{
		data->sum += data->A[i] + data->B[i];
	}
}
void Part2(Data* data) {
	for (int i = 0; i < data->AMOUNT; i++)
	{
		data->sum += data->A[i] + data->B[i];
		data->sumMult += data->A[i] * data->B[i];
		data->sumSub += data->A[i] - data->B[i];
		data->sumBit += data->A[i] << data->B[i];
	}
}
void Part3(Data* data) {
	for (int i = 0; i < data->AMOUNT; i++)
	{
		data->sum += (data->A[i] + data->B[i]) * (data->A[i] - data->B[i]);
	}
}
void Part4(Data* data) {
	for (int i = 0; i < data->AMOUNT; i++)
	{
		if (data->A[i] > 500000) {
			data->sum += (data->A[i] + data->B[i]) * (data->A[i] - data->B[i]);
		}
		
	}
}


int main() {
	Data data;
	for (int i = 0; i < data.AMOUNT; i++)
	{
		
		data.A[i] = rand();
		data.B[i] = rand();
	}
	steady_clock::time_point t1 = steady_clock::now();
	Part2(&data);
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time = duration_cast<duration<double>>(t2 - t1);
	std::cout << time.count() << " Seconds" << std::endl;
	std::cout << "Sum Addition: " << data.sum << std::endl;
	return 0;
}