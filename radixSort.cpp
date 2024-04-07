 #include<iostream>

using namespace std;
void print(int *input, int n)
{//menampilkan data yang kita akan input
	for(int i = 0; i < n; i++)
	{
		cout << input[i] << "\t";
	}
}

void radixsortlogic(int *input, int n)
{
    int i;
    int maxNumber =  input[0]; // Inisialisasi maxNumber dengan elemen pertama
    for (i = 1; i < n; i++)
    {
        if(input[i] > maxNumber)
        {
            maxNumber = input[i];
        }
    }
	int exp = 1;
	int *tmpBuffer = new int[n];
	//perulangan sampai variable exp lebih besar dari nilai inputan
	while(maxNumber / exp > 0)
	{
	    int decimalBucket[10] = {0};
	    for (i = 0; i < n; i++)
	    {
	        decimalBucket[(input[i] / exp) % 10]++;
	    }
	    for (i = 1; i < 10; i++)
	    {
	        decimalBucket[i] += decimalBucket[i - 1];
	    }
	    for (i = n - 1; i >= 0; i--)
	    {
	        tmpBuffer[--decimalBucket[(input[i] / exp) % 10]] = input[i];
	    }
	    for (i = 0; i < n; i++)
	    {
	        input[i] = tmpBuffer[i];
	    }
	    exp *= 10;
	    cout << endl << "PASS : ";
	    print(input, n);
	}

}

int main()
{
	int input[100], INPUT_SIZE;
	cout << "PROGRAM RADIX SHORT" << endl;
	cout << "STRUKTUR DATA DAN ALGORITMA" << endl;
	cout << "1. Kadek Sugiartini\n2. Monica Agustriani Purba\n3. Kadek Rista Dwi Purnami\n\n" << endl;
	cout << "MASUKAN BANYAKNYA INPUTAN : " << endl;
	cin >> INPUT_SIZE;
	cout << endl;
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		cout << "MASUKAN BILANGAN KE- " << i + 1 << " : ";
		cin >> input[i];
	}
	cout<< endl
		<<"DATA YANG DIINPUT : " << endl;
	print(input, INPUT_SIZE);
	radixsortlogic(input, INPUT_SIZE);
	cout << endl 
		<< endl << "Output: ";
	print(input, INPUT_SIZE);
	cout << endl << endl;

	cout<<"Terima kasih";
	return 0;
}
