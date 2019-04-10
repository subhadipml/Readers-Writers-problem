# Project No. 1
Write a multi-threaded C program that gives readers priority over writers concerning a shared (global) variable. Essentially, if any readers are waiting, then they have priority over writer threads - writers can only write when there are no readers.

# Test Cases

## Test Case No. 1
#### When the User Enter Number of ‘WRITER’ is Negative 

![1](https://user-images.githubusercontent.com/44317938/55866606-4f01f700-5b9e-11e9-8e3c-3efde7670277.PNG)
In this case 
i.	No WRITER and READER thread will be created
ii.	No read or write operation done
iii.	Program will be terminated

## Test Case No. 2
#### When the User Enter Number of ‘READER’ is Negative

![2](https://user-images.githubusercontent.com/44317938/55866618-56c19b80-5b9e-11e9-97dd-df9917d6b069.PNG)
In this case 
i.	No WRITER and READER thread will be created
ii.	No read or write operation done
iii.	Program will be terminated

## Test Case No. 3
#### When Number of ‘WRITER=0’ is taken as input

![3](https://user-images.githubusercontent.com/44317938/55866627-5c1ee600-5b9e-11e9-949b-ed7c4c7cbe18.PNG)
In This Case:
i.	Only READER thread will be created
ii.	No WRITER thread is created
iii.	No updating of the Shared Variable
iv.	Only READER is reading the shared variable. From the example given above R1, R0 wait for some times. Then R1 read 1 time and R0 read 2 times. Finally Shared variable value will be remain same.

## Test Case No. 4
#### When Number of “READER=0’ is taken as input

![4](https://user-images.githubusercontent.com/44317938/55866637-60e39a00-5b9e-11e9-8a6d-6f51139fcce9.PNG)
In This Case:
i.	Only WRITER thread is created
ii.	No READER thread is created
iii.	No reading of the shared variable
iv.	Only WRITER is updating the shared variable. From the same example given above W1, W0 will make change on the shared variable. W1 writes 2 times and W0 writes 1 time. Finally shared variable value will be changes/updated.

## Test Case No. 5
#### User taken same number of READER and WRITER i.e. READER = WRITER

![5](https://user-images.githubusercontent.com/44317938/55866648-650fb780-5b9e-11e9-9f54-5eb4f954bd9b.PNG)
In This Case:
i.	Both READER and WRITER threads created
ii.	Any WRITER can update the Shared variable any number of times
iii.	Any READER can read that Value any number of times
iv.	In the screen slot, W0 wait for some random times. Then he has the choice to update the variable any number of times with any number. Here W0 update for 2 times. He added 1st times with value 5.

## Test Case No. 6
#### User taken a greater number of WRITER as compared with READER i.e. READER < WRITER

![6](https://user-images.githubusercontent.com/44317938/55866654-69d46b80-5b9e-11e9-9d16-a10abf3321b9.PNG)
In This Case:
i.	Both READER and WRITER threads created
ii.	Any WRITER can update the Shared variable any number of times
iii.	Any READER can read that Value any number of times
iv.	In this screen slot, W0 wait for some time and add some value with shared variable. Then R0 given the choice to read any number of times. Then again, the turn of next writer i.e. W1 came.

## Test Case No. 7
#### User taken a greater number of READER as compared with WRITER i.e. READER > WRITER

![7](https://user-images.githubusercontent.com/44317938/55866662-6d67f280-5b9e-11e9-9b3d-c8208c88c0d9.PNG)
In This Case:
i.	Both READER and WRITER threads created
ii.	Any WRITER can update the Shared variable any number of times
iii.	Any READER can read that Value any number of times
iv.	In this example, W0 wait for some times and update the variable. Then R0, R1 also wait then read the variable any number of times.

## Test Case No. 8
#### Shared Variable value is taken non-INTEGER
 
![8](https://user-images.githubusercontent.com/44317938/55866667-722ca680-5b9e-11e9-8759-83b4dec7a042.PNG)
In This Case:
i.	User unable to take any input
ii.	No READER and WRITER thread were created
iii.	We will not get output as we expected
iv.	But get the Shared variable value as 0

# Program Working with a Proper example

![a](https://user-images.githubusercontent.com/44317938/55866691-7d7fd200-5b9e-11e9-8a08-334c01df5cac.PNG)

ii.	User taken the initial value of share variable(S) as 10
iii.	User taken the no. of reader(R) is 2 as input i.e. R0 & R1
iv.	User taken the no. of writer(W) is 2 as input i.e. W0 & W1
v.	Now READER and WRITER threads were created successfully

![b](https://user-images.githubusercontent.com/44317938/55866707-82dd1c80-5b9e-11e9-88da-895b75c15be2.PNG)

vii.	W0 wait for some random time. Then he chooses that he will update S two time. Fist time he add 7 to S. S = 10 + 7 = 17 then second time he add 8 to S. Now S = 17 + 8 = 25. So, New updated value is 25.

![c](https://user-images.githubusercontent.com/44317938/55866716-8670a380-5b9e-11e9-8461-2d75ce7cd750.PNG)

ix.	Now R0 & R1 wait for some random times. Then R0 wants that he wants to read the shared variable 2 time. Then R1 read for 3 times. At this instant, 1 reader is present. Then W1 wait for some times and he want to add 9 to the shared variable for 1 time. S = 25 + 9 = 34. 
x.	Finally, after joining the thread, we got the shared variable value as 34.
