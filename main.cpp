#include <iostream>
#include <math.h>
#include <ctime>
#include <fstream>

using namespace std;

int main(){
	ofstream result("result.txt");
	int start = 0;
	unsigned long long end = 0;			//if you use optimisation there is no sense to use "unsigned long long"
	int i = 2;
	int showall = 0;
	int savetofile = 0;
	bool prime = true;
	cout << "Начальное значение: ";
	cin >> start;
	cout << "Конечное значение: ";
	cin >> end;
	cout << "Показывать все числа? (1/0)" << endl;
	cin >> showall;
	cout << "Сохранять простые числа в файл? (1/0)" << endl;
	cin >> savetofile;
	int sec = time(0);
	//unfortunely if you want to optimize program you can't use "unsigned long long" with all they features
	while (start != end+1){
		//float str = start;				//if you don't want to use optimisation comment this line
		//int star = sqrt(str);			//and this
		while (i != start){				//in this line change "star" to "start"
			if (start % i == 0){
				if (showall == 1){
					cout << start << " - составное потому, что делится на " << i;
					cout << "	Осталось: " << end - start << endl;
				}
				prime = false;
				break;
				}
			i++;
		}
		if (prime == true){
			cout << start << " - число простое";
			cout << "	Осталось: " << end - start << endl;
			if (savetofile == 1){
				result << start << endl;
			}
		}
		prime = true;
		start++;
		i = 2;
	}
	cout << "Прошло секунд: " << time(0) - sec << endl;
}
