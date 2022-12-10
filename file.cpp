#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>

using namespace std;

bool isPrime(int x) {
	if(x < 2)
		return false;
	for(int i = 2; i <= x/2; i++) {
		if(x % i == 0)
			return false;
	}
	return true;
}

bool isSquare(int x) {
	if(sqrt(x) == round(sqrt(x)))
		return true;
	return false;
}


int Move(string move) {
	int arr[100];
	int length = move.length();
	int x = 0, y = 0;
	int j = 1;
	while(j <= length) {
		int data = 0;
        int count = 0;
		while(move[j] >= '0' && move[j] <= '9') {
            char input = move[j];
            arr[count] = (int)input - 48;
            j++;
            count++;
        }
        
        for(int i = 0; i < count; i++) {
			data += arr[i]*pow(10,count-i-1);
		}

		switch (move[j-count-1]) {
		case 'U' :
			y += data;
			break;
		case 'D' :
			y -= data;
			break;
		case 'R' :
			x += data;
			break;
		case 'L' :
			x -= data;
			break;
		}
		j++;
	}
	float dis = sqrt(x*x+y*y);
	return round(dis);
}

int main() {
	string move;

	cin >> move;
	int distance = Move(move);

	cout << "Khoang cach xe da di chuyen tu vi tri ban dau toi diem hien tai: "<< distance << '\n';
	if(isPrime(distance) == true)
	{
		cout << "So " << distance << " la so nguyen to";
	}
	else if(isSquare(distance) == true)
	{
		cout << "So " << distance << " la so chinh phuong";
	}
	return 0;
}