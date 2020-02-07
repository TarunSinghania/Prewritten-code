int numbers[100];
cout << sizeof(numbers) << endl;     // Size of entire array in bytes (400)
cout << sizeof(numbers[0]) << endl;  // Size of first element of the array in bytes (4)
cout << "Array size is " << sizeof(numbers) / sizeof(numbers[0]) << endl;  // (100)